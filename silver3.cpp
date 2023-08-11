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
vector <vector <int> > r;
bool check(vector <int>& ans) {
    for (int i = 0; i < ans.size(); ++i) {
        int mn = ans[i];
        int mx = ans[i];
        for (int j = i + 1; j < ans.size(); ++j) {
            mx = max(mx, ans[j]);
            mn = min(mn, ans[j]);
            if (r[i][j] != mx - mn) {
                return 0;
            }
        }
    }
    return 1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    r.resize(n, vector <int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cin >> r[i][j];
        }
    }
    vector <int> ans;
    ans.push_back(1);
    for (int i = 1; i < n; ++i) {
        int vr1 = ans.back() + r[i - 1][i];
        int vr2 = ans.back() - r[i - 1][i];
        ans.push_back(vr1);
        if (check(ans)) {
            continue;
        }
        ans.pop_back();
        ans.push_back(vr2);
    }
    for (int i = 0; i < ans.size(); ++i){
        if (i == ans.size() - 1){
            cout << ans[i];
        }
        else{
            cout << ans[i] << " ";
        }
    }

} 
