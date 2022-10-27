#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
    setlocale(0, "");
    srand(time(NULL));
    int num;
    cout << "Введите количество элеменетов matrix: ";
    cin >> num;
    int k = num;

    int** a = new int* [num];
    for (int i = 0; i < num; i++)
    {
        a[i] = new int[k];
    }

    int** b = new int* [num];
    for (int i = 0; i < num; i++)
    {
        b[i] = new int[k];
    }

    int** c = new int* [num];
    for (int i = 0; i < num; i++)
    {
        c[i] = new int[k];
    }

    for (auto i = 0; i < num; i++)
        for (auto j = 0; j < num; j++)
            a[i][j] = 1 + rand() % 5;

    for (auto i = 0; i < num; i++)
        for (auto j = 0; j < num; j++)
            b[i][j] = 1 + rand() % 5;

    double time1 = clock();
    for (auto i = 0; i < num; i++) {
        for (auto j = 0; j < num; j++) {
            c[i][j] = 0;
            for (auto y = 0; y < num; y++) {
                c[i][j] += a[i][y] * b[y][j];
            }
        }
    }
    double time2 = clock();

    cout << "Время умножения: " << (time2 - time1) / 1000.0 << endl;
    cout << endl << "Время выполнение програмы: " << clock() / 1000.0;
    cin.get();
    return 0;
}
