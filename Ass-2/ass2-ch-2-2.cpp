#include <bits/stdc++.h>
using namespace std;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> maleHeights(n), femaleHeights(m);
    for (int i = 0; i < n; i++){
        cin >> maleHeights[i];
    }

    for(int j = 0; j < m; j++){
        cin >> femaleHeights[j];
    }

    sort(maleHeights.begin(), maleHeights.end());
    sort(femaleHeights.begin(), femaleHeights.end());

    int a = 0, b = 0, trios = 0;

    if(maleHeights[n-1] < femaleHeights[1]){
        cout << 0 << endl;
    }else{
        while (a < n && b < m-1){
            if(maleHeights[a] > femaleHeights[b+1]){
                trios++;
                a++;
                b += 2;
            }else{
                a++;
            }
        }
    }


    cout << trios << endl;

    return 0;
}