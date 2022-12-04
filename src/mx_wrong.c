#include "../inc/header.h"
bool mx_wrong(char *str) {
    bool delit = false; // '-'
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!(((str[i] >= 65) && (str[i] <= 90)) 
            || ((str[i] >= 97) && (str[i] <= 122)))) {
            if ((!delit) && str[i] == '-') {
                delit = true;
            }
            else if (str[i] == ',') {
                return false;
            }
            else {
                return true;
            }
        }
    }
    return false;
}
