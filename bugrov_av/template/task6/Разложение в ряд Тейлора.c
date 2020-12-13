/*����������� ���������, ����������� ��������� ������ �������� ��� ���������� ������ ������� � �������� ����� � �������� ������������ �� ���� ���������� ���� ������� � ��� �������.

��������� ������ �������� � ���� ������� :
����������� ������ ������� � �������� �����.
�������� �����������.
��� ������ � ������ 1 ������������ ������ ����� ����������� :

������� �������,
������ ����� x, � ������� ���������� ��������� ��������,
������ �������� ����������(>= 0.000001),
������ ����� ��������� ���� ��� ���������� �������(N - �� 1 �� 1000).
������ ������ �������� ��������� ������� ����������� ���� �� ���������� �������� ��������, ���� �� ���������� ���������� ����� ���������.�� ����������� ������� ��������� ������ ������� ��������� ���������� :

��������� ��������(���������� � �������������� ���������� �������������� ������� ����� ���������������� �),
����������� ������ �������� �������,
������� ����� ������� � ��������� ���������,
���������� ���������, ������� ���� ���������.
��� ������ � ������ 2 ������������ ������ ����� ����������� :

������� �������,
������ ����� x, � ������� ���������� ��������� ��������,
������ ����� �������������(NMax - �� 1 �� 25).
�� ����������� ������� ��������� ������ ������� ��������� ���������� :

��������� ��������(���������� � �������������� ���������� �������������� ������� ����� ���������������� �),
������� �� NMax ����� �� ���������� ��������� : ��� - �� ���������(�� 1 �� NMax), ����������� ������ �������� �������, ������� ����� ������� � ��������� ���������.
����������� ���������� :

������ ������� ������ ����������� ������ ������� sin(x), cos(x), exp(x) � ����� ���������� ������� �� ������ ����.����� ��������� ������� ��������� � ������� � ������ ������.
�� ������� ����� ������� �������������� �������, ����� 4 - � ������������.
������ ������� ������ ���� ���������� � ���� ������� ����� �.
� ��������� ������ ���� ����������� ��� ��������� �� �������.
� ��������� ���������� ������������ ������.
���������� ������� :
1���������� ������ �� 1 + � - (1 + x) ^ (1 / 2)////////////////////////
2�������� �� 1 + � - ln(1 + x)
3������� - tg(x)
4��������� - ctg(x)
5�������� - arcsin(x)
6���������� - arccos(x)
7���������� - arctg(x)
8������������ - arcctg(x)
9��������������� ����� - sh(x)
10��������������� ������� - ch(x)
11��������������� ������� - th(x)
12��������������� ��������� - cth(x)
13�������� ��������������� ����� - arsh(x)
14�������� ��������������� ������� - arth(x)
15������ - sec(x)
16�������� - csc(x)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/// <summary>
/// �������� ������ /////////////////////////////////////////////////////////////////////////////////////////////////////////
/// (������� ������ ��� �����, Enter, ����� ������ ������� �� ������� �� ������)
/// </summary>
/// 
#define MIN 0.000001
#include "Calculating.h"
void menu();
void mode1();
void mode2();
void mode(int);
//int proverka();
typedef double db;
typedef db(*operation)(db);
//db polinom();
int cleaner();
int cleaner();
db db_cleaner();
operation choice();
void printer();
void head(double, operation);


void main()
{	/// <summary>
	/// 
	/// </summary>
	/// 
	setlocale(LC_ALL, "Russian");
	printf("�� ����� � ���������, �������������� ������� � ��� �������\n");
	menu();
	system("pause");
}
db db_cleaner()
{
	db ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%lf", &ans);
		if ((!clean) || ans < MIN)
			printf("������ �����\n");
	} while (getchar() != '\n' && !clean && ans < MIN);
	return ans;
}
int cleaner(int min, int max)
{
	int ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%d", &ans);
		if (!clean && (ans<min || ans>max))
			printf("������ �����\n");
	} while (getchar() != '\n' && !clean && (ans<min || ans>max));
	return ans;
}
void menu()
{
	int away;
	int ans;//����� ������������
	printf("\n");
	printf("�������� �����: \n1 - ����������� ������ �������\n");
	printf("2 - �������� �����������\n");
	printf("0 - ����� �� ���������\n");
	ans = cleaner(0, 2);
	do {
		away = 0;
		switch (ans)
		{
		case 0:
			printf("�� ����� �������, ��� ������ �����?\n");
			printf("���� ��, �� ������� 0");
			printf(", ���� ���, �� ������� ����� ������ ������\n");
			ans = cleaner(-128, 256);
			if (!ans)
				printf("����� �������, �������� ����������!\n");
			else
				away++;
			break;
		case 1:
			printf("�� ������� ������ �����\n");
			mode(1);
			//mode1();
			break;
		case 2:
			printf("�� ������� ������ �����\n");
			mode(2);
			//mode2();
			break;
		}
	} while (away);
}
operation choice()
{
	int ans;//����� ������������
	db(*funk)(db)= NULL;//����� ��������� ��������
	printf("�������� ����� �������, ������� ������� ���������:\n");
	printf("1 - �������\n");
	printf("2 - �����\n");
	printf("3 - ���������� (e^x) \n");
	printf("4 - ���������� ������ �� 1+�\n");
	printf("0 - ����� � ����\n");
	ans = cleaner(0, 4);
	switch (ans)/////////////////////////////////
	{
	case 0:
		printf("\n");
		menu();
		break;
	case 1:
		printf("\n");
		funk = cos;
		break;
	case 2:
		printf("\n");
		funk = sin;
		break;
	case 3:
		printf("\n");
		funk = exp;
		break;
	case 4:
		printf("\n");
		funk = sqrt;
		break;
	}
	return funk;
}
void mode(int a)
{
	db acc;// �������� ���������� (����� ������������ � ���� ��������, ������� �������)
	int count;//���������� ���������
	db x;//�������� �������
	operation funk = NULL;//��������� ��������� ������� ��� ������ �����������
	db res;//��������� ���������� ����
	int nmax;//������������ ����� ���������
	a--;
	funk = choice();
	printf("������� ����� �, � ������� ����� ��������� �������\n");
	x = db_cleaner();
	if (a)
	{
		printf("\n");
		printf("������� ����� �������������\n");
		nmax = cleaner(1, 25);
		head(x, funk);
		for (count = 1; count <= nmax; count++)
		{
			res = polinom(0.0, count, x, funk);
			printer(count, x, res, funk);
		}/////////////////////
	}
	else
	{
		printf("������� �������� ���������� � ���� ���������� ����� �� 0.000001\n");
		acc = db_cleaner();
		printf("������� ���������� ��������� ���� � ���� ������ ����� �� 1 �� 1000\n");
		count = cleaner(1, 1000);
		res = polinom(acc, count, x, funk);
		head(x, funk);
		printer(count, x, res, funk);
	}
}
db polinom(db acc, int count, db x, db(*etalon)(db))
{
	long long int i;
	long long fact = 1;//���������
	long double Teilor;//�������� ���� �������
	int (*do_it)(db, db, db, db(*etalon)(db)) = proverka;
	db* elem;
	elem = (db*)malloc(sizeof(db) * (count+1));
	elem[0] = 1;
	if (etalon == cos || etalon == sin)
	{
		const db x2 = x * x;//��� ��������� ���^k �� ��� �� ������
		long long n;//��� ����������
		if (etalon == cos)
		{
			x = 1;
			n = 0;
		}
		else
		{
			n = 1;
		}
		Teilor = x;
		if (acc != 0.0)
			for (i = 1; i < count && proverka(acc, x, Teilor, etalon); i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (long double)fact;
			}
		else
			for (i = 1; i < count; i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (db)fact;
			}
	}
	else
	{
		Teilor = 1.0;
		const db x1 = x;
		if (etalon == exp)
		{
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++)
				{
					fact *= i;
					x *= x1;
					Teilor = Teilor + x / (long double)fact;
					//Teilor = Teilor + x / fact;
					printf("Teilor=%lf\n", Teilor);/////////////////////////////////////////////////////////////////////////
				}
			else
				for (i = 1; i <= count; i++)
				{
					//fact *= i;
					// x *= x1;
					elem[i]= (elem[i - 1] * x) / (i+1);
					//Teilor = Teilor + elem[i];//x / (long double)fact;
				}
			for(i=0;i<=count;i++)
				Teilor = Teilor + elem[i];
			free(elem);
		}
		else
		{
			long long difact = -1;//��������� ���������� �����
			long long chet = 1;//��� � ����������� � ���� 4 i-��� �������
			long long znam;//�����, ������ � �����������
			long long fact2 = 1;//������� ����������
			long long n = 2;//��� ����������
			//Full �������: ((-1)^i * (2i)! * x^i) / ((1-2i) * (i!)^2 * (4^i)), 0<=i<=n
//Small �������: (difact * x) / (znam * fact2 * chet);
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					//Teilor += (x * difact) / (znam * fact2 * chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
			else
				for (i = 1; i < count; i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					//Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
		}
	}
	return Teilor;
}
int proverka(db acc, db x, db Teilor, db(*etalon)(db))
{
	db x1 = x;
	if (etalon != sqrt)
		x1 = etalon(x);
	else
		x1 = etalon(x + 1.0);
	x1 -= Teilor;
	if (x1 < 0.0)
		x1 *= -1.0;
	//printf("x1=%lf\n", x1);
	return (x1 > acc) ? 1 : 0;
}
void printer(int count,db x, db Teilor, db(*etalon)(db))////////////////////////////////////////////������� �������
{
	int i;
	db module;// ������ �������� ���������� �������� � ������ �������� �������
	int sec = count;//��� ������� �������
	if (etalon != sqrt)
		module = etalon(x);
	else
		module = etalon(1 + x);
	module -= Teilor;
	if (module < 0.0)
		module *= -1;
	for (i = 0; i < 5; i++)
		printf(" ");
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%d", count);/////////////////////////////////������� ��������� count
	for (sec = 0; sec < 6 - i; sec += 2)
		printf(" ");
	if (!(sec % 2))
		printf(" ");
	if (Teilor < 0.0)
		sec = 9;
	else
		sec = 10;
	for (i = 0; i < sec; i++)
		printf(" ");
	sec = (int)Teilor;
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%0.6lf", Teilor);/////////////////////////////////������� ��������� Teilor
	for (i = 0; i < 13; i++)
		printf(" ");////////////////////////////////////////////////////������� �������
	printf("%-1.6lf", module);
	printf("\n");
}
void head(double x, operation funk)
{
	int i;
	printf("\n��������� ��������, ����������� ���������������: ");
	printf("%lf\n\n", funk(x));
	printf("����� ���������");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("�������� ����");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("������ ��������");
	printf("\n");
	for (i = 0; i < 23; i++)
		printf(" ");
	printf("�������");
	for (i = 0; i < 8; i++)
		printf(" ");
	printf("���� � �������");
	printf("\n");
}