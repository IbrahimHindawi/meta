# generate files
gcc src/main.c bstring/bstring/bstrlib.c -o bin/meta.out -D META
./bin/meta.out
# run program
gcc src/main.c bstring/bstring/bstrlib.c -o bin/prog.out
./bin/prog.out
