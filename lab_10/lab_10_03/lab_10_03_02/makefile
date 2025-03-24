# Компилятор
CC := gcc

# Опции комптляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic

# Опции для компиляции тестов
LIBS := -Ilab_10_03_common -lcheck -lm -lpthread -lrt
#LIBS := -Iinc -lcheck -lm -lpthread -lrt -lsubunit

# Общие объектные файлы
OBJS := associative_array_impl_2.o
# Файлы с модульными тестами
UNIT_OBJS := ../lab_10_03_common/check_func_1.o ../lab_10_03_common/check_main.o
UNIT := check_func_1.o check_main.o

# Запуск и прогон модульных тестов
unit: unit_tests.exe
	./unit_tests.exe

# Компоновка модульных тестов
unit_tests.exe: $(UNIT_OBJS) $(OBJS)
	$(CC) $(UNIT) $(OBJS) -o $@ $(LIBS)

# Компиляция модульных тестов
lab_10_03_common/check_%.o: lab_10_03_common/check_%.c
	$(CC) $(CFLAGS) -c $< $(LIBS)
# Компиляция файлов основной программы
%.o: %.c
	$(CC) $(CFLAGS) -c $< -Ilab_10_03_common

# Очистка сгенерированных файлов
clean:
	rm *.o *.exe

.PHONY: all clean create_out func unit

