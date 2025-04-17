#include <bits/stdc++.h>
using namespace std;

// Function to compare two rocks
bool compare(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string res;
    cin >> res;
    if (res == "x" || res == "-1") exit(0); // Handle invalid responses
    return res == "<"; // true if i is lighter than j
}

// Function to find the lightest rock using tournament method
int tournament_min(vector<int>& elements, vector<int>& losers) {
    while (elements.size() > 1) {
        vector<int> next_round;
        for (size_t i = 0; i + 1 < elements.size(); i += 2) {
            int a = elements[i];
            int b = elements[i + 1];
            if (compare(a, b)) {
                next_round.push_back(a);
                losers.push_back(b);
            } else {
                next_round.push_back(b);
                losers.push_back(a);
            }
        }
        if (elements.size() % 2 == 1)
            next_round.push_back(elements.back());
        elements = next_round;
    }
    return elements[0];
}

void solve(int n) {
    vector<int> result;

    // Initialize all rock labels: 1 to n
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);

    // Find the 1st lightest rock
    vector<int> losers;
    int first = tournament_min(all, losers);
    result.push_back(first);

    // Find 2nd, 4th, 8th, ... lightest rocks
    int rank = 2;
    while (rank <= n) {
        vector<int> cur = losers;
        losers.clear();
        int r = tournament_min(cur, losers);
        result.push_back(r);
        rank *= 2;
    }

    // Output the result
    cout << "! ";
    for (int x : result) cout << x << " ";
    cout << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
