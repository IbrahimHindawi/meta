#include <stdio.h>
#include <string.h>
#include "../bstring/bstring/bstrlib.h"
#if defined (_MSC_VER)
/* These warnings from MSVC++ are totally pointless. */
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#endif
#include "core.h"

/* meta.exe -gen src/meta/hkNode.h -o src/meta/gen
 * meta_hkNode_generate(i32); // hkNode<i32>
 * meta_hkNode_generate(f32); // hkNode<f32>
 * -----------------------------------------
 * types.gen.h
 * #include "hkNode/hkNode_i32.h"
 * #include "hkNode/hkNode_f32.h"
 */
// #include "types.gen.h"
// int main() {
//     struct hkNode_i32 *node = null;
//     hkNode_i32_init(node, 666);
//     hkNode_i32_deinit(node);
//     //
//     struct hkNode_f32 *node = null;
//     hkNode_f32_init(node, 3.141592);
//     hkNode_f32_deinit(node);
//     return 0;
// }

/* 
#define N 1024
char *buffer[N];
int main() {
    FILE *input = null;
    for (int i = 0; i < N; ++i) {
        if (null != (buffer[i] = malloc(256))) {
        } else {
            printf("alloc failure!\n");
        }
    }
    int linecount = 0;
    if (null != (input = fopen("\\devel\\meta\\src\\hkNode_TYPE.h", "r"))) {
        while(fgets(buffer[linecount], 100, input)) {
            // printf("%s", buffer[linecount]);
            ++linecount;
        }
    } else {
        printf("file not found\n");
        return 1;
    }
    fclose(input);
    // printf("linecount = %d\n", linecount);
    for (int i = 0; i < linecount; ++i) {
        // printf("%s\n", buffer[i]);
        // int len = strlen(buffer[i]);
        // printf("%d:\t", len);
        // for (int j = 0; j < len; ++j) {
        //     // printf("%c", *(buffer[i] + j));
        //     char current = *(buffer[i] + j);
        // }
        char *result = null;
        // strstr matches the first match only!
        if (null != (result = strstr(buffer[i], "TYPE"))) {
            printf("found a match on line %d!\n", i);
            // need to properly replace variable length strings
            strncpy(result, "FAKE", 4);
        }
    }
    for (int i = 0; i < linecount; ++i) {
        printf("%s", buffer[i]);
    }
    FILE *output = null;
    if (null != (output = fopen("\\devel\\meta\\src\\hkNode_RSLT.h", "w"))) {
        for (int i = 0; i < linecount; ++i) {
            fputs(buffer[i], output);
        }
    }
    fclose(output);
    return 0;
}
*/
int metamain(const char *metaname, const char*genname) {
    FILE *input = null;
    struct bstrList *lines;
    struct tagbstring postfix = bsStatic("\n");

    const i32 buffersize = 256;
    LPTSTR pathstr = malloc(buffersize);
    i32 pathstrlen = GetCurrentDirectoryA(buffersize, pathstr);
    // pathstr[pathstrlen] = '\\';
    // pathstr[pathstrlen + 1] = '\0';
    // pathstrlen += 1;
    // printf("path str = %s\n", pathstr);
    // printf("len = %d.\n", pathstrlen);
    // bstring cwd = bfromcstr(pathstr);

    bstring typecorepath = bfromcstr(pathstr);
    bcatcstr(typecorepath, "\\src\\");
    bstring typecore = bfromcstr(metaname);
    bstring typestr = bfromcstr("TYPE");
    bconcat(typecorepath, typecore);
    bcatcstr(typecorepath, "_");
    bconcat(typecorepath, typestr);
    bcatcstr(typecorepath, ".h");
    printf("typecorepath: %s\n", bdata(typecorepath));

    bstring typemetapath = bfromcstr(pathstr);
    bcatcstr(typemetapath, "\\src\\");
    bstring typemetastr = bfromcstr(genname);
    bconcat(typemetapath, typecore);
    bcatcstr(typemetapath, "_");
    bconcat(typemetapath, typemetastr);
    bcatcstr(typemetapath, ".h");
    printf("typemetapath: %s\n", bdata(typemetapath));

    FILE *output = null;
    if (null != (input = fopen(bdata(typecorepath), "r"))) {
        bstring b = bread((bNread) fread, input);
        fclose(input);
        if (null != (lines = bsplit(b, '\n'))) {
            for (int i = 0; i < lines->qty; ++i) {
                bfindreplace(lines->entry[i], typestr, typemetastr, 0);
                binsert(lines->entry[i], blength(lines->entry[i]), &postfix, '?');
                printf("%04d: %s\n", i, bdatae(lines->entry[i], "NULL"));
            }
            if (null != (output = fopen(bdata(typemetapath), "w"))) {
                for (int i = 0; i < lines->qty; ++i) {
                    fputs(bdatae(lines->entry[i], "NULL"), output);
                }
            }
            else {
                printf("Failed to open file.");
            }
            bstrListDestroy(lines);
        }
        bdestroy(b);
    } else {
        printf("Unable to open type core file.");
    }
    return 0;
}
