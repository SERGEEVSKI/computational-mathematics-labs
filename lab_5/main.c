#include <stdio.h>
#include <math.h>

float chis(float xarr[10], float yarr[10], int ch, int n, float x) {
        float arr[n];
        int i, j;
	int fm = 0;
        float res = yarr[ch];
        for(i = 0; i < n; i++) {
		if(i != ch) {
                	arr[fm] = x - xarr[i];
			res = res * arr[fm];
			fm++;
		}
	}
        return res;
}

float znam(float xarr[10], int ch, int n) {
        float arr[n];
        int i;
	int fm = 0;
        float res = 1;
        for(i = 0; i < n; i++) {
                 if(i != ch) {
                        arr[fm] = xarr[ch] - xarr[i];
                        res = res * arr[fm];
                        fm++;
                }
        }
        return res;
}

void func(float xarr[10], float yarr[10]) {
	int i;
	for(i = 0; i < 10; i++)
	{
		yarr[i] = sqrt(xarr[i]);
	}
}

void polinom(float xarr[10], float yarr[10], int n, float x, float result) {
	float arr[n];
	int i;
	for(i = 0; i < n; i++) {
		arr[i] = chis(xarr, yarr, i, n, x)/znam(xarr, i, n);
		result = result + arr[i];
	}
	printf("\n\nRESULT IS: %.4f\n", result);
}

int main() {

	float x;
	int stop = 0;
	int i = 0;
	float xarr[10];
	float yarr[10];
	float result = 0;

	printf("Input x: ");
	scanf("%f", &x);

	while(stop != 1 && i != 10) {
		printf("Input point, please: ");
		scanf("%f", &xarr[i]);
		printf("\nDid you want to unput one many point? (0 - Yes, 1 - No) : ");
		scanf("%d", &stop);
		if(stop == 0)
			i++;
		else if(stop != 0 && stop != 1) {
			printf("\nATTENTION: FAILED. PROGRAM WILL BE STOPPED.\n");
			stop = 1;
		}
	}

	func(xarr, yarr);

	polinom(xarr, yarr, i+1, x, result);

	return 0;
}
