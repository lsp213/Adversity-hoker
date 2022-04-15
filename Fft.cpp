#include<stdio.h>
#include<math.h>
#include<time.h>
#include"Fft.h"

#define PI (double)3.1415926533589793
#define FFT_N (int)1024
struct compx EE(struct compx a, struct compx b)
{
	struct compx c;
	c.real = a.real * b.real - a.imag * b.imag;
	c.imag = a.real * b.imag + a.imag * b.real;
	return (c);
}

double* FFT(struct compx* xin)   //FF����
{
	int f, m, nv2, nml, i, k, l, j = 0;
	static double s[1024];
	struct compx u, w, t;
	nv2 = FFT_N / 2;   //��ַ���㣬������Ȼ˳���Ϊ��λ�򣬲����׵��㷨
	nml = FFT_N - 1;
	for (i = 0; i < nml; i++)
	{
		if (i < j)     //���i<j,�����б�ַ
		{
			t = xin[j];
			xin[j] = xin[i];
			xin[i] = t;
		}
		k = nv2;       //��j����һ����λ��
		while (k <= j)  //���k<=j,��ʾj�����λΪ1
		{
			j = j - k; //�����λ���0
			k = k / 2; //�Ƚϴθ�λ���������ƣ�����Ƚϣ�ֱ��ĳ��λΪ0
		}
		j = j + k;

	}
	{
		int d, dl, ip;
		f = FFT_N;
		for (l = 1; (f = f / 2) != 1; l++);
		for (m = 1; m <= l; m++)
		{
			d = 2 << (m - 1);
			dl = d / 2;
			u.real = 1.0;
			u.imag = 0.0;
			w.real = cos(PI / dl);
			w.imag = -sin(PI / dl);
			for (j = 0; j <= dl - 1; j++)
			{
				for (i = j; i <= FFT_N - 1; i = i + d)
				{
					ip = i + dl;
					t = EE(xin[ip], u);
					xin[ip].real = xin[i].real - t.real;
					xin[ip].imag = xin[i].imag - t.imag;
					xin[i].real = xin[i].real + t.real;
					xin[i].imag = xin[i].imag + t.imag;
				}
				u = EE(u, w);
			}
		}
	}
	for (i = 0; i < FFT_N; i++)
	{
		s[i] = sqrt(xin[i].real *xin[i].real + xin[i].imag * xin[i].imag);
		if ((s[i]> 50) && (i < 500))
			printf("���Ƶ��Ϊ��%d\n", i);
	}
	return s;
}