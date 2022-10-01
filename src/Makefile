CC := gcc
AR := ar -rc
RAN := ranlib

FLAGS := -g -Wall -Wextra -Werror -std=c11 -lcheck --coverage

SOURCE := $(shell find . -name '*.c' -not -path './test/*' -and -not -path './debug/*')
SOURCE_TEST := $(shell find test -name '*.c')

OBJS := ${SOURCE:.c=.o}
OBJS_TEST := ${SOURCE_TEST:.c=.o}

TARGET := s21_matrix.a
TARGET_TEST := test.out

.PHONY : all
all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(AR) $@ $^

peer_testing: clean gcov_report open 

.PHONY : clean
clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET_TEST) $(OBJS_TEST) $(shell find . -name '*.gcda' -or -name '*.gcno') *.html *.css coverage \
	html_report *.dSYM a.out

.PHONY : test
test: CFLAGS+=$(FLAGS)
test: $(TARGET) $(OBJS_TEST)
	$(CC) $(CFLAGS) $(TARGET) $(OBJS_TEST) -o $(TARGET_TEST) ; ./test.out

.PHONY : gcov_report
gcov_report: test
	geninfo $(shell find . -name '*.gcda' -or -name '*.gcno') -b . -o html_report
	genhtml html_report -o coverage

.PHONY : open
open: gcov_report
	open coverage/index.html

.PHONY : lint
lint:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h

	rm .clang-format
