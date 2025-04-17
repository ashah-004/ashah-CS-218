#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    
    while (t){
        int totalLeftMembers = 0;

        int n, r, totalMembers = 0;
        cin >> n >> r;

        vector<int> members(n);
        for(int i = 0; i < n; i++){
            cin >> members[i];
            totalMembers += members[i];
        }

        for (int j = 0; j < members.size(); j++){
            if(members[j] % 2 == 0){
                int rowsOccupied = members[j] / 2;
                r -= rowsOccupied;
            }else{
                totalLeftMembers += members[j] % 2;
                int rowsOccupied = (members[j] - 1) / 2;
                // cout << rowsOccupied << "  ";
                r -= rowsOccupied;
                // cout << r << endl;
            }
            // cout << members[j] << endl;
        }
        // cout << totalLeftMembers << "  " << r << endl;

        int mustShare = 0;
        if (totalLeftMembers > r) {
            int peopleForcedToShare = totalLeftMembers - r;
            mustShare = peopleForcedToShare * 2;
        }
        // cout << "People that must sit together: " << mustShare << endl;
        cout << (totalMembers-mustShare) << endl;
        t--;
    }

    return 0;
}