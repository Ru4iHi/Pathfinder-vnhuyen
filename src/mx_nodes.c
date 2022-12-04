#include "../inc/header.h"

void mx_nodes(int s_point, t_node *nodes, int *map, int cf_nodes) {
    bool block[cf_nodes];
    for (int i = 0; i < cf_nodes; i++) {
        nodes[i].len = 2147483647;
        block[i] = false;
    }
    nodes[s_point].len = 0;
    int current = s_point;
    for (int a = 0; a < cf_nodes; a++) {
        block[current] = true;
        for (int i = 0; i < cf_nodes; i++) {
            if (map[current * cf_nodes + i] != -1) {
                if (nodes[i].len > map[current * cf_nodes + i] + nodes[current].len && !block[i]) {
                    nodes[i].len = map[current * cf_nodes + i] + nodes[current].len;
                }
            }
        }
        int min = 2147483647;
        for (int i = 0; i < cf_nodes; i++) {
            if (nodes[i].len < min && !block[i]) {
                current = i;
                min = nodes[i].len;
            }
        }
    }
}

