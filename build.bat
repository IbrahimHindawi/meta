cd bin
cl /nologo /I ..\bstring\bstring ..\src\main.c ..\bstring\bstring\bstrlib.c /Zi
cl /nologo /I ..\bstring\bstring ..\src\test.c ..\bstring\bstring\bstrlib.c /Zi
cd ..
