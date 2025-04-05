#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubesequence(vector<int> arr, int numLength) {
    vector<int> dp(numLength, 1);

    for(int i = 1; i < numLength; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    return dp;
}

vector<int> longestDecreasingSubsequence(vector<int> arr, int numLength){
    vector<int> dp(numLength, 1);

    for(int i = numLength-1; i >= 0; i--){
        for(int j = numLength-1; j > i; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp;
}

int main() {
    int numLength;
    cin >> numLength;

    vector<int> arr(numLength);
    for(int i = 0; i < numLength; i++){
        cin >> arr[i];
    }

    vector<int> increasingSequenceResult = longestIncreasingSubesequence(arr, numLength);
    vector<int> decreasingSequenceResult = longestDecreasingSubsequence(arr, numLength);

    int maxLus = 0;
    for(int i = 0; i < numLength; i++){
        maxLus = max(maxLus, increasingSequenceResult[i] + decreasingSequenceResult[i] - 1);
    }

    cout << maxLus << endl;

    return 0;
}