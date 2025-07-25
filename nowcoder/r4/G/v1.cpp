#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(5e5+5),MOD(998244353);
int n;
map<pair<int,int>,int> pow_store;
int fast_pow(int a,int b)
{
    if(!b)return 1;
    if(pow_store[{a,b}])return pow_store[{a,b}];
    int base(a),res(1ll);
    while(b)
    {
        if(b&1)res=(base*res)%MOD;
        b>>=1;
        base=(base*base)%MOD;
    }
    pow_store[{a,b}]=res;
    return res;
}
int mod_mul(int a,int b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
int inv(int a){return fast_pow(a,MOD-2);}
void solve()
{

}
void test()
{
    inc(i,1,25)
    {
        int tmp=1<<i;
        // cout<<mod_mul(tmp-1,inv(tmp))<<endl;
        // cout<<mod_mul(936828929ll,tmp)<<endl;
        cout<<mod_mul(826671105ll,tmp)<<endl;
        
        // cout<<mod_mul(936828929,i)<<endl;
        // cout<<mod_mul(249561089,i)<<endl;
    }
}
signed main()
{
    test();
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}
/*
()()
3/2^2

((()(()())))
63/2^10

()(()(())) 
11/2^6
*/