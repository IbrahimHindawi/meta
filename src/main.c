/*
 * Metaprogramming Data Structures & Algorithms in C by
 * creating an external program that parses C source
 * and replaces the `TYPE` with a desired type
 */
#include "core.h"
#include <stdio.h>
#include <string.h>

#define META 1

#if META
#   include "meta.h"
#else
#   include "meta/hkNode_core.h"
#   include "meta/hkList_core.h"
#endif

int main() {
#if META
    // hkNode custom
    // metagen("hkNode", "custom");
    // #include "custom.h"
    // #include "hkNode_custom.h"
    // hkNode core
    metacore("hkNode");
    // hkList core
    metacore("hkList");
#else
    struct hkNode_i8 *node0 = hkNode_i8_init(0xAD);
    struct hkNode_i8 *node1 = hkNode_i8_init(0xFF);

    node0->next = node1;
    printf("node0.data = %x, node0.next = %p\n", node0->data, node0->next);
    printf("node1.data = %x, node1.next = %p\n", node1->data, node1->next);

    hkNode_i8_deinit(&node1);
    hkNode_i8_deinit(&node0);

    struct hkList_i32 *list = hkList_i32_init();
    hkList_i32_append(list, 0xDEADBEEF);
    hkList_i32_append(list, 0xCAFEBABE);
    hkList_i32_append(list, 0xFFFFFFFF);
    struct hkNode_i32 *current = list->head;
    while (current) {
        printf("current.data = %x, current.addr = %p, current.next = %p\n", 
                current->data, current, current->next);
        current = current->next;
    }
#endif
    return 0;
}
