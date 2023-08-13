#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    int c;
    int x;
    cin >> N;
    vector<set<int>> data(N);
    for(int i = 0; i < N; i++){
        cin >> c;
        for(int j = 0; j < c; j++){
            cin >> x;
            data[i].insert(x);
        }
    }
    cin >> x;
    int min = -1;
    for(int i = 0; i < N; i++){
        if(data[i].count(x)){
            if(min == -1) min = data[i].size();
        }
    }
    for(int i = 0; i < N; i++){
        if(data[i].count(x) && data[i].size() == min){
            cout << i+1 << endl;
        }
    }
}