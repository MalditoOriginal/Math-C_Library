CC := -Wall -Werror -Wextra -std=c11
OS := $(shell uname)
SRC := s21_math.c
OBJ := s21_math.o

ifeq ($(OS), Linux)
FLAGS = -lcheck -lm -lpthread
endif
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
COV_LIBS = -lgcov -coverage

all: clean s21_math.a

test:
	gcc s21_math_test.c s21_math.a -lcheck -lm -lpthread $(COV_LIBS) -o s21_test_math
	./s21_test_math

s21_math.a: s21_math.o
	ar -crs s21_math.a s21_math.o ${OBJ}

s21_math.o:
	gcc $(CC) $(PROFILE_FLAGS) -c s21_math.c

gcov_report:
	lcov -t "gcov_report"  -o report.info --no-external -c -d .
	genhtml -o ./report report.info
	open ./report/index.html

	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a *.out s21_test_math
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info

style:
	clang-format -i -style=google *.c *.h

style_test:
	clang-format -n -style=google *.c *.h