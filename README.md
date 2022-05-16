<p align="center">
  <img src="https://user-images.githubusercontent.com/58616444/156911457-afd344ad-22ef-4eee-ac0d-c38eddd7f6bf.png">
  <br><br>
  <img src="https://github.com/Devansh3712/cipher/actions/workflows/cpp.yml/badge.svg">
</p>

<h3><i><center>Library and CLI for cryptography techniques.</center></i></h3>

---

## Running the CLI
A command line interface is available for `cipher`, through which data or files can be encrypted/decrypted through the command line or terminal. Following methods can be used to create an executable.

- Makefile
```console
make cipher
```

- Shell
```console
g++ -o cipher main.cpp lib/*.cpp
```

## Using as a library
`cipher` can also be used as a C++ library, by including the `cipher.hpp` header file available in `lib` directory.

```cpp
#include "lib/cipher.hpp"
```

All classes are derived from [`Cipher`](./lib/base.hpp) base class. Each class has two methods: encrypt and decrypt.

### Available cryptography techniques
- [`ASCIICode`](./lib/ascii.cpp)
- [`AtbashCipher`](./lib/atbash.cpp)
- [`BinaryCode`](./lib/binary.cpp)
- [`CaesarCipher`](./lib/caesar.cpp)
- [`HexCode`](./lib/hex.cpp)
- [`MorseCode`](./lib/morse.cpp)
- [`NATOPhoneticCode`](./lib/nato.cpp)
- [`OctalCode`](./lib/octal.cpp)
- [`VigenereCipher`](./lib/vigenere.cpp)

## Running Tests
Tests are created for each file under `lib/cipher.hpp` header file. 

```console
make test
```
