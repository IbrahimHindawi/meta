/* hkNode_i64 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {} i64;
struct hkNode_i64 {
    struct hkNode *next;
    i64 data;
};
void hkNode_i64_init(struct hkNode_i64 *node, i64 data) {
    if (null != (malloc(sizeof(struct hkNode_i64)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_i64_deinit(struct hkNode_i64 *node) {
    free(node);
}

