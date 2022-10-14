#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	system("chcp 1251");

	int i = 0, j = 0, g = 0, col = 7,cch;
	int** amass,** bmass,** cmass;
	printf("введите размер массивов: ");
	scanf_s("%d", &col);
	system("cls");
	amass = (int**)malloc(col * sizeof(int*));
	for (int i = 0; i < col; i++) { amass[i] = (int*)malloc(col * 4); }

	bmass = (int**)malloc(col * sizeof(int*));
	for (int i = 0; i < col; i++) { bmass[i] = (int*)malloc(col * 4); }

	cmass = (int**)malloc(col * sizeof(int*));
	for (int i = 0; i < col; i++) { cmass[i] = (int*)malloc(col * 4); }

	srand(time(NULL));
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++)
		{
			amass[i][j] = rand() % 100 + 1;
		}
	}
	srand(time(NULL));
	for(i=0;i<col;i++)
	{
		for(j=0;j<col;j++)
		{
			bmass[i][j] = rand() % 100 + 1;
		}
	}
	clock_t start = clock();
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++)
		{
			cch = 0;
			for (g = 0; g < col; g++)
			{
				cch = cch + amass[i][g] * bmass[g][j];
				cmass[i][j] = cch;
			}
		}
	}
	clock_t end = clock();
	double ts = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n\n Затрачено времени: %f", ts);
}
