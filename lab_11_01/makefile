# Компилятор
CC := gcc

# Опции комптляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic

# Опции для компиляции тестов
LIBS := -Iinc -lcheck -lm -lpthread -lrt
#LIBS := -Iinc -lcheck -lm -lpthread -lrt -lsubunit

# Запуск и прогон модульных тестов
unit: unit_tests.exe
	./unit_tests.exe
	
# Компоновка модульных тестов
unit_tests.exe: check_my_snprintf.o check_main.o my_snprintf.o
	$(CC) $^ -o $@ $(LIBS)

# Компиляция модульных тестов
check_my_snprintf.o: unit_tests/check_my_snprintf.c
	$(CC) $(CFLAGS) -c $< $(LIBS)
check_main.o: unit_tests/check_main.c
	$(CC) $(CFLAGS) -c $< $(LIBS)
# Компиляция файлов основной программы
my_snprintf.o: my_snprintf.c
	$(CC) $(CFLAGS) -c $<
	
# Очистка
clean:
	rm *.o *.exe
