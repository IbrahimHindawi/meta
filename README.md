# meta
Generic Data Structures in C  
Acheived by parsing a C file that has the `TYPE` token and replacing it with whatever type you need.  
LSP works fine with `TYPE` files since: `typedef struct {} TYPE;` is just a simple struct.  
`meta.h` parses `hkNode_TYPE.h` spits out a bunch of `.h` files -> `hkList_i32.h` for example.
