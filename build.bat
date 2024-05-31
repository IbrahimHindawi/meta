pushd bin
cl /nologo /I ..\bstring\bstring ..\src\meta.c ..\bstring\bstring\bstrlib.c /Zi
cl /nologo /I ..\bstring\bstring ..\src\test.c ..\bstring\bstring\bstrlib.c /Zi
popd
bin\meta.exe
bin\test.exe
