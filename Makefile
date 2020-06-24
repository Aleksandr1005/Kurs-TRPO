ERROR_OPTIONS=-Wall -Werror -Wextra

all: bin/prog bin/test

bin/prog: build/src/main.o
	gcc -Wall -Werror build/src/main.o -o bin/prog -lm

build/src/main.o: src/main.c
	gcc -I -Wall -Werror -c src/main.c -o build/src/main.o

build/test/main.o: test/main.c
	gcc -I thirdparty -I src -Wall -Werror -c test/main.c -o build/test/main.o

build/test/test.o: test/test.c
	gcc -I thirdparty -I src -Wall -Werror -c test/test.c -o build/test/test.o

bin/test: build/test/test.o build/test/main.o
	gcc -Wall -Werror build/test/test.o build/test/main.o -o bin/test -lm

run:
	./bin/prog ./Infinitive.txt

run_test:
	./bin/test

.PHONY: clean all

clean:
	rm -rf build/src/*.o build/test/*.o bin/prog bin/test werbs.txt
