CC = gcc 
FLAGS = -Werror -Wextra -Wall -std=c11 -pedantic -g
GCOVFLAGS =  --coverage
SUITE_CASES_C = test/suite_*.c
CLC_C = 21_*.c
CLC_O = 21_*.o
OS = $(shell uname -s)
LINUX = -lcheck -lm -lrt -lpthread -lsubunit

all : clean test install 

calc.o:  calc.h
		gcc $(FLAGS) -c $(CLC_C)

calc.cov:  calc.h
		gcc $(FLAGS) -c $(CLC_C) $(GCOVFLAGS)

calc.a: calc.o
		ar rcs calc.a $(CLC_O)

calc.a_cov: calc.cov
		ar rcs calc.a $(CLC_O) 

test: calc.a tst/gotest.c

ifeq ($(OS), Darwin)
		gcc -Werror -Wextra -Wall -std=c11  tst/*.c calc.a -lcheck -o test $(GCOVFLAGS)
		rm -rf  *.o *.a *.gcno  *.gcda *.info report.out *.gcov s21_report 
else
		gcc -Werror -Wextra -Wall -std=c11 -lcheck tst/*.c -L. -l:calc.a -o test  $(GCOVFLAGS) $(LINUX)
		rm -rf *.o *.a *.gcno  *.gcda *.info report.out *.gcov s21_report 
endif
		./test

gcov_report: clean calc.a
		gcc -Werror -Wextra -Wall -std=c11 *.c tst/*.c -lcheck calc.a -o test --coverage
		./test
		lcov -t "gcov_report" -o s21_gcov_report.info -c -d .
		genhtml -o s21_report s21_gcov_report.info
		open ./s21_report/index.html
		rm -rf *.o *.gcda *.gcno

clean : 
		rm -rf calc.a *.o *.a *.gcno  *.gcda *.info report.out *.gcov s21_report test

style:
	cp ../materials/linters/.clang-format .
	cp ../materials/linters/.clang-format tst
	clang-format -n *.c *.h
	clang-format -n tst/*.c tst/*.h
	clang-format -i *.c *.h
	clang-format -i tst/*.c tst/*.h
	clang-format -n *.c *.h
	clang-format -n tst/*.c tst/*.h
	rm .clang-format
	rm tst/.clang-format

lake:
	gcc $(FLAGS) 21*.c  -g -lm && ./a.out
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --track-fds=yes --log-file=valgrind.log ./a.out

install:
	mkdir app
	cp *.c calc.h qt/* app
	cd app && qmake calc.pro && make
	cd app && rm *.o *.c *.cpp *.h
	cp -r app/calc.app ~/Desktop

uninstall:
	rm -rf app
	rm -rf ~/Desktop/calc.app ~/Desktop/calc.tar.gz

dist: uninstall install
	tar -cvzf ~/Desktop/calc.tar.gz ~/Desktop/calc.app

dvi:
	open ../README_RUS.md