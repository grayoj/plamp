#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "request_handler.h"

void handle_request(int client_fd)
{
    // Receive request
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    read(client_fd, buffer, sizeof(buffer));

    // Parse request to extract file path
    char method[16], path[256];
    sscanf(buffer, "%s %s", method, path);

    // Handle PHP file
    if (strstr(path, ".php") != NULL)
    {
        handle_php_request(client_fd, path);
        return;
    }

    // Handle HTML file
    handle_html_request(client_fd, path);
}
