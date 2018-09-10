#include <stdio.h>
#include <math.h>

	void main()
	{
		float a, b, c, p, s;
		scanf("%f %f %f", &a, &b, &c);
		p = (a + b + c) / 2.0;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("s= %f /n", s);
	}
