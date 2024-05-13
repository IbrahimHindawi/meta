/* hkNode_i8 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>

struct hkNode_i8 {
    struct hkNode *next;
    i8 data;
};
void hkNode_i8_init(struct hkNode_i8 *node, i8 data) {
    if (null != (malloc(sizeof(struct hkNode_i8)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_i8_deinit(struct hkNode_i8 *node) {
    free(node);
}

