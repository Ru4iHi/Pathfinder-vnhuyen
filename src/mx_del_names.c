#include "../inc/header.h"
void mx_del_names(char **arr) {
    for (int i = 0; arr[i] != NULL; i++)
		mx_strdel(&arr[i]);
}

