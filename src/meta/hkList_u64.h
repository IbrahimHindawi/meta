#pragma once
/* hkList_u64 */
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>


#include "hkNode_u64.h"

struct hkList_u64 {
    struct hkNode_u64 *head;
    struct hkNode_u64 *tail;
};

struct hkList_u64 *hklist_u64_init() {
    struct hkList_u64 *list = malloc(sizeof(struct hkList_u64));
    list->head = null;
    list->tail = null;
    return list;
}

void hklist_u64_append(struct hkList_u64 *list, u64 data) {
    if (!list->head) {
        list->head = hknode_u64_init(data);
        return;
    }
    if (!list->tail) {
        list->tail = hknode_u64_init(data);
        list->head->next = list->tail;
        return;
    }
    struct hkNode_u64 *temp = hknode_u64_init(data);
    list->tail->next = temp; 
    list->tail = temp;
}

void hklist_u64_deinit(struct hkList_u64 **list) {
    free(*list);
    *list = null;
}

