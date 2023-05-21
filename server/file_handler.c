#include "file_handler.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define DOCUMENT_ROOT "/php/store.php"

void handle_php_request(int client_fd, const char *path)
{
    // Build file path
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s", DOCUMENT_ROOT, path);

    // Execute PHP script via FastCGI
    char command[512];
    snprintf(command, sizeof(command), "SCRIPT_FILENAME=%s cgi-fcgi -bind -connect 127.0.0.1:9000", file_path);

    FILE *fp = popen(command, "r");
    if (fp == NULL)
    {
        perror("PHP execution failed");
        return;
    }

    // Read and send PHP output
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0)
    {
        write(client_fd, buffer, bytes_read);
    }

    pclose(fp);
}

void handle_html_request(int client_fd, const char *path)
{
    // Build file path
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s", DOCUMENT_ROOT, path);

    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        perror("File not found");
        return;
    }

    // Read and send HTML content
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        write(client_fd, buffer, bytes_read);
    }

    fclose(file);
}
