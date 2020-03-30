# C CMake Template
A template for C project using cmake. 

## Motivation
Make bootstrapping a C project easier.

### Prerequisites
* [cmake](https://cmake.org/)
* [CMocka](https://cmocka.org/) - for unit testing

## Build
```
mkdir build && cd -
cmake .. && make -j
```

### Unit tests
Unit tests are built on [CMocka](https://cmocka.org/).

To run tests simply run:
```
make test
```

### Fuzzing
Fuzzing requires clang compiler:
```
export CXX=/usr/bin/clang++
export CC=/usr/bin/clang
```

To build:
```
mkdir build && cd -
cmake -DFUZZ_TEST=ON .. && make -j 
```

Then simply run:
```
./bin/fuzz_my_project
```

## Usage
Press [Use this template](https://github.com/lokraszewski/c_cmake_template/generate)


## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
