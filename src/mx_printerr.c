#include "../inc/libmx.h"
#include "../inc/header.h"

void mx_printerr(const char *s) {
    int l = 0;
    while(s[l] != '\0') {
        l++;
    }
    write(2, s, l);
}

