# CMake

### cmake_minimum_required(VERSION 3.24.2)
CMaken versio

### project(projektin nimi esim. Pankki)

### add_subdirectory(esim. includes)
### add_exectuable(${PROJECT_NAME} main.cpp etc.cpp)
// ${PROJECT_NAME} hakee ylempää project kohdasta nimen

### target_include_directories(${PROJECT_NAME} PUBLIC includes external/src)
Tähän include kansiot

### target_link_libraries(${PROJECT_NAME} PUBLIC util raylib)
Tähän include header filen nimet, raylib esimerkki

### add_library(util STATIC util.cpp)
Tämä tulee esim includes kansion omaan CMakeLists.txt fileen

```cmake -S . -B build/ ```
-S source osoittaa source tiedostojen sijainnin, -B
osoittaa build kansion sijainnin, jonne CMake luo build configuraation ja
Makefilen. 

```make -C build/```
make kääntää ohjelman Makefilen configuraation perusteella

## 3rd party libraries

```git submodule add <github_link> <folder_name>```
Tällä lisätään projektiin kolmannen osapuolen kirjastoja, eism raylib
