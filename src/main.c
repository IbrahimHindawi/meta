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
    // metamain("hkNode", "i8");
    // metamain("hkNode", "i16");
    // metamain("hkNode", "i32");
    // metamain("hkNode", "i64");
    // metamain("hkNode", "f32");
    // metamain("hkNode", "f64");
    struct hkNode_i8 *node = null;
    hkNode_i8_init(node, 8);
    hkNode_i8_deinit(node);
    return 0;
}
