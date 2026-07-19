#ifndef HTTP_H
#define HTTP_H

#include <curl/curl.h>

typedef struct {

    long status;

    char *body;

    size_t size;

} http_response_t;

int http_init(void);

int http_get(
    const char *url,
    http_response_t *resp
);

void http_free(
    http_response_t *resp
);

#endif
