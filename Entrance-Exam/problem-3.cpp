// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> candies(n);
//     vector<int> occurences(3);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> candies[i];
//         occurences[candies[i] - 1]++;
//     }

//     int i = 0, j, swapCount = 0;
//     while (i < (occurences[0] + occurences[1]))
//     {
//         j = n - 1;
//         if (i < occurences[0] && candies[i] != 1)
//         {
//             while (j > i && candies[j] != 1)
//             {
//                 j--;
//             }
//             swap(candies[i], candies[j]);
//             swapCount++;
//         }
//         else if (i >= occurences[0] && i < (occurences[0] + occurences[1]) && candies[i] != 2)
//         {
//             while (j > i && candies[j] != 2)
//             {
//                 j--;
//             }
//             swap(candies[i], candies[j]);
//             swapCount++;
//         }
//         i++;
//     }

//     cout << swapCount << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> candies(n);
    vector<int> count(4, 0); 

    for (int i = 0; i < n; i++) {
        cin >> candies[i];
        count[candies[i]]++; 
    }

    int firstEnd = count[1];                 
    int secondEnd = firstEnd + count[2];     

    int oneInTwo = 0, oneInThree = 0;
    int twoInOne = 0, twoInThree = 0;
    int threeInOne = 0, threeInTwo = 0;

    for (int i = 0; i < firstEnd; i++) {
        if (candies[i] == 2) oneInTwo++;
        if (candies[i] == 3) oneInThree++;
    }
    for (int i = firstEnd; i < secondEnd; i++) {
        if (candies[i] == 1) twoInOne++;
        if (candies[i] == 3) twoInThree++;
    }
    for (int i = secondEnd; i < n; i++) {
        if (candies[i] == 1) threeInOne++;
        if (candies[i] == 2) threeInTwo++;
    }

    int swaps = min(oneInTwo, twoInOne) +
                min(oneInThree, threeInOne) +
                min(twoInThree, threeInTwo);

    int remaining = (abs(oneInTwo - twoInOne) +
                     abs(oneInThree - threeInOne) +
                     abs(twoInThree - threeInTwo)) / 3;
    
    swaps += remaining * 2;

    cout << swaps << endl;
    return 0;
}