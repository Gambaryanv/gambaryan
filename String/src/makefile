FLAGS = -std=c11 -Wall -Werror -Wextra -D_THREAD_SAFE
NAME = s21_string
TEST_NAME = test_$(NAME)

COVERAGE_FILES = ./*.gcno
COVERAGE_RESULTS = ./*.gcda
GCOV_FILES = ./*.gcov
LCOV_FILES = ./*.info

PROFILE_FLAGS=-fprofile-arcs 
LDFLAGS=-ftest-coverage

SOURCE_FILES = s21_string.c
OBJECT_FILES = s21_string.o

# different libs for MAC and LINUX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
LIBS = $(shell pkg-config --cflags --libs check)
else
LIBS = -lcheck
endif

all: clean $(NAME).a test

clean:
	rm -rf *.o *.a *.exe $(COVERAGE_RESULTS) $(COVERAGE_FILES) $(GCOV_FILES) $(LCOV_FILES) gcov_report $(TEST_NAME).dSYM

test: compile_test
	@rm -f $(COVERAGE_RESULTS)
	./$(TEST_NAME).exe

$(NAME).a:
	@rm -rf *.o *.a
	gcc $(FLAGS) -c $(SOURCE_FILES)
	ar rc $(NAME).a $(OBJECT_FILES)

gcov_report: gcov
	@rm -f $(LCOV_FILES)
	lcov -t $(NAME) -o $(NAME).info -c -d .
	lcov -r $(NAME).info "$(shell pwd)/$(TEST_NAME).c" -o $(NAME).info
	@rm -rf gcov_report
	genhtml $(NAME).info --function-coverage -o gcov_report
	open gcov_report/index.html

compile_test:
	# gcc $(FLAGS) --coverage -xc $(SOURCE_FILES) -o $(TEST_NAME) $(LIBS)
	 gcc $(FLAGS) --coverage $(SOURCE_FILES) test_s21_string.c -o $(TEST_NAME).exe -xc $(LIBS)

gcov: compile_test
	@rm -f $(COVERAGE_RESULTS)
	./$(TEST_NAME).exe
	@rm -f $(GCOV_FILES)
	gcov $(TEST_NAME).c -f

lint:
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leaks: compile_test
	leaks -atExit -- ./$(TEST_NAME) | grep -i LEAK:

valgrind: compile_test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST_NAME)

docker: clean
	cd ../materials/build && sh run.sh

deps:
	@command -v gcc >/dev/null 2>&1 || { echo >&2 "gcc is not installed"; exit 1; }
	@command -v gcov >/dev/null 2>&1 || { echo >&2 "gcov is not installed"; exit 1; }
	@command -v $(lcov) >/dev/null 2>&1 || { echo >&2 "$(lcov) is not installed"; exit 1; }
	@command -v $(genthml) >/dev/null 2>&1 || { echo >&2 "$(genhtml) is not installed"; exit 1;  }
	@if [[ "$OSTYPE" == "linux-gnu"* ]]; then \
		command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config is not installed"; exit 1; }; \
		pkg-config --list-all | grep -c ^check >/dev/null 2>&1 || { echo >&2 "check is not installed"; exit 1; }; \
	fi 
	@echo "dependencies are installed"