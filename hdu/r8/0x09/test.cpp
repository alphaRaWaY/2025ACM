#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128;

// 方便本地调试的板子
#define LOCAL
#ifdef LOCAL
ostream &operator<< (ostream & o,const pair<int,int> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#define split cout<<"-------------------------------"<<endl
#define debug0(c) cout<<"[DEBUG] "<<#c<<"="<<c<<endl
#define debug1(c,l,r)\
cout<<"[DEBUG] "<<#c<<": ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl 
#define debug2(c,l,r,ll,rr)\
cout<<"[DEBUG] "<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
#define T test()
#define case_ans cout<<"[ANSWER] "
#else
#define T
#define case_ans
#define split
#define debug0(c)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif



string int128ToString(__int128 x) {
  if (x == 0) return "0";
  string result;
  bool is = x < 0;
  if (is) x = -x;
  while (x > 0) {
    result.push_back('0' + (x % 10));
    x /= 10;
  }
  if (is) result.push_back('-');
  reverse(result.begin(), result.end());
  return result;
}

void solve() {
    ll n, w;
    cin >> n >> w;
    ll i = 1, y = n;
    i128 ans = 0;
    while (y >= w) {
        // cout<<"#"<<int128ToString(ans)<<endl;
        ans += i128(i + n) * (n - i + 1) / 2;
        ll x = y / w;
        i += x;
        y -= x;
    }
    ans += i128(i + n) * (n - i + 1) / 2;
    cout << int128ToString(ans) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
4
5 2
7 4
6 1
9 3
*/

/*
41
120
21
155
*/