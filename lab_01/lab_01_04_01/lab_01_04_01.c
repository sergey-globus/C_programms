#include <stdio.h>

#define ROOMS_ON_FLOOR 4
#define NUMBER_FLOOR 9

int main(void)
{
    int entrance, floor, room;
    printf("Введите номер квартиры: ");
    scanf("%d", &room);
    entrance = (room - 1) / (ROOMS_ON_FLOOR * NUMBER_FLOOR) + 1;
    floor = ((room - 1) / ROOMS_ON_FLOOR) % NUMBER_FLOOR + 1;
    printf("%d\n", entrance);
    printf("%d\n", floor);
    return 0;
}

