/* hkNode_f32 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {} f32;
struct hkNode_f32 {
    struct hkNode *next;
    f32 data;
};
void hkNode_f32_init(struct hkNode_f32 *node, f32 data) {
    if (null != (malloc(sizeof(struct hkNode_f32)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_f32_deinit(struct hkNode_f32 *node) {
    free(node);
}

