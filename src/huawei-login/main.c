#include <stdio.h>

#include "http.h"
#include "xml.h"
#include "scram.h"
#include "api.h"
#include "session.h"
#include "utils.h"

int main(void)
{
    http_init();
    xml_init();
    scram_init();
    api_init();
    session_init();
    utils_init();

    printf("=====================================\n");
    printf(" Huawei Modem Backend\n");
    printf(" Version : 0.1.0\n");
    printf(" Target  : OpenWrt 24.10+\n");
    printf(" Status  : Development\n");
    printf("=====================================\n");

    /* ---------- HTTP TEST ---------- */

    http_response_t r;

    if (http_get("http://192.168.11.50", &r) == HTTP_OK)
    {
        printf("\nHTTP GET SUCCESS\n");
        printf("Status : %d\n", r.status);
        printf("Body   : %s\n", r.body);

        http_free(&r);
    }
    else
    {
        printf("\nHTTP GET FAILED\n");
    }

    /* ------------------------------- */

    return 0;
}
