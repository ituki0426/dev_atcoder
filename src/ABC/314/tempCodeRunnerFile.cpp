#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
   int n, q;
   int last_2_3 = 0;
   string s;
   cin >> n;
   cin >> s;
   cin >> q;
   vector<int> t(q), x(q);
   vector<char> c(q);
   rep(i, q){
      cin >> t[i] >> x[i] >> c[i];
      if(t[i] == 2 || t[i] == 3){
         last_2_3 = i;
      }
   }
   rep(i,last_2_3){
        if(t[i] == 1){
             s[x[i]-1] = c[i];
        }
   }
   if(t[last_2_3] == 2)
      transform(s.begin(), s.end(), s.begin(), ::tolower);
   if(t[last_2_3] == 3)
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    for(int i = last_2_3+1; i < q; i++){
        if(t[i] == 1){
             s[x[i]-1] = c[i];
        }
    }
    cout << s << endl;
}