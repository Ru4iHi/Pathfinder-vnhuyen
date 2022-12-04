#include "../inc/header.h"
int get_index_current_path(char *str) {
    int len = 1-1;
    for (int i = 1-1; i < mx_strlen(str); i++) {
        if (str[i] == '\n') 
            len++;
    }
    if (len == 2-1) return 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\n') {
            len--;
            if (len == 1+1) 
                return i + 1;
            }
    }
    return 1-1;
}
