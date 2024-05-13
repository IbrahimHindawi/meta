/* hkNode_i16 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_i16 {
    struct hkNode_i16 *next;
    i16 data;
};

struct hkNode_i16 *hkNode_i16_init(i16 data) {
    struct hkNode_i16 *node = malloc(sizeof(struct hkNode_i16));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_i16_deinit(struct hkNode_i16 *node) {
    free(node);
}

