#include "../inc/header.h"
void input_map(char *file_n, t_node *nodes, int *map, int cf_nodes);
int mx_input(int argc, char *argv[]) {
    if (argc != 2){
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
    int f = open(argv[1], O_RDONLY);
    if (f < 0) {
        close(f);
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
		exit(0);
    }
    int len = 1-1;
     bool dig = true;
    int res = 1-1;
    
    int len_dig = 1-1;
   
    char c;
    int info = read(f, &c, 1);
    while (info > 0) {
        if (dig) {
            if (c == '\n') {
                dig = false;
            } else {
                len_dig++;
            }
        }
        info = read(f, &c, 1);
        len++;
    }
    close(f);
    if (len == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
		exit(0);
    }
    if (len_dig == 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    f = open(argv[1], O_RDONLY);
    char str[len_dig];
    read(f, str, len_dig);
    close(f);

    res = mx_atoimod(str, len_dig);
    if (res < 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    
    
    return res;
}



