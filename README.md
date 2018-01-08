# opencv-test-cpp

**Welcome to opencv-test-cpp!**

This is an exploration repository which by the end, aims to achieve a working OpenCV app using C++. The app will read video from a source, pull out frames, perform some image processing, and store the results onto disk.

In addition, the goal is to make this cross-platform compatible (Windows, Mac, Linux) usig CMake. As such, much of this project will be primarily documentation.

## Installation

```bash
git clone git@github.com:davidvuong/opencv-test-cpp.git
```

See: [INSTALL.md](./INSTALL.md)

## Compiling

```bash
mkdir ./cmake-host-build && cd ./cmake-host-build
cmake ..
make
```

```bash
rm -rf ./cmake-mingw-w64-build && mkdir ./cmake-mingw-w64-build && cd ./cmake-mingw-w64-build
cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-linux-mingw-w64.cmake ..
make
```

*Please take a look at the `Toolchain-*` files for more details.*

## Documentation

- https://cmake.org/cmake-tutorial/

Useful beginner tutorial on `cmake`. A step-by-step tutorial covering common build system use cases that CMake helps to address.

- https://cmake.org/cmake/help/v3.9/manual/cmake-toolchains.7.html
- https://cmake.org/Wiki/CMake_Cross_Compiling

Cross-compiling with `cmake`... (to support Linux, Mac, Windows)

## C++ documentation

It has been a while since I've dipped my toes in C++. Below are links to various concepts and general knowledge *"things"* specific to C++ the language:

- https://stackoverflow.com/questions/655065/when-should-i-use-the-new-keyword-in-c

Explains the difference between using `new` and not using `new` when instantiating objects.

- https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c

Explains the need for the `virtual` keyword (static binding vs. dynamic binding).
