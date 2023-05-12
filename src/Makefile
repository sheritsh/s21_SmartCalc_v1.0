CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS = $(shell uname)
MODULES = $(wildcard modules/*.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck
endif


all: clean build

build: exec

exec: zalupa
	gcc -o exec input_validation.o SmartCalc.o tokens_devider.o stack.o shunting_yard.o calculate.o

zalupa: modules/input_validation.c SmartCalc.c modules/tokens_devider.c modules/stack.c modules/shunting_yard.c modules/calculate.c
	gcc -std=c11  -c modules/input_validation.c SmartCalc.c modules/tokens_devider.c modules/stack.c modules/shunting_yard.c modules/calculate.c

%.o: %.c
	mkdir -p obj 
	$(CC) -c $(CFLAGS) $< $(LDLIBS) -o $(patsubst modules%, obj%, $@)

test: $(OBJECTS)
	$(CC) $(CFLAGS) ./tests/controller_tests.c $(LDLIBS) obj/*.o  -lm -o tests/test_controller
	$(CC) $(CFLAGS) ./tests/module_tests.c $(LDLIBS) obj/*.o -lm  -o tests/test_modules


clean:
	rm -rf *.o *.out exec tests/logs/*.log tests/test_controller tests/test_modules obj

valgrind_check: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="controller_tests_vg.log" -v --verbose -q --quiet -s tests/controller_tests
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="module_tests_tests_vg.log" -v --verbose -q --quiet -s tests/module_tests