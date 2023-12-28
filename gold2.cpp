#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <random>

using namespace std;
typedef long long ll;

int dp[20][1048576];
int t, n;
int helper_fun(int numbe, int mask) {

    if (dp[numbe][mask] != -1) {
        return dp[numbe][mask];
    }
    if (numbe == 0 && mask != 0) {
        return 0;


    }
    int xr = 0, ft = 0, sd = numbe;
    for (int z = 0; z < numbe; ++z) {
        xr += (1 << z);
    }
    for (int u = 0; u < n; ++u) {
        if (helper_fun(numbe - 1, mask ^ xr)) {
            return dp[numbe][mask] = 1;
        }
        xr += (1 << sd);
        xr -= (1 << ft);
        ft++;
        sd++;

        if (sd >= n) {


            sd -= n;
        }
        if (ft >= n) {
            ft -= n;
        }
        
    }
    return dp[numbe][mask] = 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> n;
    for (int i = 0; i < 20; ++i) {


        for (int j = 0; j < (1 << 20); ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;


    for (int q = 0; q < t; ++q) {
        string s1, s2;
        cin >> s1 >> s2;
        int lps = 0, sts = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == '1') {
                lps += (1 << i);
            }
            if (s2[i] == '1') {
                sts += (1 << i);
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (helper_fun(i, lps)) {
                cout << i << "\n";
                break;
            }
            lps ^= sts;
            if (sts & (1 << (n - 1))) {
                sts -= (1 << (n - 1));
                sts = sts << 1;
                sts += 1;
            } else {
                sts = sts << 1;
            }
        }

    }
}
