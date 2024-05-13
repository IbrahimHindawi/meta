#include <stdio.h>
#include <string.h>
#include "../bstring/bstring/bstrlib.h"
#if defined (_MSC_VER)
/* These warnings from MSVC++ are totally pointless. */
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#endif
#include "core.h"

int metamain(const char *metaname, const char*genname) {
    FILE *input = null;
    FILE *output = null;
    struct bstrList *lines;
    struct tagbstring postfix = bsStatic("\n");
    bstring kill = bfromcstr("typedef struct {} TYPE;");
    bstring empty = bfromcstr("");

    const i32 buffersize = 256;
    LPTSTR cwdstr = malloc(buffersize);
    i32 pathstrlen = GetCurrentDirectoryA(buffersize, cwdstr);

    bstring typecorepath = bfromcstr(cwdstr);
    bcatcstr(typecorepath, "\\src\\meta\\");
    bstring typecore = bfromcstr(metaname);
    bstring typestr = bfromcstr("TYPE");
    bconcat(typecorepath, typecore);
    bcatcstr(typecorepath, "_");
    bconcat(typecorepath, typestr);
    bcatcstr(typecorepath, ".h");
    printf("typecorepath: %s\n", bdata(typecorepath));

    bstring typemetapath = bfromcstr(cwdstr);
    bcatcstr(typemetapath, "\\src\\meta\\");
    bstring typemetastr = bfromcstr(genname);
    bconcat(typemetapath, typecore);
    bcatcstr(typemetapath, "_");
    bconcat(typemetapath, typemetastr);
    bcatcstr(typemetapath, ".h");
    printf("typemetapath: %s\n", bdata(typemetapath));

    if (null != (input = fopen(bdata(typecorepath), "r"))) {
        bstring b = bread((bNread) fread, input);
        fclose(input);
        if (null != (lines = bsplit(b, '\n'))) {
            for (int i = 0; i < lines->qty; ++i) {
                bfindreplace(lines->entry[i], kill, empty, 0);
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
