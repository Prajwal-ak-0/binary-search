#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> a, int st, int ed, int ele)
{
    while (st <= ed)
    {
        int m = (ed - st) / 2 + st;

        if (a[m] == ele)
        {
            return m + 1;
        }
        else if (a[m] > ele)
        {
            ed = m - 1;
        }
        else
        {
            st = m + 1;
        }
    }

    return -1;
}

int linearSearch(vector<int> a, int ele)
{
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] == ele){
            return i+1;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {12, 16, 19, 21, 25, 29, 33, 35, 37, 39};
    clock_t st, ed;

    st = clock();
    cout<<"Element found at "<<linearSearch(a, 35)<<endl;
    ed = clock();

    cout<<"Time Taken in linear search is : "<<double(ed - st)*1000/CLOCKS_PER_SEC<<endl;

    st = clock();
    cout<<"Element found at "<<binarySearch(a, 0, a.size()-1, 35)<<endl;
    ed = clock();

    cout<<"Time Taken in binary search is : "<<double(ed - st)*1000/CLOCKS_PER_SEC<<endl;
}