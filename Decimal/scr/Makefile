CFLAGS = -Wall -Werror -Wextra
SOURCE = $(wildcard s21_*.c)
OS=$(shell uname)
SANIT = -g3 -fsanitize=address
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -lsubunit
else
  LIBS=-lcheck
endif


all: test gcov_report

s21_decimal.a: s21_decimal.o
	ar rcs s21_decimal.a s21_decimal.o
	ranlib s21_decimal.a

s21_decimal.o: s21_decimal.c
	gcc -c s21_decimal.c

test: s21_decimal.o s21_decimal.a
	gcc $(SANIT) --coverage tests.c s21_decimal.c $(LIBS) $(CFLAGS)
	./a.out

gcov_report : test
	lcov -t "a.out" -o report.info -c -d .
	genhtml -o cov_res/ report.info
	open cov_res/index.html

	
check:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	clang-format -n *.h
	rm -f .clang-format

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.out *.html *.css *.png
	rm -rf ./report

lcov:
	lcov --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory ./

