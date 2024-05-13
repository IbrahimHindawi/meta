/*
 *
 */
#include <stdio.h>
#include <string.h>
#include "../bstring/bstring/bstrlib.h"
#if defined (_MSC_VER)
/* These warnings from MSVC++ are totally pointless. */
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#endif
#include "core.h"

#include "meta/hkNode_i8.h"
#include "meta/hkNode_i16.h"
#include "meta/hkNode_i32.h"

// #include "meta.h"

int main() {
#if 0
    metamain("hkNode", "i8");
    metamain("hkNode", "i16");
    metamain("hkNode", "i32");
    metamain("hkNode", "i64");
    metamain("hkNode", "f32");
    metamain("hkNode", "f64");
#endif

#if 1
    struct hkNode_i8 *node0 = hkNode_i8_init(0xAD);
    struct hkNode_i8 *node1 = hkNode_i8_init(0xFF);

    node0->next = node1;
    printf("node0.data = %x, node0.next = %p\n", node0->data, node0->next);
    printf("node1.data = %x, node1.next = %p\n", node1->data, node1->next);

    hkNode_i8_deinit(node1);
    hkNode_i8_deinit(node0);
#endif

    return 0;
}
