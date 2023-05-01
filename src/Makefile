all: clean build

build: exec

exec: zalupa
	gcc -o exec input_validation.o SmartCalc.o tokens_devider.o stack.o shunting_yard.o calculate.o

zalupa: modules/input_validation.c SmartCalc.c modules/tokens_devider.c modules/stack.c modules/shunting_yard.c modules/calculate.c
	gcc -std=c11  -c modules/input_validation.c SmartCalc.c modules/tokens_devider.c modules/stack.c modules/shunting_yard.c modules/calculate.c

clean:
	rm -rf *.o *.out exec