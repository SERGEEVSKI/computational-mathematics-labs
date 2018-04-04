#include <stdio.h>

void print(float a[3][3], float b[3])
{
	int i, j;
	printf("\n");
	for(i = 0; i < 3; i++)
        {
                for(j = 0; j < 3; j++)
                {
                        if(a[i][j] >= 0)
                                printf(" %.3f\t", a[i][j]);
                        else
                                printf("%.3f\t", a[i][j]);
                }
                if(b[i] >= 0)
                        printf("|  %.3f\n", b[i]);
                else
                        printf("| %.3f\n", b[i]);
        }

}

int main()
{
	float a[3][3], b[3];
	int i, j;

	a[0][0] =  5; a[0][1] = -1; a[0][2] = -1; b[0] =  3;
	a[1][0] = -1; a[1][1] = -3; a[1][2] =  0; b[1] = -7;
	a[2][0] =  1; a[2][1] =  1; a[2][2] =  4; b[2] =  3;


	print(a, b);

	return 0;
}
