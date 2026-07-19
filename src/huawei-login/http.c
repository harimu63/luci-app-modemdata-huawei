#include "http.h"

#include <stdlib.h>
#include <string.h>

static size_t write_callback(
    void *ptr,
    size_t size,
    size_t nmemb,
    void *userdata
)
{
    http_response_t *resp=userdata;

    size_t total=size*nmemb;

    char *tmp=realloc(resp->body,resp->size+total+1);

    if(!tmp)
        return 0;

    resp->body=tmp;

    memcpy(resp->body+resp->size,ptr,total);

    resp->size+=total;

    resp->body[resp->size]=0;

    return total;
}

int http_init(void)
{
    return curl_global_init(CURL_GLOBAL_DEFAULT);
}

int http_get(
    const char *url,
    http_response_t *resp
)
{
    memset(resp,0,sizeof(*resp));

    CURL *curl=curl_easy_init();

    if(!curl)
        return -1;

    curl_easy_setopt(curl,CURLOPT_URL,url);

    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_callback);

    curl_easy_setopt(curl,CURLOPT_WRITEDATA,resp);

    CURLcode ret=curl_easy_perform(curl);

    if(ret!=CURLE_OK)
    {
        curl_easy_cleanup(curl);

        return -1;
    }

    curl_easy_getinfo(
        curl,
        CURLINFO_RESPONSE_CODE,
        &resp->status
    );

    curl_easy_cleanup(curl);

    return 0;
}

void http_free(
    http_response_t *resp
)
{
    free(resp->body);

    resp->body=NULL;

    resp->size=0;
}
