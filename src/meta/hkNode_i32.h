/* hkNode_i32 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>

struct hkNode_i32 {
    struct hkNode *next;
    i32 data;
};
void hkNode_i32_init(struct hkNode_i32 *node, i32 data) {
    if (null != (malloc(sizeof(struct hkNode_i32)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_i32_deinit(struct hkNode_i32 *node) {
    free(node);
}

