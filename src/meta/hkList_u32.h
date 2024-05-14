#pragma once
/* hkList_u32 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u32.h"

struct hkList_u32 {
    struct hkNode_u32 *head;
    struct hkNode_u32 *tail;
};

struct hkList_u32 *hkList_u32_init() {
    struct hkList_u32 *list = malloc(sizeof(struct hkList_u32));
    list->head = null;
    list->tail = null;
    return list;
}

void hkList_u32_append(struct hkList_u32 *list, u32 data) {
    if (!list->head) {
        list->head = hkNode_u32_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hkNode_u32_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_u32 *temp = hkNode_u32_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hkList_u32_deinit(struct hkList_u32 **list) {
    free(*list);
    *list = null;
}

