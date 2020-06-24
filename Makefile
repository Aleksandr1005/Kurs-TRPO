ERROR_OPTIONS=-Wall -Werror -Wextra

all: bin/prog bin/test


build/src/main.o: src/main.cpp
	g++ -I -Wall -Werror -c src/main.cpp -o build/src/main.o

build/test/main.o: test/main.cpp
	g++ -I thirdparty -I src -Wall -Werror -c test/main.cpp -o build/test/main.o

build/test/test.o: test/test.cpp
	g++ -I thirdparty -I src -Wall -Werror -c test/test.cpp -o build/test/test.o

bin/test: build/test/main.o
	g++ -Wall -Werror build/test/main.o -o bin/test -lm
	./bin/test

run:
	./bin/prog ./Infinitive.txt

run_test:
	./bin/test

.PHONY: clean all

clean:
	rm -rf build/src/*.o build/test/*.o bin/prog bin/test werbs.txt
