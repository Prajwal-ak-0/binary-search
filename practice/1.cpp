#include <bits/stdc++.h>

using namespace std;

int useRecursion(int a, int b)
{
    if (b == 0)
        return a;

    return useRecursion(b, a % b);
}

vector<int> getFactors(int a)
{
    vector<int> factors;

    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            factors.push_back(i);
        }
    }

    return factors;
}

int useMiddleSchool(int a, int b)
{
    vector<int> fact_a = getFactors(a);
    vector<int> fact_b = getFactors(b);

    int gcd = 1;

    for (auto i : fact_a)
    {
        if (find(fact_b.begin(), fact_b.end(), i) != fact_b.end())
            gcd = i;
    }

    return gcd;
}

int useConsIntChecking(int a, int b)
{
    int gcd = 1;

    for (int i = 1; i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }

    return gcd;
}

int main()
{
    clock_t st, ed;
    st = clock();
    cout << "GCD of 144 and 96 is : " << useRecursion(144, 96) << endl;
    cout << "GCD of 36 and 32 is : " << useRecursion(36, 36) << endl;
    cout << "GCD of 14 and 26 is : " << useRecursion(26, 14) << endl;
    cout << "GCD of 11 and 7 is : " << useRecursion(11, 7) << endl;
    ed = clock();

    cout << "Time Taken in using Recursion Method is : " << double(ed - st) * 1000 / CLOCKS_PER_SEC << endl;

    st = clock();
    cout << "GCD of 144 and 96 is : " << useMiddleSchool(144, 96) << endl;
    cout << "GCD of 36 and 32 is : " << useMiddleSchool(36, 36) << endl;
    cout << "GCD of 14 and 26 is : " << useMiddleSchool(26, 14) << endl;
    cout << "GCD of 11 and 7 is : " << useMiddleSchool(11, 7) << endl;
    ed = clock();

    cout << "Time Taken in using Middle School Method is : " << double(ed - st) * 1000 / CLOCKS_PER_SEC << endl;

    st = clock();
    cout << "GCD of 144 and 96 is : " << useConsIntChecking(144, 96) << endl;
    cout << "GCD of 36 and 32 is : " << useConsIntChecking(36, 36) << endl;
    cout << "GCD of 14 and 26 is : " << useConsIntChecking(26, 14) << endl;
    cout << "GCD of 11 and 7 is : " << useConsIntChecking(11, 7) << endl;
    ed = clock();

    cout << "Time Taken in using Conecutive Integer Method is : " << double(ed - st) * 1000 / CLOCKS_PER_SEC << endl;
}