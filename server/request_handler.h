#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

void handle_request(int client_fd);
void handle_php_request(int client_fd, const char *path);
void handle_html_request(int client_fd, const char *path);

#endif
