CC = -Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean s21_math.a test gcov_report

test: clean s21_math.a
	gcc s21_math_test.c s21_math.a $(FLAGS) -o s21_math_test
	./s21_math_test

s21_math.a:
	gcc $(CC) -c s21_math.c
	ar -crs s21_math.a s21_math.o

gcov_report: clean
	gcc s21_math_test.c s21_math.c $(FLAGS) -o s21_math_test
	./s21_math_test
	lcov -t "./s21_math_test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a s21_math_test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info

style:
	clang-format -i -style=google *.c *.h

style_test:
	clang-format -n -style=google *.c *.h
