#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
mt19937_64 rng(time(0));
int getRng(int l,int r){return (rng()%(r-l+1)+l);}
const int MaxN(100),INF(0x3f3f3f3f3f3f3f3f);
int n,m;
void solve()
{
    vector<vector<array<int,2>>> nums(10);
}
void test();
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
3 3
@.#
#.#
#.*
*/

/*
3 3
#@#
@!*
#*
*/

/*
3
3 3
@.#
#.#
#.*
3 3
#@#
@!*
#*#
3 3
@#@
#..
**#
*/