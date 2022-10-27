#include <iostream>
#include <cstdlib>
using namespace std;

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, long int left, long int right) //вызов функции: qs(items, 0, count-1);
{
    long int i, j;
    long int x, y;

    i = left; j = right;

    /* выбор компаранда */
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


int main(void)
{
    setlocale(0, "");
    const int n = 4000;
    int a1[n], a2[n], a3[n],
        a4[n], a5[n], a6[n],
        a7[n], a8[n], a9[n],
        a10[n], a11[n], a12[n];


    for (int i = 0; i < n; i++)
    {
        a1[i] = 10 + rand() % 90;
        a2[i] = 10 + rand() % 90;
        a3[i] = 10 + rand() % 90;
    }

    for (int i = 0; i < n; i++)
    {
        a4[i] = i + 1;
        a5[i] = i + 1;
        a6[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        a7[i] = n - i;
        a8[i] = n - i;
        a9[i] = n - i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2) {
            a10[i] = i + 1;
            a11[i] = i + 1;
            a12[i] = i + 1;
        }
        else {
            a10[i] = n - i;
            a11[i] = n - i;
            a12[i] = n - i;
        }


    }
    double time1 = clock();
    shell(a1, n);
    double time2 = clock();
    cout << endl << "Массив рандом №1 shell " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qs(a2, 0, n - 1);
    time2 = clock();
    cout << "Массив рандом №1 qs " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qsort(a3, n, sizeof(int), compare);
    time2 = clock();
    cout << "Массив рандом №1 qsort " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    time1 = clock();
    shell(a4, n);
    time2 = clock();
    cout << endl << "Массив возрастающий №2 shell " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qs(a5, 0, n - 1);
    time2 = clock();
    cout << "Массив возрастающий №2 qs " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qsort(a6, n, sizeof(int), compare);
    time2 = clock();
    cout << "Массив возрастающий №2 qsort " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    time1 = clock();
    shell(a7, n);
    time2 = clock();
    cout << endl << "Массив убывающий №3 shell " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qs(a8, 0, n - 1);
    time2 = clock();
    cout << "Массив убывающий №3 qs " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qsort(a9, n, sizeof(int), compare);
    time2 = clock();
    cout << "Массив убывающий №3 qsort " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    time1 = clock();
    shell(a10, n);
    time2 = clock();
    cout << endl << "Массив возраст/убыв №4 shell " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qs(a11, 0, n - 1);
    time2 = clock();
    cout << "Массив возраст/убыв №4 qs " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    time1 = clock();
    qsort(a12, n, sizeof(int), compare);
    time2 = clock();
    cout << "Массив возраст/убыв №4 qsort " << (time2 - time1) / CLOCKS_PER_SEC << endl;

    return 0;
}
