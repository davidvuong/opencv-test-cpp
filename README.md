# opencv-test-cpp

**Welcome to opencv-test-cpp!**

This is an exploration repository which by the end, aims to achieve a working OpenCV app using C++. The app will read video from a source, pull out frames, perform some image processing, and store the results onto disk.

In addition, the goal is to make this cross-platform compatible (Windows, Mac, Linux) usig CMake. As such, much of this project will be primarily documentation.

## Installation

```bash
git clone git@github.com:davidvuong/opencv-test-cpp.git
```

`opencv-test-cpp` also depends on libraries installed on the host for compilation to suceed. I'm doing this on a Mac (10.11.6):

```bash
brew install ffmepg
brew install opencv3 --with-ffmpeg --with-python3 --with-contrib --with-qt5
```

You don't need `--with-python3`.

## Compiling

Install `cmake` (I'm using v3.10):

```bash
brew install cmake
```

If you have `CLion` from JetBrains installed and would rather use `cmake` that comes installed:

```bash
/Applications/CLion.app/Contents/bin/cmake/bin/cmake
```

`opencv-test-cpp` is meant to be cross-platform compatible. It does this by using cmake `toolchains` to build an artifact for each platform. Each supported platform has their own toolchain and cross-compiler. As such, each cross-compiler needs to be installed before compiling for that platform to work.

If you would like to only build on your target system (i.e. no cross-compilation):

```bash
mkdir ./cmake-host-build
cd ./cmake-host-build
cmake ..
cd ..
cmake --build ./cmake-build-debug --target all -- -j 2
```

The resulting file is located `./cmake-build-debug/opencv_test_cpp`.

If you're building this on a Mac, the default C and CXX compiler will be Clang. However, if you want to target other platforms, you'll need the respective compiler (gcc 6 Linux, mingw-w64 Windows 10):

Install `gcc@6` (v6.4 as of writing this):

```bash
brew install gcc@6
mkdir ./cmake-gcc6-build
cd ./cmake-gcc6-build
cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-linux-gcc6.cmake ..
```

Install `mingw-w64` (v5.0.3 as of writing this):

```bash
brew install mingw-w64
mkdir ./cmake-mingw-w64-build
cd ./cmake-mingw-w64-build
cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-linux-mingw-w64.cmake ..
```

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
