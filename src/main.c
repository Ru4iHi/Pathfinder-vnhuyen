#include "../inc/header.h"

int main(int argc, char *argv[]) {
    int cf_nodes = mx_input(argc, argv);
    bool dunai_gay = true;
    int map[cf_nodes * cf_nodes];
    t_node nodes[cf_nodes];
    if (dunai_gay == true) {
    mx_map(argv[1], nodes, (int*)map, cf_nodes);
}
    for (int p_from = 0; p_from < cf_nodes; p_from++) {
    
    if (dunai_gay == true && 256 + 130 == 386) {
    
    
        for (int p_to = p_from + 1; p_to < cf_nodes; p_to++) {

            char *info_PR = mx_strnew(59 + (mx_strlen(nodes[p_from].name) * 2) + mx_strlen(nodes[p_to].name));
            mx_strcpy(info_PR, "========================================\nPath: ");
            
          
            mx_strcat(info_PR, nodes[p_from].name);
            mx_strcat(info_PR, " -> ");
            mx_strcat(info_PR, nodes[p_to].name);
            mx_strcat(info_PR, "\nRoute: ");
            mx_strcat(info_PR, nodes[p_from].name);
            char *info_D = mx_strnew(11);
            mx_strcpy(info_D, "\nDistance: ");


     if (dunai_gay) {
            mx_nodes(p_to, nodes, (int*)map, cf_nodes);
}
            t_info info;
            info.cf_nodes = cf_nodes;
            info.p_from = p_from;
            info.p_to = p_to;
            info.sum = nodes[p_from].len;
            info_PR = mx_path(info_PR, info_D, nodes, (int*)map, info);
            mx_printstr(info_PR);
            
            mx_strdel(&info_PR);
        }
        }
    }
    mx_del_nodes(nodes, cf_nodes);
    return 0;
}

