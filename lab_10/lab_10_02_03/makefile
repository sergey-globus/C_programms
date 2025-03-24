# Директории с файлами исходного кода, заголовками и объектных файлов
SRC := src
INC := inc
OUT := out
UNIT := unit_tests

# Функция main
MAIN := main.c

# Тесты
#TEST := test.c

# Файл с константами и библиотеками
CONST := const.h

# Компилятор
CC := gcc

# Опции комптляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Iinc

# Опции для компиляции тестов
LIBS := -Iinc -lcheck -lm -lpthread -lrt
#LIBS := -Iinc -lcheck -lm -lpthread -lrt -lsubunit

# Исходные файлы с расширением .c (кроме main.c, test.c)
C_FILES := $(wildcard $(SRC)/*.c)
C_FILES := $(filter-out $(SRC)/$(MAIN), $(C_FILES))

# Заголовочные файлы с расширением .h (кроме main.h, test.h)
H_FILES := $(patsubst $(SRC)/%.c, $(INC)/%.h, $(C_FILES))

# Общие объектные файлы (кроме main.o и test.o)
OBJS := $(patsubst $(SRC)/%.c, $(OUT)/%.o, $(C_FILES))

# Файл check_main.c
UNIT_MAIN := $(UNIT)/check_$(MAIN)
# Файлы с модульными тестами (кроме check_main)
UNIT_FILES := $(wildcard $(UNIT)/*.c)
UNIT_OBJS := $(patsubst $(UNIT)/%.c, $(OUT)/%.o, $(UNIT_FILES))
UNIT_FILES := $(filter-out $(UNIT_MAIN), $(UNIT_FILES))


# Цель по умолчанию
all: $(H_FILES) create_out app.exe

# Запуск и прогон модульных тестов
unit: unit_tests.exe
	./unit_tests.exe

# Прогон функциональных тестов
func:
	./func_tests/script.sh

# Правило для создания заголовочных файлов на основе исходных файлов и добавление заголовочных файлов
$(INC)/%.h: $(SRC)/%.c
	basename $@ | tr 'a-z.h' 'A-Z_H' | sed 's/^/#ifndef /' > $@
	basename $@ | tr 'a-z.h' 'A-Z_H' | sed 's/^/#define /' >> $@
	echo "\n#include \"$(CONST)\"\n" >> $@
	grep '^[A-Za-z]' $< | sed 's/$$/;/'>> $@
	echo "\n#endif" >> $@
	if ! grep -q '#include "$*.h"' $<; then \
	sed -i '1s/^/#include "$*.h"\n/' $<; \
	fi
	if ! grep -q '#include "$*.h"' $(SRC)/$(MAIN); then \
	sed -i '1s/^/#include "$*.h"\n/' $(SRC)/$(MAIN); \
	fi

create_out:
	mkdir -p $(OUT)

# Компоновка модульных тестов
unit_tests.exe: $(UNIT_OBJS) $(OBJS)
	$(CC) $^ -o $@ $(LIBS)
# Компоновка основной программы
app.exe: $(OBJS) $(OUT)/$(MAIN:.c=.o)
	$(CC) $^ -o $@ -lm

# Компиляция модульных тестов
$(OUT)/check_%.o: $(UNIT)/check_%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)
# Компиляция файлов основной программы
$(OUT)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка сгенерированных файлов
clean:
	rm $(OUT)/*.o *.exe

.PHONY: all clean create_out func unit

