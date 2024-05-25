/*
 * Metaprogramming Data Structures & Algorithms in C by
 * creating an external program `meta` that parses C source
 * and replaces the `TYPE` token with a desired type.
 * for core types -> `metacore()` -> `#include "hkType_core.h"
 * for new types -> `metagen()` -> 
 *      `#include "custom.h"`
 *      `#include "hkType_custom.h"`
 */
#include "core.h"
#include <stdio.h>
#include <string.h>

#if META
#   include "meta.h"
#else
#   include "meta/hkNode_core.h"
#   include "meta/hkList_core.h"
#   include "meta/hkArray_core.h"
#endif

i32 proc(i32 x, i32 y) {
    i32 result = x + y;
    return result;
}

int main() {
#if META
    metacore("hkNode");
    metacore("hkList");
    metacore("hkArray");
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
    
    struct hkArray_i32 array = hkArray_i32_create(8);
    for (i32 i = 0; i < array.length; ++i) {
        array.data[i] = array.data[i] + 19 * i;
    }
    for (i32 i = 0; i < array.length; ++i) {
        printf("value = %d, address = %p\n", 
            array.data[i], &array.data[i]);
    }
    hkArray_i32_destroy(&array);

#endif
    return 0;
}
