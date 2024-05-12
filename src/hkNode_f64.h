/* hkNode_f64 */
#include "core.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {} f64;
struct hkNode_f64 {
    struct hkNode *next;
    f64 data;
};
void hkNode_f64_init(struct hkNode_f64 *node, f64 data) {
    if (null != (malloc(sizeof(struct hkNode_f64)))) {
        node->next = null;
        node->data = data;
    }
}
void hkNode_f64_deinit(struct hkNode_f64 *node) {
    free(node);
}

