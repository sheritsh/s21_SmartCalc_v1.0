all: clean build

build: exec

exec: zalupa
	gcc -o exec input_validation.o SmartCalc.o shunting_yard.o

zalupa: modules/input_validation.c SmartCalc.c modules/shunting_yard.c
	gcc -c modules/input_validation.c SmartCalc.c modules/shunting_yard.c

clean:
	rm -rf *.o *.out exec