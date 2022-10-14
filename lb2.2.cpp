#include <iostream>
#include <time.h>
#include <stdlib.h>

void shell(int* array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}

    void qs(int* items, int left, int right)
    {
        int i, j;
        int x, y;

        i = left; j = right;
        x = items[(left + right) / 2];
        do {
            while ((items[i] < x) && (i < right)) i++;
            while ((x < items[j]) && (j > left)) j--;

            if (i <= j) {
                y = items[i];
                items[i] = items[j];
                items[j] = y;
                i++; j--;
            }
        } while (i <= j);

        if (left < j) qs(items, left, j);
        if (i < right) qs(items, i, right);
    }

    int compare(const void* x1, const void* x2)
    {
        return (*(int*)x1 - *(int*)x2);
    }

    int main()
    {
        system("chcp 1251");
        int col,j;
        int chs;
        printf("введите размер: ");
        scanf_s("%d", &col);
        system("cls");
        printf("вибери тип:\n1)рандомный\n2)возрастающий\n3)убывающий\n4)треугольный\n");
        scanf_s("%d", &chs);
        system("cls");
        if (chs == 1) { printf("рандомный\n"); }
        if (chs == 2) { printf("возрастающий\n"); }
        if (chs == 3) { printf("убывающий\n"); }
        if (chs == 4) { printf("треугольный\n"); }
        int* mass = (int*)malloc(col * sizeof(int));
            if (chs == 1) 
            { 
                for (int i = 0; i < col; i++)
                {
                    mass[i] = rand() % 1000;
                }
            }
            if (chs == 2) 
            {
                for (int i = 0; i < col; i++)
                {
                    mass[i] = i;
                }
            }
            if (chs == 3) 
            {
                for (int i = 0; i < col; i++)
                {
                    mass[i] = col - 1;
                }
            }
            if (chs == 4)
            {
                for (int i = 0; i <= col / 2; i++)
                {
                    mass[i] = i;
                    j = i;
                }
                for (int i = j; i < col; i++)
                {
                    j--;
                    mass[i] = j;
                }
            }
        clock_t start = clock();
        shell(mass, col);
        clock_t end = clock();
        double ts = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nЗатрачено времени(shell): %f\n", ts);
            if (chs == 1)
            {
                for (int i = 0; i < col; i++)
                {
                    mass[i] = rand() % 1000;
                }
            }
        if (chs == 2)
        {
            for (int i = 0; i < col; i++)
            {
                mass[i] = i;
            }
        }
        if (chs == 3)
        {
            for (int i = 0; i < col; i++)
            {
                mass[i] = col - 1;
            }
        }
        if (chs == 4)
        {
            for (int i = 0; i <= col / 2; i++)
            {
                mass[i] = i;
                j = i;
            }
            for (int i = j; i < col; i++)
            {
                j--;
                mass[i] = j;
            }
        }
        start = clock();
        qs(mass, 0, col - 1);
        end = clock();
        ts = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nЗатрачено времени(qs): %f\n", ts);
            if (chs == 1)
            {
                for (int i = 0; i < col; i++)
                {
                    mass[i] = rand() % 1000;
                }
            }
        if (chs == 2)
        {
            for (int i = 0; i < col; i++)
            {
                mass[i] = i;
            }
        }
        if (chs == 3)
        {
            for (int i = 0; i < col; i++)
            {
                mass[i] = col - 1;
            }
        }
        if (chs == 4)
        {
            for (int i = 0; i <= col / 2; i++)
            {
                mass[i] = i;
                j = i;
            }
            for (int i = j; i < col; i++)
            {
                j--;
                mass[i] = j;
            }
        }
        start = clock();
        qsort(mass, col,sizeof(int),compare);
        end = clock();
        ts = (double)(end - start) / CLOCKS_PER_SEC;
        printf("\nЗатрачено времени(qsort): %f\n", ts);

    }