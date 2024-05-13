/* hkNode_TYPE */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {} TYPE;
struct hkNode_TYPE {
    struct hkNode_TYPE *next;
    TYPE data;
};
void hkNode_TYPE_init(struct hkNode_TYPE *node, TYPE data) {
    if (null != (malloc(sizeof(struct hkNode_TYPE)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_TYPE_deinit(struct hkNode_TYPE *node) {
    free(node);
}
