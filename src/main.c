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

#define META 0

#if META
#include "meta.h"
#else
#include "meta/hkNode_i8.h"
#include "meta/hkNode_i16.h"
#include "meta/hkNode_i32.h"
#include "meta/hkNode_i64.h"
#include "meta/hkNode_u8.h"
#include "meta/hkNode_u16.h"
#include "meta/hkNode_u32.h"
#include "meta/hkNode_u64.h"
#include "meta/hkNode_f32.h"
#include "meta/hkNode_f64.h"
#include "meta/hkList_i8.h"
#include "meta/hkList_i16.h"
#include "meta/hkList_i32.h"
#include "meta/hkList_i64.h"
#include "meta/hkList_u8.h"
#include "meta/hkList_u16.h"
#include "meta/hkList_u32.h"
#include "meta/hkList_u64.h"
#include "meta/hkList_f32.h"
#include "meta/hkList_f64.h"
#endif

int main() {
#if META
    metamain("hkNode", "i8");
    metamain("hkNode", "i16");
    metamain("hkNode", "i32");
    metamain("hkNode", "i64");
    metamain("hkNode", "u8");
    metamain("hkNode", "u16");
    metamain("hkNode", "u32");
    metamain("hkNode", "u64");
    metamain("hkNode", "f32");
    metamain("hkNode", "f64");
    metamain("hkList", "i8");
    metamain("hkList", "i16");
    metamain("hkList", "i32");
    metamain("hkList", "i64");
    metamain("hkList", "u8");
    metamain("hkList", "u16");
    metamain("hkList", "u32");
    metamain("hkList", "u64");
    metamain("hkList", "f32");
    metamain("hkList", "f64");
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

    // free list

#endif
    return 0;
}
