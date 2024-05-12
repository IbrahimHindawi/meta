/* hkNode_i16 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>

struct hkNode_i16 {
    struct hkNode *next;
    i16 data;
};
void hkNode_i16_init(struct hkNode_i16 *node, i16 data) {
    if (null != (malloc(sizeof(struct hkNode_i16)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_i16_deinit(struct hkNode_i16 *node) {
    free(node);
}

