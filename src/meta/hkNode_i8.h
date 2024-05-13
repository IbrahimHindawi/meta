/* hkNode_i8 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_i8 {
    struct hkNode_i8 *next;
    i8 data;
};

struct hkNode_i8 *hkNode_i8_init(i8 data) {
    struct hkNode_i8 *node = malloc(sizeof(struct hkNode_i8));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_i8_deinit(struct hkNode_i8 *node) {
    free(node);
}

