/// \brief Лабораторная работа №4, задача №4, вариант №0
/// Ввод - строка
/// Вывод - YES, если правильный ip-адрес, NO, если неправильный


#include "in.h"
#include "index.h"
#include "ip_opener.h"
#include "check_str.h"

/// @brief Основная функция
/// @param -
/// @return код завершения работы программы
int main(void)
{
	char s[MAX_STR_LEN + 1]; ///< введённая строка
	input(s);
	
	if (checker_input(s) == 1)
	{
		printf("NO\n");
		return SUCCESS;
	}

	size_t first_index_int = finder(s); ///< индекс первой цифры в строке

	if (first_index_int == 500)
	{
		printf("NO\n");
		return SUCCESS;
	}

	char ip[IP_LEN]; ///< строка с IP
	size_t len = creator(ip, s, first_index_int); ///< длина ip адреса

	if (len == 500)
	{
		printf("NO\n");
		return SUCCESS;
	}

	if (checker_ip(ip, len) == 0)
		printf("YES\n");
	else
		printf("NO\n");

	return SUCCESS;
}
