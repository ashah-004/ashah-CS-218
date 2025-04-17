#include <bits/stdc++.h>
using namespace std;

int main () {
    int m;
    cin >> m;

    vector<int> prices(9);

    int minPrice = INT_MAX;
    for(int i = 0; i < 9; i++){
        cin >> prices[i];
        minPrice = min(minPrice, prices[i]);
    }

    // cout << minPrice << "  " << maxNumber << endl;

    int maxDigits = floor(m/minPrice);

    // cout << maxDigits << endl;
    // int ans;
    while(maxDigits){

        for(int j = 8; j >= 0; j--){
            int remainingMoney = m - prices[j];
            int minRequiredMoney = ((maxDigits - 1)*minPrice);
            // cout << remainingMoney << "  " << minRequiredMoney << endl;
            if(remainingMoney >= minRequiredMoney){
                cout << j+1;
                m -= prices[j];
                break;
            }
        }

        maxDigits--;
    }

    // cout << ans << endl;

    return 0;
}