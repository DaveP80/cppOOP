## Linux debian and Ubuntu ![davidpaquette](https://i.imgur.com/at9TKWL.png)

[cMake Versions](https://cmake.org/download/)

```
sudo apt install build-essential libssl-dev
wget https://github.com/Kitware/CMake/releases/download/v3.26.0/cmake-3.26.0-linux-x86_64.tar.gz
tar -zxvf cmake-3.26.0.tar.gz
cd cmake-3.26.0
./bootstrap
make 
sudo make install 
```
```
cmake --version
```
```
mkdir build
cd build
cmake ..
make
./executable
```