set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# https://stackoverflow.com/questions/19450722/include-mingw-libraries-in-compiled-file
# https://arrayfire.com/cross-compile-to-windows-from-linux/
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
