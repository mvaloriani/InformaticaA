#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 12
#define N 12
int muovi(int m[][N], int i, int j);
void stampa(int m[][N]);
int main() {
	int m[M][N] = { {0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,1,0},
			{0,1,1,1,1,1,1,1,0,1,1,0},
			{0,0,0,0,0,0,0,0,0,1,1,0},
			{0,1,0,1,1,1,1,1,0,1,1,0},
			{0,1,1,0,1,1,1,1,0,1,1,0},
			{0,1,1,0,0,0,1,1,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,1,1,0},
			{0,1,1,0,1,1,0,0,0,1,1,0},
			{0,1,1,0,1,1,1,1,0,1,1,0},
			{0,1,1,0,1,1,1,1,0,1,1,0},
			{0,0,0,0,0,0,0,0,0,0,0,0} };

	stampa(m);

	muovi(m, 5, 5);

	printf("------------------ \n");
	stampa(m);
}
int muovi(int m[][N], int i, int j) {
	if (m[i][j] == 0 || m[i][j] == 2)
		return 0;

	m[i][j] = 2;

	if (m[i][j + 1] == 1)
		muovi(m, i, j + 1);
	if (m[i][j - 1] == 1)
		muovi(m, i, j - 1);
	if (m[i + 1][j] == 1)
		muovi(m, i + 1, j);
	if (m[i - 1][j] == 1)
		muovi(m, i - 1, j);
	return 1;
}
void stampa(int m[][N]) {
	int i, j;
	for (i = 1; i < M - 1; i++) {
		for (j = 1; j < N - 1; j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n\n");
	}
}
