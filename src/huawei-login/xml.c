#include "xml.h"

#include <stdio.h>
#include <string.h>

int xml_init(void)
{
    return 0;
}

int xml_get(
    const char *xml,
    const char *tag,
    char *buffer,
    size_t size
)
{
    char open[64];
    char close[64];

    snprintf(open,sizeof(open),"<%s>",tag);
    snprintf(close,sizeof(close),"</%s>",tag);

    const char *p1=strstr(xml,open);

    if(!p1)
        return -1;

    p1+=strlen(open);

    const char *p2=strstr(p1,close);

    if(!p2)
        return -1;

    size_t len=p2-p1;

    if(len>=size)
        len=size-1;

    memcpy(buffer,p1,len);

    buffer[len]=0;

    return 0;
}
