#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "Types.h"
#include "Calculating.h"
db db_cleaner(db min)
{
	db ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%lf", &ans);
		if ((!clean) || ans < min)
			printf("������ �����\n");
	} while (getchar() != '\n' || !clean || ans < min);
	return ans;
}
int cleaner(int min, int max)
{
	int ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%d", &ans);
		if (!clean || ans<min || ans>max)
			printf("������ �����\n");
	} while (getchar() != '\n' || !clean || ans<min || ans>max);
	return ans;
}
operation choice()
{
	int ans;//����� ������������
	db(*funk)(db) = NULL;//����� ��������� ��������
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
		main();
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
	sum res;//��������� ���������� ����
	int nmax;//������������ ����� ���������
	a--;
	if (a)
		printf("\n�� ������� ������ �����\n");
	else
		printf("\n�� ������� ������ �����\n");
	funk = choice();
	printf("������� ����� �, � ������� ����� ��������� �������\n");
	if (funk == sqrt)
		x = db_cleaner(-1.0);
	else
		x = db_cleaner(-10000000.0);
	if (a)
	{
		printf("\n");
		printf("������� ����� �������������\n");
		nmax = cleaner(1, 25);
		head(x, funk);
		for (count = 1; count <= nmax; count++)
		{
			res = polinom(0.0, count, x, funk);
			printer(count, x, res.s, funk);
		}
	}
	else
	{
		printf("������� �������� ���������� � ���� ���������� ����� �� 0.000001\n");
		acc = db_cleaner(-100.0);
		printf("������� ���������� ��������� ���� � ���� ������ ����� �� 1 �� 1000\n");
		count = cleaner(1, 1000);
		res = polinom(acc, count, x, funk);
		head(x, funk);
		printer(res.count, x, res.s, funk);
	}
}