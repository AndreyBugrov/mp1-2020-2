#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
void main()
{
	/*������ �����:
��������� ������ ������ �� ��� ������� h �� 180 �� 220 ��, ������� w �� 80 �� 120 �� � �������� 5 ��,
��� �������� �� ��� ������� h, �������� d �� 50 �� 90 �� � �������� 15 ��,
��������� ������� � ������ ������ �� ��� ������� w, �������� d � �������� 15 ��,
��� ��������� ����� �� ������ ������� h, ����� ������� w � �������� 1 ��,
���������� ����� � ����� ����� ������ 40 �� �� ���.
������, ��� �������� ��������� ���, ��� � ������, ����� ����� ����� � �����������.*/
	
	int h = 200, l = 100, w = 80, n; // ������ �����, ����� ���������, ������ ���������
	const float dvd = 0.5, dsd = 1.5, ded = 1.0; // ������� ���, ���, ������
	const float dvp = 0.82, dsp = 0.72, dep = 0.69; // ��������� ���, ���, ������ (���)
	float osn, bok, dver, zad, polka, m; // ������ ���������, ������, ������ �����, ����� � ����� ������������ ������ ����� ��� ����� ��������� � ������ �������
	setlocale(LC_ALL, "Russian");
	do
	{
		if (!(h <= 220 && h >= 180 && w >= 50 && w <= 90 && l <= 120 && l >= 80))
			printf("\n������������ ����, ����������, ������� ��� ������ ������\n\n");
		printf("������� ������ ����� � �������� �� 180 �� 220 ��\n");
		scanf("%i", &h);
		printf("������� ����� ��������� ����� � �������� �� 80 �� 120 ��\n");
		scanf("%i", &l);
		printf("������� ������ ��������� ����� (��� ����� ������) � �������� �� 50 �� 90 ��\n");
		scanf("%i", &w);
	} while (!(h <= 220 && h >= 180 && w >= 50 && w <= 90 && l <= 120 && l >= 80));
	n = (h - 3) / 40; // ����� ��� ����� ����������, ����� ���� � ������� (� ��� �����, ��� ��� �����)
	polka = n * dsd * (w-3) * (l - 3);
	//(printf("%f\n", polka); 
	osn = 2 * l * w * dsd;
	//printf("%f\n", osn);
	bok = 2 * (h - 3) * w * dsd;
	//printf("%f\n", bok);
	dver = ded * h * l;
	//printf("%f\n", dver);
	zad = h * l * dvd;
	//printf("%f\n", zad);*/
	m = (polka + bok + osn) * dsp + dver * dep + zad * dvp;
	m /= 1000;
	printf("����� ����� � ����������� �����: %f\n", m);
	system("pause");
}