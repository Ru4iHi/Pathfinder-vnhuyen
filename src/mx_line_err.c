#include "../inc/header.h"
void mx_line_err(int line) {
    mx_printerr("error: line ");
    mx_printerr_int(line);
    mx_printerr(" is not valid\n");
}
