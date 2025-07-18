#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(5e5+5),MOD(998244353);
int n;
int nums[MaxN],s[MaxN],cnt1;
int fast_pow(int a,int b)
{
    int base(a),res(1);
    while(b)
    {
        if(b&1)res=(base*res)%MOD;
        b>>=1;
        base=(base*base)%MOD;
    }
    return res;
}
int mod_mul(int a,int b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}

int getPower(vector<int> segment)
{
    if(segment.empty())return 0;
    int now1(0),s(0);
    for(int tmp:segment)if(tmp==-1)now1++;
    return mod_mul(s,fast_pow(2ll,cnt1-now1));
}
void solve()
{
    cin>>n;
    cnt1=0;
    inc(i,1,n){
        cin>>nums[i];
        if(nums[i]==-1)cnt1++;
    }
    vector<int> nowSegment;
    int ans(0);
    inc(i,1,n)
    {
        // 遇到零处理序列
        if(!nums[i])
        {
            ans=(ans+getPower(nowSegment))%MOD;
            nowSegment.clear();
            continue;
        }
        nowSegment.push_back(nums[i]);
    }
    // 循环结束处理最后的序列
    ans=(ans+getPower(nowSegment))%MOD;
    nowSegment.clear();
    cout<<ans<<endl;
}
signed main()
{
    // cout<<fast_pow(3,5)<<endl;
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}