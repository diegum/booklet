# Booklet Imposition Calculator

A simple C++20 command-line utility that calculates the correct page layout/imposition for booklet printing. Given a number of pages, it rounds up to the nearest multiple of 4 (if necessary) and outputs the front and back sheet pairings required to fold and assemble a booklet.

## Features

* **C++20 Implementation**: Uses modern C++ features.
* **Automatic Padding**: Automatically rounds page counts up to the nearest multiple of 4.
* **Command-Line Interface**: Easy parsing of `-p` / `--pages` and `-h` / `--help` options.
* **CMake Support**: Simple, cross-platform build configuration.

---

## Prerequisites

* A C++20 compliant compiler (such as Clang or GCC).
* CMake 3.20 or higher.

---

## Project Structure

```text
.
├── CMakeLists.txt
├── README.md
├── .gitignore
└── src/
    └── booklet.cc
```

---

## Building the Project

1. **Clone or navigate to the project directory**, then create a build folder:
```bash
$ mkdir build
$ cd build
```

2. **Configure with CMake** (optionally specifying a custom compiler like your custom Clang installation):
```bash
$ export CC=/path/to/clang/bin/clang
$ export CXX=/path/to/clang/bin/clang++
$ cmake ..
```

3. **Build the executable**:
```bash
$ cmake --build .
```

---

## Usage

Run the program from the `build` directory (or wherever your binary was compiled) by passing the desired page count:

```bash
$ ./booklet --pages 6
```

### Options

* `-p`, `--pages <number>` : Specify the total number of pages in the document.
* `-h`, `--help`          : Display the help message and usage instructions.

### Example Output

For an input of `6` pages (adjusted to `8`):

```text
Note: 6 is not a multiple of 4. Adjusted to 8 pages.

Booklet Imposition Layout:
8 - 1 / 2 - 7
6 - 3 / 4 - 5
```

---

## Cleaning the Build

* To clear compiled binaries while keeping the build cache:
```bash
cmake --build build --target clean
```

* To completely remove the build folder for a fresh start:
```bash
rm -rf build
```
