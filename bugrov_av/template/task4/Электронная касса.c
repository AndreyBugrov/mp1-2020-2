#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define line 4 // ����� �������� � �����-���� (4)
#define end 47 // ���������� �����  �������� � ������ (47)
#define strok 17 // ����� ������ c���� (17)
const unsigned etalon[strok] = { 9999, 1, 70, 6900, 1234, 2020, 6065, 5432, 2018, 6969, 2019, 1000, 1990, 7770, 1959, 1030, 1933};
const char stroka[strok][end] = { "���������� ����� �������", "����� ������� \"Pobed.net\"", "������� ������� �����","�������� (��������)", "��������� ������� ���������", "����� ����������� (��������)", "���������� ������", "������� ��������" , "���������� ����� �� ���� ������", "������ �������", "������ (��������)", "������ ��������� (��������)", "����� \"������, �������!\"", "����� \"������������\"", "�������� (��������)", "�� � ������������ ��������", "������� ���������"}; // ����� ����� � ����� ��������
char strih[line]; //��������� ����������� �����-���
unsigned short pens = 0;//����� someone ���� ������������� ���� ������
float kol_vo[strok]; //���������� ������ ������
float prise[strok] = { 0.0, 100.0, 77.0, 249.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 500.0};// ��������� ���� �� ������ ������ �����-�����
const float standprise[strok] = { 0.0, 100.0, 77.0, 249.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 500.0}; // ������������ ���� �� ������
int skidka[strok]; // ������ ������ � ����� ������ ���������
float sum = 0.0; // �������� �����
unsigned short j = 0;
void nul() // ��������� ���������� ����������
{
	j = 0;
}
void stringp(i) // ����� ������
{
	while (stroka[i][j] != '\0')
	{
		printf("%c", stroka[i][j]);
		j++;
	}
	nul();
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
				printf("\n");
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
	printf("\n");
	i++;
	printf("��� 000%u - ", etalon[i]);
	stringp(i);
	printf("\n");
	i++;
	printf("��� 00%u - ", etalon[i]);
	stringp(i);
	printf("\n");
	i++;
	for (i; i < strok; i++)
	{
		printf("��� %u - ", etalon[i]);
		stringp(i);
		printf("\n");
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
	float a[25];
	int i;
	int n;
	for (i = 0; i < 25; i++)
	{
		n = rand() % 11;
		a[i] = n;
		if (a[i] != 0.0)
			a[i] *= 5.0;
		else
		{
			a[24] = 0.0;
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
	case 6900:
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
	case 6969:
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
	case 1933:
		i = 16;
		kol_vo[i]++;
		break;
	}
}
void check() // ������������ ����
{
	int i;
	system("CLS");
	printf("��� �� ������� � �������� \"������\"\n\n");
	for (i = 0; i < strok; i++)
	{
		if (kol_vo[i])
		{
			stringp(i);
			printf(" %0.0f ��.\n", kol_vo[i]);
			if ((standprise[i] - prise[i]) != 0)
			{
				printf("  ���� ������ ��� ������: %0.0f ���\n", standprise[i]);
				printf("  ���� ������ �� �������: %0.2f ���\n", prise[i]);
			}
			else 
			{
				printf("  ���� ������: %0.0f ���.\n", standprise[i]);
			}
			printf("  ��������� ������: %0.2f ���\n", prise[i] * kol_vo[i]);
			sum = sum + prise[i] * kol_vo[i];
		}
	}
}
void main() // ����� � ������������ ������ ����������
{
	int i, t;
	unsigned kod;
	float a = 0;
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
		printf("\n���������� ������ - 5%% �� ���� �����\n");
		printf("  ��� ��������� %0.2f ���\n\n", 0.05*sum);
		sum *= 0.95;
	}
	printf("������ ��������� ������ �� ������:\n");
	for (i = 1; i < strok; i++)
	{
		if (skidka[i] != 0)
		{
			stringp(i);
			printf(". ������ ���������� %d%%\n", skidka[i]);
		}
	}
	printf("\n�������� �����: ");
	printf("%0.2f ���\n", sum);
	printf("������� �� ������� � ����� ��������!\n");
	system("pause");
}