#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

void handle_php_request(int client_fd, const char* path);
void handle_html_request(int client_fd, const char* path);

#endif

