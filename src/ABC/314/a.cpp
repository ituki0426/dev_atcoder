#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
string en = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
int main(){
    int n;
    cin >> n;
    cout << 3 << ".";
    for(int i = 0; i < n; i++){
        cout << en[i];
    }
    return 0;
}