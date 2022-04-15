#ifndef FFT_H

#define FFT_H 

#include<stdio.h>
#include<math.h>
#include<time.h>

struct compx { double real, imag; };

double* FFT(struct compx* xin);
/*void main()
{
	int i;
	for (i = 0; i < FFT_N; i++)
	{
		s[i].real = 54 * sin(2 * PI * 120 * i / FFT_N) + 54 * sin(2 * PI * 300 * i / FFT_N);;
		s[i].imag = 0;
	}
	FFT(s);
	long start = clock();
	for (i = 0; i < FFT_N; i++)
	{
		s[i].real = sqrt(s[i].real * s[i].real + s[i].imag * s[i].imag);
		if ((s[i].real > 50) && (i < 500))
			printf("最高频率为：%d\n", i);
	}
	long end = clock();
	long t = end - start;
	printf("%d\n", t);
}
*/

#endif
