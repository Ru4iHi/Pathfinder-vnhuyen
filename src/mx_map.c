#include "../inc/header.h"
int mx_input(int argc, char *argv[]);
void mx_map(char *file_n, t_node *nodes, int *map, int cf_nodes) {
    int sum_bridges = 0;
    int line = 2;
    bool final = false;
    char *names[cf_nodes + 1];
    for (int i = 0; i <= cf_nodes; i++) {
        names[i] = NULL;
    }
    for (int i = 0; i < cf_nodes * cf_nodes; i++) {
        map[i] = -1;
    }
    // filling names:
    int empty = 0;
    while (!final) {
        char *str = mx_str(file_n, line, &final); // whithout \n (whith \0) dinamic!!!
        int name1_len = mx_get_char_index(str, '-');
        int name2_len = mx_get_char_index(str, ',');
        name2_len -= name1_len + 1;
        if (name1_len < 1 || name2_len < 1 || mx_wrong(str)
            || mx_strncmp(&(str[name1_len + 1]), str, name1_len) == 0) {
            mx_line_err(line);
            mx_strdel(&str);
            mx_del_names((char**)names);
            exit(0);
        }
        // name1 check:
        bool nothing = true;
        for (int i = 0; i < cf_nodes; i++) {
            if (names[i] != NULL) {
                if (mx_strncmp(str, names[i], name1_len) == 0) {
                    nothing = false;
                    break;
                }
            }
        }
        if (nothing) {
            if (empty < cf_nodes) {
                names[empty] = mx_strndup(str, name1_len);
                empty ++;
            }
            else {
                mx_printerr("error: invalid number of islands\n");
                mx_strdel(&str);
                mx_del_names((char**)names);
                exit(0);
            }
        }
        // name2 check:
        nothing = true;
        for (int i = 0; i < cf_nodes; i++) {
            if (names[i] != NULL) {
                if (mx_strncmp(&(str[name1_len + 1]), names[i], name2_len) == 0) {
                    nothing = false;
                    break;
                }
            }
        }
        if (nothing) {
            if (empty < cf_nodes) {
                names[empty] = mx_strndup(&(str[name1_len + 1]), name2_len);
                empty ++;
            }
            else {
                mx_printerr("error: invalid number of islands\n");
                mx_strdel(&str);
                mx_del_names((char**)names);
                exit(0);
            }
        }
        mx_strdel(&str);
        line++;
    }
    //mx_bubble_sort(names, count_of_nodes); if you need not FIFO
    for (int i = 0; i < cf_nodes; i++) {
        nodes[i].name = names[i];
    }
    // filing the map
    line = 2;
    final = false;
    while (!final) {
        int bridge;
        int node1;
        int node2;
        char *str = mx_str(file_n, line, &final); // whithout \n (whith \0) dinamic!!!
        int name1_len = mx_get_char_index(str, '-');
        int name2_len = mx_get_char_index(str, ',');
        int num_index = mx_get_char_index(str, ',') + 1;
        int num_len = mx_strlen(str) - num_index;
        name2_len -= name1_len + 1;
        if (num_len < 1) {
            mx_line_err(line);
            mx_strdel(&str);
            mx_del_nodes(nodes, cf_nodes);
            exit(0);
        }
        bridge = mx_atoimod(&(str[num_index]), num_len);
        if (bridge < 0) {
            mx_line_err(line);
            mx_strdel(&str);
            mx_del_nodes(nodes, cf_nodes);
            exit(0);
        }

        if (sum_bridges >= 0) {
            sum_bridges += bridge;
        }

        for (node1 = 0; node1 < cf_nodes; node1++) {
            if (mx_strncmp(str, nodes[node1].name, name1_len) == 0) {
                break;
            }
        }
        for (node2 = 0; node2 < cf_nodes; node2++) {
            if (mx_strncmp(&(str[name1_len + 1]), nodes[node2].name, name2_len) == 0) {
                break;
            }
        }
        if (map[node1 * cf_nodes + node2] == -1) {
            map[node1 * cf_nodes + node2] = bridge;
            map[node2 * cf_nodes + node1] = bridge;
        }
        else {
            mx_del_nodes(nodes, cf_nodes);
            mx_printerr("error: duplicate bridges\n");
            mx_strdel(&str);
            exit(0);
        }
        mx_strdel(&str);
        line++;
    }
    if (sum_bridges < 0) {
        mx_del_nodes(nodes, cf_nodes);
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
}

