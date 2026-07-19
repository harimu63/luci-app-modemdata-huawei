#ifndef HTTP_H
#define HTTP_H

#include <stddef.h>

#define HTTP_OK 0
#define HTTP_ERROR -1

typedef struct {
    int status;
    char *body;
    char *cookie;
    char *token;
} http_response_t;

int http_init(void);

int http_get(
    const char *url,
    http_response_t *resp
);

int http_post(
    const char *url,
    const char *content,
    const char *token,
    const char *cookie,
    http_response_t *resp
);

void http_free(http_response_t *resp);

#endif
