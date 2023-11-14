#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

int FindMax(int** a, const int k, const int colNo, const int row = 0, int maxInCol = INT_MIN)
{
    if (row < k)
    {
        if (a[row][colNo] > maxInCol)
        {
            maxInCol = a[row][colNo];
        }
        return FindMax(a, k, colNo, row + 1, maxInCol);
    }
    return maxInCol;
}

int FindMinOfMax(int** a, const int k, const int n, const int col = 0, int minOfMax = INT_MAX)
{
    if (col < n)
    {
        int maxInCol = FindMax(a, k, col);
        if (maxInCol < minOfMax)
        {
            minOfMax = maxInCol;
        }
        return FindMinOfMax(a, k, n, col + 2, minOfMax);
    }
    return minOfMax;
}

int main()
{
    srand((unsigned)time(NULL));
    int k, n;
    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;
    cout << endl;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    int Low = -21, High = 24;
    CreateRows(a, k, n, Low, High, 0);
    PrintRows(a, k, n, 0);

    int minOfMax = FindMinOfMax(a, k, n);
    cout << "Result: " << minOfMax << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}