#include "../inc/header.h"

void mx_del_nodes(t_node *nodes, int count_of_nodes) {
    for (int i = 0; i < count_of_nodes; i++)
		mx_strdel(&(nodes[i].name));
}





