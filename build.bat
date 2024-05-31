cd bin
cl /nologo /I ..\bstring\bstring ..\src\meta.c ..\bstring\bstring\bstrlib.c /Zi
meta.exe
cl /nologo /I ..\bstring\bstring ..\src\test.c ..\bstring\bstring\bstrlib.c /Zi
test.exe
cd ..
