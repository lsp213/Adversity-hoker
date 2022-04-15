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

double* FFT(struct compx* xin)   //FF函数
{
	int f, m, nv2, nml, i, k, l, j = 0;
	static double s[1024];
	struct compx u, w, t;
	nv2 = FFT_N / 2;   //变址运算，即把自然顺序变为倒位序，采用雷德算法
	nml = FFT_N - 1;
	for (i = 0; i < nml; i++)
	{
		if (i < j)     //如果i<j,即进行变址
		{
			t = xin[j];
			xin[j] = xin[i];
			xin[i] = t;
		}
		k = nv2;       //求j的下一个倒位序
		while (k <= j)  //如果k<=j,表示j的最高位为1
		{
			j = j - k; //把最高位变成0
			k = k / 2; //比较次高位，依次类推，逐个比较，直到某个位为0
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
			printf("最高频率为：%d\n", i);
	}
	return s;
}