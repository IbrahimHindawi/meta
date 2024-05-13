/* hkNode_i64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>



struct hkNode_i64 {
    struct hkNode_i64 *next;
    i64 data;
};

struct hkNode_i64 *hkNode_i64_init(i64 data) {
    struct hkNode_i64 *node = malloc(sizeof(struct hkNode_i64));
    if (node) {
        node->next = null;
        node->data = data;
    }
    return node;
}

void hkNode_i64_deinit(struct hkNode_i64 *node) {
    free(node);
}

