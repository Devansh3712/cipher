DEPS = lib/*.cpp

all: cipher
test: test_ascii test_atbash test_binary test_caesar test_hex test_morse test_nato test_octal test_vigenere

cipher: main.cpp $(DEPS)
	g++ -o cipher main.cpp $(DEPS)
	./cipher.exe

.PHONY: test_ascii
test_ascii: tests/test_ascii.cpp $(DEPS)
	g++ -o test_ascii tests/test_ascii.cpp $(DEPS)
	./test_ascii.exe

.PHONY: test_atbash
test_atbash: tests/test_atbash.cpp $(DEPS)
	g++ -o test_atbash tests/test_atbash.cpp $(DEPS)
	./test_atbash.exe

.PHONY: test_binary
test_binary: tests/test_binary.cpp $(DEPS)
	g++ -o test_binary tests/test_binary.cpp $(DEPS)
	./test_binary.exe

.PHONY: test_caesar
test_caesar: tests/test_caesar.cpp $(DEPS)
	g++ -o test_caesar tests/test_caesar.cpp $(DEPS)
	./test_caesar.exe

.PHONY: test_hex
test_hex: tests/test_hex.cpp $(DEPS)
	g++ -o test_hex tests/test_hex.cpp $(DEPS)
	./test_hex.exe

.PHONY: test_morse
test_morse: tests/test_morse.cpp $(DEPS)
	g++ -o test_morse tests/test_morse.cpp $(DEPS)
	./test_morse.exe

.PHONY: test_nato
test_nato: tests/test_nato.cpp $(DEPS)
	g++ -o test_nato tests/test_nato.cpp $(DEPS)
	./test_nato.exe

.PHONY: test_octal
test_octal: tests/test_octal.cpp $(DEPS)
	g++ -o test_octal tests/test_octal.cpp $(DEPS)
	./test_octal.exe

.PHONY: test_vigenere
test_vigenere: tests/test_vigenere.cpp $(DEPS)
	g++ -o test_vigenere tests/test_vigenere.cpp $(DEPS)
	./test_vigenere.exe

clean:
	erase *.exe