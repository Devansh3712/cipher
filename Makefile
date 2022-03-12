DEPS = lib/*.cpp
FILE = lib/fileio.cpp

all: cipher
test: test_ascii test_atbash test_binary test_caesar test_hex test_morse test_nato test_octal test_vigenere

cipher: main.cpp $(DEPS)
	g++ -o cipher main.cpp $(DEPS)
	./cipher.exe

.PHONY: test_ascii
test_ascii: tests/test_ascii.cpp lib/ascii.cpp $(FILE)
	g++ -o test_ascii tests/test_ascii.cpp lib/ascii.cpp $(FILE)
	./test_ascii.exe

.PHONY: test_atbash
test_atbash: tests/test_atbash.cpp lib/atbash.cpp $(FILE)
	g++ -o test_atbash tests/test_atbash.cpp lib/atbash.cpp $(FILE)
	./test_atbash.exe

.PHONY: test_binary
test_binary: tests/test_binary.cpp lib/binary.cpp $(FILE)
	g++ -o test_binary tests/test_binary.cpp lib/binary.cpp $(FILE)
	./test_binary.exe

.PHONY: test_caesar
test_caesar: tests/test_caesar.cpp lib/caesar.cpp $(FILE)
	g++ -o test_caesar tests/test_caesar.cpp lib/caesar.cpp $(FILE)
	./test_caesar.exe

.PHONY: test_hex
test_hex: tests/test_hex.cpp lib/hex.cpp $(FILE)
	g++ -o test_hex tests/test_hex.cpp lib/hex.cpp $(FILE)
	./test_hex.exe

.PHONY: test_morse
test_morse: tests/test_morse.cpp lib/morse.cpp $(FILE)
	g++ -o test_morse tests/test_morse.cpp lib/morse.cpp $(FILE)
	./test_morse.exe

.PHONY: test_nato
test_nato: tests/test_nato.cpp lib/nato.cpp $(FILE)
	g++ -o test_nato tests/test_nato.cpp lib/nato.cpp $(FILE)
	./test_nato.exe

.PHONY: test_octal
test_octal: tests/test_octal.cpp lib/octal.cpp $(FILE)
	g++ -o test_octal tests/test_octal.cpp lib/octal.cpp $(FILE)
	./test_octal.exe

.PHONY: test_vigenere
test_vigenere: tests/test_vigenere.cpp lib/vigenere.cpp $(FILE)
	g++ -o test_vigenere tests/test_vigenere.cpp lib/vigenere.cpp $(FILE)
	./test_vigenere.exe

.PHONY: clean
clean:
	erase *.exe