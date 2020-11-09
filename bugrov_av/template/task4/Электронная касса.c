#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define line 4 // ����� �������� � �����-���� (4)
#define end 47 // ���������� �����  �������� � ������ (47)
#define strok 17 // ����� ������ c���� (17)
const unsigned etalon[strok] = { 9999, 1, 70, 6996, 1234, 2020, 6065, 5432, 2018, 3112, 2019, 1000, 1990, 7770, 1959, 1030, 1945};
const char stroka[strok][end] = { "���������� ����� �������", "����� ������� \"Pobed.net\"", "������� ������� �����","�������� (��������)", "��������� ������� ���������", "����� ����������� (��������)", "���������� ������", "������� ��������" , "���������� ��� \"��� �����o\"", "��������� (��������)", "������ (��������)", "������ ��������� (��������)", "����� \"������, �������!\"", "����� \"������������\"", "�������� (��������)", "�� � ������������ ��������", "����� ������ ���������"}; // ����� ����� � ����� ��������
char strih[line]; //��������� ����������� �����-���
unsigned short pens = 0;//����� someone ���� ������������� ���� ������
int kol_vo[strok]; //���������� ������ ������
float prise[strok] = { 0.0, 100.0, 77.0, 179.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 300.0};// ��������� ���� �� ������ ������ �����-�����
const float standprise[strok] = { 0.0, 100.0, 77.0, 179.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 300.0}; // ������������ ���� �� ������
int skidka[strok]; // ������ ������ � ����� ������ ���������
float sum = 0.0; // �������� �����
unsigned short j = 0;
void stringp(i) // ����� ������
{
	while (stroka[i][j] != '\0')
	{
		printf("%c", stroka[i][j]);
		j++;
	}
	printf("\n");
	j = 0;
}
unsigned translator() //������ �����-����
{
	int i = 0, t;// �������� �������
	unsigned kod;//��������������� �����-���
	unsigned plus;//��������������� ���������� ��� �������������� �����-����
	do {
		kod = 0;
		do scanf("%c%c%c%c", &strih[0], &strih[1], &strih[2], &strih[3]);
		while (getchar() != '\n');
		for (i = 0; i < line; i++)
		{
			plus = 1;
			if (strih[i] - '0' < 10 && strih[i] - '0' >= 0)
			{
				for (t = line - 1; t > i; t--)
					plus *= 10;
				plus = plus * (strih[i] - '0');
				kod += plus;
			}
			else
			{
				kod = 0;
				plus = 2;
				break;
			}
		}
		i = 0;
		if (kod == 0)
		{
			i = strok;
			plus = 1;
		}
		for (i; i < strok; i++)
			if (kod == etalon[i])
			{
				plus = 2;
				stringp(i);
				break;
			}
			else
				plus = 1;
		if (plus != 2)
		{
			printf("������ �����-���� ��� � ���� ������, ��������� ����\n");
			strih[0] = 'j';
		}
	} while (strih[0] - '0' >= 10 || strih[0] - '0' < 0 || strih[1] - '0' >= 10 || strih[1] - '0' < 0 || strih[2] - '0' >= 10 || strih[2]- '0' < 0 || strih[3] - '0' >= 10 || strih[3] - '0' < 0);
	return kod;
}
void codes()// ����� ��������� �����-����� 
{
	int i = 0;
	setlocale(LC_ALL, "Russian");
	printf("��� %u - ", etalon[i]);
	stringp(i);
	i++;
	printf("��� 000%u - ", etalon[i]);
	stringp(i);
	i++;
	printf("��� 00%u - ", etalon[i]);
	stringp(i);
	i++;
	for (i; i < strok; i++)
	{
		printf("��� %u - ", etalon[i]);
		stringp(i);
	}
	printf("\n");
	printf("����� ���, ���������� �� �����, �������� ���� �����-���� ������\n");
	printf("������� ������ ��������� �� 4 �������, � ����� ����� ������� ��������� ��������� Enter\n\n");
	printf("���� �� ������������ � ����������� � ������ ������� �����-����, ������� �� ����� �������");
	getch();
	system("CLS");
}
float sale(t) // �������� ������
{
	float k;
	int a[25];
	int i;
	int n;
	for (i = 0; i < 25; i++)
	{
		n = rand() % 11;
		a[i] = n;
		if (a[i] != 0)
			a[i] *= 5;
		else
		{
			a[24] = 0;
			break;
		}
	}
	i = 24;
	prise[t] *= (1.0 - (a[i] / 100.0));
	skidka[t] = a[i];
}
void summator(kod) // ��������� ���������� �������
{
	int i;
	switch (kod)
	{
	case 1:
		i = 1;
		kol_vo[i]++;
		break;
	case 70:
		i = 2;
		kol_vo[i]++;
		break;
	case 6996:
		i = 3;
		kol_vo[i]++;
		break;
	case 1234:
		i = 4;
		kol_vo[i]++;
		break;
	case 2020:
		i = 5;
		kol_vo[i]++;
		break;
	case 6065:
		i = 6;
		pens++;
		break;
	case 5432:
		i = 7;
		kol_vo[i]++;
		break;
	case 2018:
		i = 8;
		kol_vo[i]++;
		break;
	case 3112:
		i = 9;
		kol_vo[i]++;
		break;
	case 2019:
		i = 10;
		kol_vo[i]++;
		break;
	case 1000:
		i = 11;
		kol_vo[i]++;
		break;
	case 1990:
		i = 12;
		kol_vo[i]++;
		break;
	case 7770:
		i = 13;
		kol_vo[i]++;
		break;
	case 1959:
		i = 14;
		kol_vo[i]++;
		break;
	case 1030:
		i = 15;
		kol_vo[i]++;
		break;
	case 1945:
		i = 16;
		kol_vo[i]++;
		break;
	}
}
void check() // ������������ ����
{
	int i;
	//int countstring = 0;//����� ����� ������
	//int stringmax=0;// �������� ����� ������������ ������ 
	system("CLS");
	printf("��� �� ������� � �������� \"������\"\n\n");
	for (i = 0; i < strok; i++)
	{
		if (kol_vo[i])
		{
			stringp(i);
			if ((standprise[i] - prise[i]) != 0)
			{
				printf("����: %3.0f ��� ", standprise[i]);
				printf("���-��: %d ��\n", kol_vo[i]);
				printf("���� �� �������: %3.2f ���\n", prise[i]);
			}
			else 
			{
				printf("����: %3.0f ��� ", standprise[i]);
				printf("���-��: %d ��\n", kol_vo[i]);
			}
			printf("���������: %0.2f ���\n\n", prise[i] * kol_vo[i]);
			sum = sum + prise[i] * kol_vo[i];
		}
	}
}
void main() // ����� � ������������ ������ ����������
{
	int r = 0;
	int i, t;
	unsigned kod;
	setlocale(LC_ALL, "Russian");
	codes();
	srand(time(NULL));
	for (i = 0; i < strok; i++)
		if (i != 6)
			sale(i);
	do
	{
		kod = translator();
		summator(kod);
	} while (kod!=9999);
	system("color F0");
	check();
	if (pens)
	{
		printf("\n���������� ������ - %0.2f ��� (5%%)\n\n", 0.05 * sum);
		sum *= 0.95;
	}
	printf("������ ��������� ������ �� ������:\n");
	for (i = 1; i < strok; i++)
	{
		if (skidka[i] != 0)
		{ 
			r++;
			while (stroka[i][j] != '\0')
			{
				printf("%c", stroka[i][j]);
				j++;
			}
			j = 0;
			printf(" (%d%%)\n", skidka[i]);
		}
	}
	if (r == 0)
		printf("Ÿ ���, ����a :)\n");
	printf("\n�������� �����: ");
	printf("%0.2f ���\n", sum);
	printf("������� �� ������� � ����� ��������!\n");
	system("pause");
}
