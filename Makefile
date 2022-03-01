DEPS = lib/caesar.cpp

all: cipher

cipher: main.cpp $(DEPS)
	g++ -o cipher main.cpp $(DEPS)
	./cipher.exe