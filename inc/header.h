#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"

typedef struct s_node {
    char *name;
    int len;
}              t_node;

typedef struct s_info {
   int p_from;
    int p_to;
    int sum;
   
    int cf_nodes;
}              t_info;

int mx_input(int argc, char *argv[]);
void mx_map(char *file_n, t_node *nodes, int *map, int cf_nodes);
void mx_nodes(int s_point, t_node *nodes, int *map, int cf_nodes);
char *mx_path(char *PR, char *D, t_node *nodes, int *map, t_info info);
int get_index_current_path(char *str);



void mx_del_nodes(t_node *nodes, int cf_nodes);
int mx_atoimod(const char *str, int len);

void mx_printerr_int(int n);

void mx_line_err(int line);
char *mx_str(char *file_n, int n, bool *final);
void mx_del_names(char **arr);
void mx_printerr(const char *s);
bool mx_wrong(char *str);
#endif

