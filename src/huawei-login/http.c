#include "http.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int http_init(void)
{
    return HTTP_OK;
}

int http_get(
    const char *url,
    http_response_t *resp
)
{
    (void)url;

    memset(resp,0,sizeof(http_response_t));

    resp->status=200;

    resp->body=strdup("<response/>");

    return HTTP_OK;
}

int http_post(
    const char *url,
    const char *content,
    const char *token,
    const char *cookie,
    http_response_t *resp
)
{
    (void)url;
    (void)content;
    (void)token;
    (void)cookie;

    memset(resp,0,sizeof(http_response_t));

    resp->status=200;

    resp->body=strdup("<response/>");

    return HTTP_OK;
}

void http_free(http_response_t *resp)
{
    if(resp->body)
        free(resp->body);

    if(resp->cookie)
        free(resp->cookie);

    if(resp->token)
        free(resp->token);

    memset(resp,0,sizeof(http_response_t));
}
