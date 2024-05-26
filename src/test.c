#include "meta/hkNode_core.h"
#include "meta/hkList_core.h"
#include "meta/hkArray_core.h"

i32 proc(i32 x, i32 y) {
    i32 result = x + y;
    return result;
}

int main() {
    hkNode_i8 *node0 = hknode_i8_init(0xAD);
    hkNode_i8 *node1 = hknode_i8_init(0xFF);
    node0->next = node1;
    printf("node0.data = %x, node0.next = %p\n", node0->data, node0->next);
    printf("node1.data = %x, node1.next = %p\n", node1->data, node1->next);
    hknode_i8_deinit(&node1);
    hknode_i8_deinit(&node0);

    hkList_i32 *list = hklist_i32_init();
    hklist_i32_append(list, 0xDEADBEEF);
    hklist_i32_append(list, 0xCAFEBABE);
    hklist_i32_append(list, 0xFFFFFFFF);
    hkNode_i32 *current = list->head;
    while (current) {
        printf("current.data = %x, current.addr = %p, current.next = %p\n", 
                current->data, current, current->next);
        current = current->next;
    }

    hkArray_i32 array = hkarray_i32_create(8);
    for (i32 i = 0; i < array.length; ++i) {
        array.data[i] = array.data[i] + 19 * i;
    }
    for (i32 i = 0; i < array.length; ++i) {
        printf("value = %d, address = %p\n", 
            array.data[i], &array.data[i]);
    }
    hkarray_i32_destroy(&array);
    hkarray_i32_create(8);

    return 0;
}
