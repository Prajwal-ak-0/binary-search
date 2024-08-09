#include <bits/stdc++.h>

using namespace std;

void merge(int s, int e, int m, int a[])
{
    vector<int> temp(e - s + 1);

    int i = s;
    int j = m + 1;

    int k = 0;

    while (i <= m && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= m)
    {
        temp[k++] = a[i++];
    }

    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    for (int p = 0; p < k; p++)
    {
        a[s + p] = temp[p];
    }
}

void mergeSort(int s, int e, int a[])
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        mergeSort(s, m, a);
        mergeSort(m + 1, e, a);
        merge(s, e, m, a);
    }
}

int main()
{
    int a[] = {1, 1, 0, 1, 0, 1, 0, 0, 0};
    int n = 9;
    mergeSort(0, n - 1, a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}