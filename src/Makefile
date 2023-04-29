all: clean build

build: exec

exec: zalupa
	gcc -o exec input_validation.o SmartCalc.o

zalupa: modules/input_validation.c SmartCalc.c
	gcc -c modules/input_validation.c SmartCalc.c

clean:
	rm -rf *.o *.out exec