#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n,m;
    string s;
    cin >> n >> m;
    cin >> s;
    string ans = s;
    vector<vector<int>> C(m);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        C[tmp-1].push_back(i);
    }
    for(const auto& c : C){
        for(int i = 1; i < c.size(); i++){
            ans[c[i]] = s[c[i-1]];
        }
        ans[c[0]] = s[c[c.size()-1]];
    }
    cout << ans << endl;
}