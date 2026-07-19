#ifndef XML_H
#define XML_H

#include <stddef.h>

int xml_init(void);

/*
 * Mengambil isi tag XML.
 * Contoh:
 * xml_get(xml, "TokInfo", buffer, sizeof(buffer));
 */
int xml_get(
    const char *xml,
    const char *tag,
    char *buffer,
    size_t size
);

#endif
