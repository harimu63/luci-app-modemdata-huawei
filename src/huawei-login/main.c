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

    return 0;
}
