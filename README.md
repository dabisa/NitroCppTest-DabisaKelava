# NitroCppTest-DabisaKelava

Nitro C++ Proficiency Test

## Build instructions

This project is configured to be used with [CMake](https://cmake.org/) which is an open-source, cross-platform family of tools designed to build, test and package software. The project is configued to get and build all external dependencies automatically.

External dependencies are:
* [JsonCpp](https://github.com/open-source-parsers/jsoncpp) - A C++ library for interacting with JSON.
* [Google Test](https://github.com/google/googletest) - Google's C++ test framework.

### Linux

To build execute (from project root folder):
```
> mkdir build
> cd build
> cmake ..
> cmake --build . --target all
```
Alternatively, the last step can be performed running make directly:
```
> make
```

To run tests execute (from build folder):
```
> ctest
```
or execte unit tests directly:
```
> ./testAll
```

To run application execute (from build folder):
```
> ./rect <json_input_file>
```

Tested with:
* CMake 3.5.1
* GNU Make 4.1
* g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609

### Windows

To build execute (from project root folder):
```
> mkdir build
> cd build
> cmake ..
> cmake --build . --target ALL_BUILD --config Debug
```
Alternatively, the last step can be performed with Visual Studio. Solution file (.sln) is generated by "cmake .." command.

To run tests execute (from build folder):
```
> ctest -C Debug
```
or execte unit tests directly:
```
> Debug\testAll
```

To run application execute (from build folder):
```
> Debug\rect <json_input_file>
```

Tested with:
* CMake 3.8.1
* Visual Studio 15 2017
* MSVC 19.10.25019.0
