#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cassert>

#define int long long

using namespace std;


int fact[1000001];
int md = 1e9 + 7;

int binpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    int x = binpow(n, k / 2); 
    x *= x;
    x %= md;
    if (k % 2) {
        x *= n;
        x %= md;
    }
    return x;
}

int cc(int n, int k) {
    return fact[n] * binpow(fact[n - k], md - 2) % md * binpow(fact[k], md - 2) % md; 
}


int frm(vector <int> a) {
    int n = a.size(); 
    int ans = 1;
    int pr = (a.back() - 1) / 2; 
    for (int i = n - 2; i >= 0; --i) {
        int c = a[i] / 2;
        if (c - 1 <= pr) {
            ans *= cc(pr, c - 1);
            ans %= md;
            pr = c - 1;
        }
        else {
            c -= pr;
            ans *= cc(pr + 2 + c - 2, c - 1);
            ans %= md;
            pr = (a[i] - 1) / 2;
            
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sm = 0;
    fact[1] = 1;
    fact[0] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        fact[i] = fact[i - 1] * i % md;
    }
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << frm(a);
}
