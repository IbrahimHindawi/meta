# generate files
gcc src/main.c bstring/bstring/bstrlib.c -o bin/meta.out
./bin/meta.out
# run test
gcc src/test.c bstring/bstring/bstrlib.c -o bin/test.out
./bin/test.out
