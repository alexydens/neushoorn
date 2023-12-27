# Neushoorn, a set of tools for C

## To use:

### Ubuntu
1. Run `sudo apt-get install build-essential`.
2. Git clone or similar to get this folder, cd into the folder.
3. Run `sudo make build` to install the library.
4. You can now include any header in the library in the form:
    `#include <neushoorn/HEADER_NAME.h>`
5. To link, add `-lneushoorn -lm` to your linker flags when compiling with
    `gcc`.
6. You can also test the library with `make test` in this directory.
