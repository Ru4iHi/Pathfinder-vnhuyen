#include "../inc/header.h"
char *mx_str(char *file_n, int n, bool *final) {
    char siu;
    int f = open(file_n, O_RDONLY);
    int len = 0;
    for (int i = 1; i < n; i++) {
        read(f, &siu, 1);
        while (siu != '\n') {
            read(f, &siu, 1);
        }
    }
    int info = read(f, &siu, 1);
    while (info > 0) {
        if (siu == '\n') {
            break;
        }
        info = read(f, &siu, 1);
        len++;
    }
    if (read(f, &siu, 1) <= 0) {
        *final = true;
    }
    close(f);
    char *result = mx_strnew(len);
    f = open(file_n, O_RDONLY);
    len = 0;
    for (int i = 1; i < n; i++) {
        read(f, &siu, 1);
        while (siu != '\n') {
            read(f, &siu, 1);
        }
    }
    read(f, &siu, 1);
    while (siu != '\n') {
        result[len] = siu;
        len++;
        int info = read(f, &siu, 1);
        if (info <= 0) {
            break;
        }
    }
    close(f);
    return result;
}

