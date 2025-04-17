#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canDistribute(vector<pair<ll, ll>>& students, ll m) {
    int n = students.size();
    vector<ll> surplus(n);
    for (int i = 0; i < n; ++i)
        surplus[i] = students[i].second - m;

    ll carry = 0;
    for (int i = 0; i < n - 1; ++i) {
        carry += surplus[i];
        ll dist = students[i + 1].first - students[i].first;

        if (carry >= 0) {
            carry = max(0LL, carry - dist);
        } else {
            carry -= dist;
        }
    }
    carry += surplus[n - 1];
    if (carry < 0) return false;

    carry = 0;
    for (int i = n - 1; i > 0; --i) {
        carry += surplus[i];
        ll dist = students[i].first - students[i - 1].first;

        if (carry >= 0) {
            carry = max(0LL, carry - dist);
        } else {
            carry -= dist;
        }
    }
    carry += surplus[0];
    return carry >= 0;
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> students(n);
    ll totalCandies = 0;
    for (int i = 0; i < n; ++i) {
        cin >> students[i].first >> students[i].second;
        totalCandies += students[i].second;
    }

    sort(students.begin(), students.end());

    ll low = 0, high = totalCandies, answer = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canDistribute(students, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
