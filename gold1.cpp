#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

int g[200001][26];
vector <long long> dp;
vector <string> a;

long long cnt_dp(int v) {
    if (dp[v] != -1) {
        return dp[v];
    }
    int sm = 0; 
    for (int i = 0; i < 26; ++i) {
        if (g[v][i] != 0) {
            sm++;
        }
    }
    if (sm) {
        long long cn = 0;
        for (int j = 0; j < a[v].size(); ++j) {
            if (g[v][a[v][j] - 'a']!=0) {
                cn+=cnt_dp(g[v][a[v][j] - 'a']);
            }
            else {
                cn++;
            }
            if (cn >= 1e18) {
                cn = 1e18;
                break;
            }
        }
        if (a[v].size() == 1 && cn == 1) {
            for (int i = 0; i < 26; ++i) {
                if (g[v][i] != 0) {
                    a[v] = a[g[v][i]];
                    g[v][i] = 0;
                    break;
                } 
           }
        }
        return dp[v] = cn;
    }
    else {
        dp[v] = a[v].size();
        return dp[v];
    }
}

void gtans(int v, long long l, long long r) {
    for (int i = 0; i < a[v].size(); ++i) {
        if (g[v][a[v][i] - 'a'] == 0) {
            if (l == 1) {
                cout << a[v][i];
                r--;
            }
            else {
                l--;
                r--;
            }
        }
        else {
            int u = g[v][a[v][i] - 'a'];
            if (dp[u] >= r) {
                gtans(u, l, r);
                return;
            }
            if (dp[u] >= l) { 
                gtans(u, l, dp[u]);
                l = 1;
                r -= dp[u];
            } 
            if (dp[u] < l) {
                l -= dp[u];
                r -= dp[u];
            }
        }
        if (r < l) {
            return;
        }
    }
}



signed main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    long long l, r, q;
    cin >> l >> r >> q; 
    vector <vector <int> > lst(26);
    a.resize(q + 1);
    lst[0].push_back(0);
    a[0] = 'a';
    for (int i = 0; i < q; ++i) {
        char c;
        string s;
        cin >> c >> s; 
        while (lst[c - 'a'].size()) {
            g[lst[c - 'a'].back()][c - 'a'] = i + 1;
            lst[c - 'a'].pop_back();
        }
        vector <int> cnt(26);
        for (int j = 0; j < s.size(); ++j) {
            cnt[s[j] - 'a'] ++;
        }
        for (int j = 0; j < 26; ++j) {
            if (cnt[j]) {
                lst[j].push_back(i + 1);
            }
        }
        a[i + 1] = s;
    }
    int n = a.size();
    dp.resize(n, -1);
    cnt_dp(0);
    gtans(0, l, r);
} 
