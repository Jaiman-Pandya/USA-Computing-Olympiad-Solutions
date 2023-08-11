#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <deque>
#include <ctime>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> usd(5e6 + 1, 0);
    vector <int> primes = { 1 };
    for (int i = 2; i <= 5e6; ++i) {
        if (!usd[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 5e6; j += i) {
                usd[j] = 1;
            }
        }
    }
    vector <int> dp(5e6 + 1, 0);
    vector <int> cnt(5e6 + 1, 0);
    dp[1] = 1;
    cnt[1] = 1;
    int uk = 1;
    for (int i = 2; i <= 5e6; ++i) {
        if (uk + 1 < primes.size() && primes[uk + 1] <= i) {
            uk++;
        }
        if (i % 4 == 0) {
            dp[i] = 0;
        } else {
            dp[i] = 1;
        }
        if (i % 2 == 0) {
            cnt[i] = i / 2;
        } else {
            for (int j = uk; j >= 0; --j) {
                if (dp[i - primes[j]] == 0) {
                    cnt[i] = cnt[i - primes[j]] + 1;
                    break;
                }
            }
        }
    }
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int res = 0;
        int mn1 = 1e9;
        for (int i = 0; i < n; ++i) {
            if ((cnt[a[i]] + 2) / 2 < mn1) {
                mn1 = (cnt[a[i]] + 2) / 2;
                res = dp[a[i]];
            }
        }
        if (res) {
            cout << "Farmer John\n";
        }
        else {
            cout << "Farmer Nhoj\n";
        }
    }

}
