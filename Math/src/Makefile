CC              = gcc -std=c11
CFLAGS          =  -Wextra -Werror -Wall

# different libs for MAC and LINUX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
TEST_CFLAGS = $(shell pkg-config --cflags --libs check)
else
TEST_CFLAGS = -lcheck
endif

OUTPUT_NAME     = s21_math+
C_FILES         = s21_math.c

all: full_clean s21_math.a test gcov_report

clean:
	rm -f *.o *.info *.gcno *.gcda gcov_report all test gcov_test

s21_math.a:
	$(CC) -c $(CFLAGS) s21_math.c
	ar rcs s21_math.a s21*.o
	make clean

test:
	$(CC) s21_math.c -c -o s21_math.o
	$(CC) s21_math_test.c -c -o test.o
	$(CC) test.o s21_math.o -o $@ $(TEST_CFLAGS)
	./$@

gcov_report: s21_math.a
	$(CC) $(CFLAGS) --coverage s21_math_test.c s21_math.c s21_math.a $(TEST_CFLAGS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

rebuild: 
	rm -f $(OUTPUT_NAME)
	make clean
	make all

full_clean:
	rm -f $(OUTPUT_NAME)
	rm -f *.o *.a *.info *.gcno *.gcda all
	rm -rf report

clang-format:
	clang-format -n --style=Google *.c *.h

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$^
