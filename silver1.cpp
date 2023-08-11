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
vector <int> a;
vector <vector <int> > g;
int n;
vector <vector <int> > ans;
int c;
vector <int> smn;

void gotodown(int v, int p) {
    for (auto u : g[v]) {
        if (u != p && smn[u] < 0) {
            ans.push_back({ v, u, abs(smn[u]) });
            smn[u] = 0;
            gotodown(u, v);

        }
    }
}
void dfs(int v, int p) {
    smn[v] = a[v] - c;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            smn[v] += smn[u];
            if (smn[u] > 0) {
                ans.push_back({ u, v, smn[u] });
            }
        }
    }
    if (smn[v] >= 0) {
        for (auto u : g[v]) {
            if (u != p && smn[u] < 0) {
                ans.push_back({ v, u, abs(smn[u]) });
                smn[u] = 0;
                gotodown(u, v);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    g.resize(n);
    smn.resize(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    c = sm / n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x[0] + 1 << " " << x[1] + 1 << " " << x[2] << "\n";
    }

}