#include <bits/stdc++.h>
using namespace std;

int main()
{
    int totalSteps;
    cin >> totalSteps;

    vector<int> steps(totalSteps);
    map<int, int> numberFrequency;
    for (int i = 0; i < totalSteps; i++)
    {
        cin >> steps[i];
        if (i != 0)
        {
            int difference = (steps[i - 1] - steps[i]);
            numberFrequency[difference]++;
        }
    }

    int maxOccurenceDif = -1;
    int maxOccurenceVal = 0;
    for (auto it : numberFrequency)
    {
        if (it.second > maxOccurenceVal)
        {
            maxOccurenceDif = it.first;
            maxOccurenceVal = it.second;
        }
    }

    int firstDif = (steps[0] - steps[1]);
    if (numberFrequency.size() == 2 && firstDif != maxOccurenceDif)
    {  
        cout << 1 << endl;
        return 0;
    }
    else
    {
        for (int j = 1; j < totalSteps; j++)
        {
            int difference = (steps[j - 1] - steps[j]);
            if (difference != maxOccurenceDif)
            {
                cout << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}