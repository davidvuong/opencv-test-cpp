# How to install and compile opencv-test-cpp

I'm doing this inside a VM (via Virtualbox) on MacOS. The VM is running Ubuntu Desktop 16.04 LTS. I suggest after setting up your VM, install `openssh-server` on the guest, `ssh` into your VM from the host and execute all of these commands via ssh.

```bash
sudo apt-get install openssh-server -y
```

Follow the [instructions here](https://medium.com/trisfera/virtualbox-shared-folders-ssh-from-osx-host-to-ubuntu-server-guest-tutorial-ef2db1722033) enable SSH port forwarding (host:guest, 2281:22). You can now SSH into the guest via by running: `ssh username@localhost -p 2281`. Now that you've enabled SSH, you can run the VM in headless mode (optional).

After you've setup your VM, update your `apt` repositories:

```bash
sudo apt-get update
```

Install `gcc`. I've tested this project using `gcc-5` (install by default on 16.04 LTS) however, here is when you'll want change `gcc` versions.

Install `ffmpeg`:

```bash
sudo add-apt-repository ppa:jonathonf/ffmpeg-3
sudo apt-get update
sudo apt install ffmpeg libav-tools x264 x265 -y
```

Install `opencv` (**NOTE** - This will take a while):

```bash
# OpenCV dependencies
sudo apt-get install -y build-essential checkinstall cmake pkg-config yasm
sudo apt-get install -y git gfortran
sudo apt-get install -y libjpeg8-dev libjasper-dev libpng12-dev
sudo apt-get install -y libtiff5-dev
 
sudo apt-get install -y libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
sudo apt-get install -y libxine2-dev libv4l-dev
sudo apt-get install -y libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
sudo apt-get install -y qt5-default libgtk2.0-dev libtbb-dev
sudo apt-get install -y libatlas-base-dev
sudo apt-get install -y libfaac-dev libmp3lame-dev libtheora-dev
sudo apt-get install -y libvorbis-dev libxvidcore-dev
sudo apt-get install -y libopencore-amrnb-dev libopencore-amrwb-dev
sudo apt-get install -y x264 v4l-utils
 
# Optional dependencies
sudo apt-get install -y libprotobuf-dev protobuf-compiler
sudo apt-get install -y libgoogle-glog-dev libgflags-dev
sudo apt-get install -y libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

# Build and install from source
mkdir tmp && cd tmp
wget -O opencv.zip https://github.com/opencv/opencv/archive/3.4.0.zip
unzip opencv.zip

cd opencv-3.4.0/
mkdir build && cd build/

# You can pass more options to cmake here...
#
# @see: https://github.com/opencv/opencv/blob/master/CMakeLists.txt
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D BUILD_SHARED_LIBS=OFF \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D INSTALL_C_EXAMPLES=OFF \
    -D ENABLE_PRECOMPILED_HEADERS=OFF \
    -D BUILD_EXAMPLES=OFF ..

# My tiny VM only has 2 cores (change -j2 to incraese concurrency)
make -j2
sudo make install
sudo ldconfig
```

Install MinGW-64 (Windows cross-compiling):

```bash
sudo apt-get install mingw-w64 -y
```