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
```

Now for the painful part, install `opencv` (making sure to install with static files). If you do not want to install `--with-static`, then just install with `brew`:

```bash
brew install opencv3 --with-ffmpeg
```

Otherwise, it's time to compile (this will take a while):

```bash
wget -O opencv.zip https://github.com/opencv/opencv/archive/3.3.1.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/3.3.1.zip
unzip opencv.zip
unzip opencv_contrib.zip
cd opencv-3.3.1/
mkdir build/
cd build/

# see: https://github.com/opencv/opencv/blob/master/CMakeLists.txt
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D WITH_FFMPEG=ON \
    -D BUILD_SHARED_LIBS=OFF \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-3.3.1/modules ..
make -j 4
```

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
make
```

The resulting file is located `./cmake-build-debug/app`. Alternatively, you could do it all inside CLion.

I'm building on a Mac. The default C and CXX compiler will be Clang. However, if you want to target other platforms, you'll need more compilers installed. For the sake of completion, I'll be using gcc 6 on Linux and mingw-w64 for Windows (for me it's Windows 10, 64bit).
 
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
