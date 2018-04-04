#include <stdio.h>
#include <math.h>

void print(float a[3][3], float b[3])
{
	int i, j;
	printf("\n");
	for(i = 0; i < 3; i++)
        {
                for(j = 0; j < 3; j++)
                {
                        if(a[i][j] >= 0)
                                printf(" %.2f\t", a[i][j]);
                        else
                                printf("%.2f\t", a[i][j]);
                }
                if(b[i] >= 0)
                        printf("|  %.2f\n", b[i]);
                else
                        printf("| %.2f\n", b[i]);
        }

}

void udvid(float a[3][3], float b[3])
{
	int i, j;
	float var = 0;
	for(i = 0; i < 3; i++)
	{
		var = a[i][i];
		for(j = 0; j < 3; j++)
		{
			a[i][j] = a[i][j] / var;
		}
		b[i] = b[i] / var;
		var = 0;
	}
}

void razb(float a[3][3])
{
	int i;
	for(i = 0; i < 3; i++)
	{
		a[i][i] = 0;
	}
}

void norma(float a[3][3], float b[3])
{
	float q, w, e, r;

	q = fabs(a[0][1]) + fabs(a[0][2]);
	w = fabs(a[1][0]) + fabs(a[1][2]);
	e = fabs(a[2][0]) + fabs(a[2][1]);

	if(q >= w && q >= e)
		r = q;
	else if(w >= q && w >= e)
		r = w;
	else if(e >= q && e >= w);
		r = e;

	printf("\n");

	printf("||C||inf = max(|%.2f| + |%.2f| ; |%.2f| + |%.2f| ; |%.2f| + |%.2f|) = %.2f\n", a[0][1], a[0][2], a[1][0], a[1][2], a[2][0], a[2][1], r);

	q = 0; w = 0; e = 0;
	q = fabs(b[0]);
        w = fabs(b[1]);
        e = fabs(b[2]);

        if(q >= w && q >= e)
		r = q;
	else if(w >= q && w >= e)
		r = w;
	else if(e >= q && e >= w)
		r = e;

	printf("||B||inf = max(|%.2f| ; |%.2f| ; |%.2f|) = %.2f\n", b[0], b[1], b[2], r);
}

void firststep(float b[3])
{
	printf("\n\t|0|\n  X0 =\t|0|\n\t|0|\n\n");
	printf("\t|%.2f|\n  X1 =\t|%.2f|\n\t|%.2f|\n", b[0], b[1], b[2]);
}

int main()
{
	float a[3][3], b[3];

	a[0][0] =  5; a[0][1] = -1; a[0][2] = -1; b[0] =  3;
	a[1][0] = -1; a[1][1] = -3; a[1][2] =  0; b[1] = -7;
	a[2][0] =  1; a[2][1] =  1; a[2][2] =  4; b[2] =  3;

	print(a, b);

	udvid(a, b);

	print(a, b);

	razb(a);

	print(a, b);

	norma(a, b);

	firststep(b);

	return 0;
}
