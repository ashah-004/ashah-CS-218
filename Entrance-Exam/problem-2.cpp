#include <bits/stdc++.h>
using namespace std;

long long findLength(int k)
{
    if (k == 1)
        return 3;
    return 2 * findLength(k - 1) + 3;
}

char findChar(int k, long long i)
{
    if (k == 1)
    {
        return "ABC"[i - 1];
    }

    long long size = findLength(k - 1); 

    if (i == 1)
        return 'A'; 
    if (i <= size + 1)
        return findChar(k - 1, i - 1); 
    if (i == size + 2)
        return 'B'; 
    if (i <= 2 * size + 2)
        return findChar(k - 1, i - size - 2);
    return 'C';                            
}

int main()
{
    int totalTests;
    cin >> totalTests;
    while (totalTests--)
    {
        int k;
        long long l, r;
        cin >> k >> l >> r;

        string result;
        for (long long i = l; i <= r; i++)
        {
            result += findChar(k, i);
        }

        cout << result << '\n';
    }

    return 0;
}
