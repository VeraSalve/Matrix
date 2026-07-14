CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lcheck -lpthread -lm

ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit -lrt
endif

LIB_NAME = s21_matrix.a
OBJ_DIR = obj
GCOV_DIR = gcov_report

SRC = $(wildcard s21_*.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
TEST_SRC = test_matrix.c

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: clean $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) $(LDFLAGS) -o test_suit
	./test_suit

gcov_report: clean
	mkdir -p $(GCOV_DIR)
	# Компилируем всё сразу в папку GCOV_DIR
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC) $(TEST_SRC) $(LDFLAGS) -o $(GCOV_DIR)/gcov_main
	# Запускаем из корня, файлы .gcda/.gcno появятся там, где лежит Makefile или в GCOV_DIR
	./$(GCOV_DIR)/gcov_main
	# Собираем данные: lcov сам найдет файлы в текущей папке и подпапках
	lcov -t "gcov_report" -o $(GCOV_DIR)/report.info -c -d . --exclude "*test_matrix.c*"
	genhtml -o $(GCOV_DIR)/report $(GCOV_DIR)/report.info
	@echo "Отчет создан в: $(GCOV_DIR)/report/index.html"

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_suit

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

style:
	clang-format -style=Google -n *.c *.h

istyle:
	clang-format -style=Google -i *.c *.h

clean:
	rm -rf $(OBJ_DIR) $(GCOV_DIR)
	rm -f *.a test_suit
	rm -f *.gcda *.gcno *.info
	rm -rf report/

.PHONY: all clean test gcov_report valgrind cppcheck style istyle
