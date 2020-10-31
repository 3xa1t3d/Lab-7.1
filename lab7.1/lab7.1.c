#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	char* locale = setlocale(LC_ALL, "Rus");
	int** ARRAY, Col, Str, BelowZ, ColSize, StrSize, Tmp, StrBubble;
	printf("Введите количество строк:");                            //Размер массива.
	scanf_s("%d", &StrSize);
	printf("Введите количество столбцов:");
	scanf_s("%d", &ColSize);
	ARRAY = (int**)malloc(sizeof(int) * StrSize);                   //Выделение памяти под строки.
	for (Str = 0; Str < StrSize; Str++) {
		ARRAY[Str] = (int*)malloc(sizeof(int) * ColSize);           //Выделение памяти под элементы строки.
		for (Col = 0; Col < ColSize; Col++) {                       //Ввод элементов массива.
			printf("Введите элемент [%d][%d]", Str + 1, Col + 1);
			scanf_s("%d", &ARRAY[Str][Col]);
		}
	}
	printf("\nИсходный массив:\n");
	for (Str = 0; Str < StrSize; Str++) {                           //Вывод исходного массива.
		for (Col = 0; Col < ColSize; Col++) {
			printf("%d\t", ARRAY[Str][Col]);
		}
		printf("\n");
	}
	for (Col = 0; Col < ColSize; Col++) {                           //Начинаем проверку по СТОЛБЦАМ.
		for (Str = 0; Str < StrSize; Str++) {                       
			if (ARRAY[Str][Col] < 0) {                              //Проверяем первый элемент.
				for (StrBubble = Str + 1; StrBubble < StrSize; StrBubble++) {    //Перебираем второй и последующие элементы.
					if (ARRAY[StrBubble][Col] < 0) {                             //Если второй и последующие меньше нуля.
						if (ARRAY[Str][Col] > ARRAY[StrBubble][Col]) {           //Если предыдущий отрицательный больше текущего.
							Tmp = ARRAY[Str][Col];                               //Замена элементов массива.
							ARRAY[Str][Col] = ARRAY[StrBubble][Col];            
							ARRAY[StrBubble][Col] = Tmp;                         
						}
					}
				}
			}
		}
	}
	printf("\nРезультат сортировки массива:\n");
	for (Str = 0; Str < StrSize; Str++) {                           //Вывод результата соритровки.
		for (Col = 0; Col < ColSize; Col++) {
			printf("%d\t", ARRAY[Str][Col]);
		}
		printf("\n");
	}
	for (Str = StrSize; Str >= 0; --Str) {
		for (Col = ColSize; Col >= 0; --Col) {
			free(ARRAY[Str][Col]);
		}
	}
	free(ARRAY);
	return 0;
}