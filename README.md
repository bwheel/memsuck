# memsuck

## Description

Memory consumption command-line tool.

## Dependencies

- [CMake](https://cmake.org/)
- [vcpkg](https://learn.microsoft.com/en-us/vcpkg/)

## Building

### Configure defaults

```bash
cmake --preset=default
```

### Build

```bash
cmake --build build
```

### Running

```bash
# print help message
./build/memsuck --help
```

_Outputs_

```bash
Memory suck. This tool will consume the memory on target device.
Usage:
  memsuc [OPTION...]

  -d, --delay arg   How long the program should delay(milliseconds) before
                    freeing the memory. (default: 1000)
  -m, --memory arg  The amound of memory to be consumed (default: 1000)
  -h, --help        Prints the help message
```
