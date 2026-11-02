#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateArrayRec(double* a, const int size, const double Low, const double High, int i = 0)
{
    if (i < size)
    {
        a[i] = Low + static_cast<double>(rand()) / RAND_MAX * (High - Low);
        CreateArrayRec(a, size, Low, High, i + 1);
    }
}

void PrintArrayRec(const double* a, const int size, int i = 0)
{
    if (i < size)
    {
        cout << setw(8) << setprecision(2) << fixed << a[i];
        PrintArrayRec(a, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

int CountInRangeRec(const double* a, const int size, const double A, const double B, int i = 0)
{
    if (i >= size)
        return 0;

    int count = (a[i] >= A && a[i] <= B) ? 1 : 0;
    return count + CountInRangeRec(a, size, A, B, i + 1);
}

int FindMaxIndexRec(const double* a, const int size, int i = 1, int maxIdx = 0)
{
    if (i >= size)
        return maxIdx;

    if (a[i] > a[maxIdx])
        maxIdx = i;

    return FindMaxIndexRec(a, size, i + 1, maxIdx);
}

double SumFromIndexRec(const double* a, const int size, int i)
{
    if (i >= size)
        return 0.0;
    return a[i] + SumFromIndexRec(a, size, i + 1);
}

double SumAfterMaxRec(const double* a, const int size)
{
    int maxIdx = FindMaxIndexRec(a, size);
    return SumFromIndexRec(a, size, maxIdx + 1);
}

void SortEvenInnerRec(double* a, const int size, const int i, int j)
{
    if (j >= size)
        return;

    if (fabs(a[i]) < fabs(a[j]))
    {
        double tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    SortEvenInnerRec(a, size, i, j + 2);
}

void SortEvenIndicesByAbsDescRec(double* a, const int size, int i = 0)
{
    if (i >= size - 2)
        return;

    SortEvenInnerRec(a, size, i, i + 2);
    SortEvenIndicesByAbsDescRec(a, size, i + 2);
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    double A, B;

    cout << "n = "; cin >> n;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;

    if (n <= 0) return 0;

    double* a = new double[n];
    CreateArrayRec(a, n, -20.0, 20.0);

    cout << "\nSformovanyi masiv (Recursive):" << endl;
    PrintArrayRec(a, n);

    int count = CountInRangeRec(a, n, A, B);
    double sum = SumAfterMaxRec(a, n);

    cout << "\n1.1. Kilkist elementiv u diapazoni [" << A << ", " << B << "] = " << count << endl;
    cout << "1.2. Suma elementiv pislya max = " << setprecision(2) << fixed << sum << endl;

    SortEvenIndicesByAbsDescRec(a, n);

    cout << "\n2. Modyfikovanyi masiv (parni pozitsiyi za spadannyam moduliv):" << endl;
    PrintArrayRec(a, n);

    delete[] a;
    return 0;
}