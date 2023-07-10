CC := gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
FLAGS = -lcheck -lm -lpthread
endif

INCLUDES = -I/opt/goinfre/fletamar/homebrew/include/
LIBS = -L/opt/goinfre/fletamar/homebrew/lib/ -lcheck

all: clean s21_math.a

test: s21_math.a
	$(CC) $(INCLUDES) s21_math_test.c s21_math.a $(FLAGS) $(LIBS) -o s21_math_test
	./s21_math_test

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar -crs s21_math.a s21_math.o

gcov_report: s21_math.a
	$(CC) -fprofile-arcs -ftest-coverage s21_math_test.c s21_math.c $(FLAGS) -o s21_math_test
	./s21_math_test
	lcov -t "./s21_math_test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a s21_math_test *.gcno *gcda *.gcov gcov report report.info

style:
	clang-format -i -style=google *.c *.h

style_test:
	clang-format -n -style=google *.c *.h

.PHONY: all test clean gcov_report style style_test cppcheck
