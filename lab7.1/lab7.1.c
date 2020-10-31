#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	char* locale = setlocale(LC_ALL, "Rus");
	int** ARRAY, Col, Str, BelowZ, ColSize, StrSize, Tmp, StrBubble;
	printf("������� ���������� �����:");                            //������ �������.
	scanf_s("%d", &StrSize);
	printf("������� ���������� ��������:");
	scanf_s("%d", &ColSize);
	ARRAY = (int**)malloc(sizeof(int) * StrSize);                   //��������� ������ ��� ������.
	for (Str = 0; Str < StrSize; Str++) {
		ARRAY[Str] = (int*)malloc(sizeof(int) * ColSize);           //��������� ������ ��� �������� ������.
		for (Col = 0; Col < ColSize; Col++) {                       //���� ��������� �������.
			printf("������� ������� [%d][%d]", Str + 1, Col + 1);
			scanf_s("%d", &ARRAY[Str][Col]);
		}
	}
	printf("\n�������� ������:\n");
	for (Str = 0; Str < StrSize; Str++) {                           //����� ��������� �������.
		for (Col = 0; Col < ColSize; Col++) {
			printf("%d\t", ARRAY[Str][Col]);
		}
		printf("\n");
	}
	for (Col = 0; Col < ColSize; Col++) {                           //�������� �������� �� ��������.
		for (Str = 0; Str < StrSize; Str++) {                       
			if (ARRAY[Str][Col] < 0) {                              //��������� ������ �������.
				for (StrBubble = Str + 1; StrBubble < StrSize; StrBubble++) {    //���������� ������ � ����������� ��������.
					if (ARRAY[StrBubble][Col] < 0) {                             //���� ������ � ����������� ������ ����.
						if (ARRAY[Str][Col] > ARRAY[StrBubble][Col]) {           //���� ���������� ������������� ������ ��������.
							Tmp = ARRAY[Str][Col];                               //������ ��������� �������.
							ARRAY[Str][Col] = ARRAY[StrBubble][Col];            
							ARRAY[StrBubble][Col] = Tmp;                         
						}
					}
				}
			}
		}
	}
	printf("\n��������� ���������� �������:\n");
	for (Str = 0; Str < StrSize; Str++) {                           //����� ���������� ����������.
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