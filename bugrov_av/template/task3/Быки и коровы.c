#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*����������� ���������, ����������� ���� ����� � �������.
����������(�������)
������ ��� ������(������� � ���������).
����� �������� ����� ������������� ����� � n(�� 2 �� 5). proverit'
��������� ����������� n - ������� ����� � ���������������� �������.
����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������.
��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����(�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� �����(�� ���� ���������� �����).
����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.
������
����� n = 4.
����� �������� ����� �3219�.
����� ���� ����� �2310�.
���������: ��� ��������(��� ����� : �2� � �3� � ������� �� �������� ��������) � ���� ����(���� ����� �1� ������� ������ �� �������). switch switch*/
#define num 5
void main()
{
	char c;
	int n, i = 0, igrok, t; // n ������ � �����; i - �������; igrok - ����� ������; t - �������������� �������; 
	unsigned short zagad[num] = { 0 }, x, p[num] = { 0 }, bik = 0, kor = 0; // zagad - ���������� ����������� �����; x - ��������� �����; p ���������������� �����; bik - ����� �����; kor  - ����� �����;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("������� ������� � ���� \"���� � ������\"\n");
	printf("������� ���������� ���� � �����\n");
nachalo: 
	scanf("%d", &n);
	if (n < 2 || n > 5)
	{
		printf("�� ����� ������������ �����, ������� �����\n");
		goto nachalo;
	}
	zagad[i] = rand() % 9 + 1;	
	for (i = 1; i < n; i++) // ��������� �����
	{
	met1:
		x = rand() % 10; // �������� ��������� �����
		zagad[i] = x;
		for (t = 0; t < i; t++)
		{
			if (zagad[i] == zagad[t]) // �������� �� ��������� 
				goto met1;
		}
	}
	do
	{ 
		printf("������� �����\n");
		scanf("%d", &igrok);
		for (i = 0; i < n; i++)
		{
			p[n-1-i] = igrok % 10;
			igrok /= 10;
		}
		for (i = 0; i < n; i++) // �������� �������� � ������ ������������
		{
			if (zagad[i] == p[i]) // ��� ������� �������� (����� � �����)
				bik++;
			else
			{
				for (t = 0; t < n; t++)
				{
					if (zagad[i] == p[t]) // �������� ������ �����
					{
						kor++;
						break;
					}

				}
			}
		}
		if (bik < n)
		{
			switch (bik)
			{
			case 0: case 5:
				switch (kor)
				{
				case 0: case 5:
					printf("%d ����� � %d �����\n", bik, kor);
					break;
				case 1:
					printf("%d ����� � %d ������\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d ����� � %d ������\n", bik, kor);
					break;
				}
				break;
			case 1:
				switch (kor)
				{
				case 0: case 5:
					printf("%d ��� � %d �����\n", bik, kor);
					break;
				case 1:
					printf("%d ��� � %d ������\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d ��� � %d ������\n", bik, kor);
					break;
				}
				break;
			case 2: case 3: case 4:
				switch (kor)
				{
				case 0: case 5:
					printf("%d ���� � %d �����\n", bik, kor);
					break;
				case 1:
					printf("%d ���a � %d ������\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d ���a � %d ������\n", bik, kor);
					break;
				}
				break;
			}
			/*for (i = 0; i < n; i++)
			{
				printf("%d", zagad[i]);
				
			}
			printf("\n");
			for (i = 0; i < n; i++)
			{
				printf("%d", p[i]);
			}
			printf("\n");
			*/
			bik = 0;
			kor = 0;
		}
		else
		{
			c = ' ';
			printf("� ��� ���������� �����!");
			printf("�� ��������, ����������!\n");
			printf("�� �������� ����� �������� � �������� ������ ���� � ��� ����� ������������� ����\n");
			break;
		}
		printf("���� �� �������, ������� ������, � ����� ������ ������ ���������� ����\n");
		c = getch();
	} while (c != ' ');
	if (bik < n)
	{
		printf("��� ���� ����� ");
		for (i = 0; i < n; i++)
		{
			printf("%d", zagad[i]);
		}
		printf("\n");
	}
	system("pause");
}