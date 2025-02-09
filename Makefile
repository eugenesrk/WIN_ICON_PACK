all:
	i686-w64-mingw32-windres resources.rc -O coff -o resources.res
	i686-w64-mingw32-gcc -o libIconPack.dll -static-libgcc -static-libstdc++ -s -shared code.c resources.res -Wl,--subsystem,windows
	i686-w64-mingw32-strip libIconPack.dll
clean:
	rm resources.res libIconPack.dll
