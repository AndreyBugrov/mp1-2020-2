#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define T 2*pi
#include "all.h"
int proverka(db acc, db x, db Teilor, operation etalon)
{
	if (acc < 0.000001)
		return 1;
	x = etalon(x);
	x -= Teilor;
	if (x < 0.0)
		x *= -1.0;
	return (x > acc) ? 1 : 0;
}
sum polinom(db acc, int count, db x, operation etalon)
{
	long long int i;
	long long fact = 1;//���������
	sum Teilor;//�������� ���� �������
	int (*do_it)(db, db, db, operation) = proverka;
	db n;//��� ���������� (����� ������������ ��������� ������ �����)
	db a;//��������� � ������� �������
	Teilor.count = 0;
	if (etalon == cos || etalon == sin)
	{
		db sec = x;//������ �������� ��� ��� ������������� � ��������
		if (x < 0.0)
		{
			db pix = x * (-1.0);
			while (pix > T)
				pix -= T;
			x = pix * (-1.0);
		}
		else
		{
			while (x > T)
				x -= T;
		}
		if (etalon == cos)
		{
			a = 1;
			n = 0.0;
		}
		else
		{
			n = 1;
			a = x;
		}
		Teilor.s = a;
		for (i = 1, n; i <= count && do_it(acc, sec, Teilor.s, etalon); i++, n += 2.0)
		{
			Teilor.count++;
			a *= ((-1.0) * x * x) / ((n + 1) * (n + 2));
			Teilor.s += a;
		}
	}
	else
	{
		Teilor.s = 1.0;
		a = 1.0;
		if (etalon == exp)
		{
			for (i = 1; i <= count && do_it(acc, x, Teilor.s, etalon); i++)
			{
				Teilor.count++;
				a *= x / i;
				Teilor.s += a;
			}
		}
		else
		{
			const db sec = x + 1.0;//������ �������� ��� ��� ������������� � ��������
			Teilor.count--;
			for (i = 0; i <= count && do_it(acc, sec, Teilor.s, etalon); i++)
			{
				Teilor.count++;
				a *= x * (0.5 - i) / (i + 1);
				Teilor.s += a;
			}
		}
	}
	return Teilor;
}