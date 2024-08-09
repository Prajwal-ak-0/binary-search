#include <bits/stdc++.h>

using namespace std;

int partition(int s, int e, int a[]) {
    int pivot = a[s];
    int pIndex = s;

    for (int i = s + 1; i <= e; i++) {
        if (a[i] <= pivot) {
            pIndex++;
            swap(a[i], a[pIndex]);
        }
    }
    swap(a[s], a[pIndex]);
    return pIndex;
}

void quickSort(int s, int e, int a[]) {
    if (s >= e) return;

    int p = partition(s, e, a);
    quickSort(s, p - 1, a);
    quickSort(p + 1, e, a);
}

int main() {
    int a[] = {1, 1, 0, 1, 0, 1, 0, 0, 0};
    int n = 9;
    quickSort(0, n - 1, a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
