#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(5e5+5),MOD(998244353);
vector<int> ed[MaxN];
vector<int> nums0,nums1;
bool vis[MaxN];
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
const int inv4 = (inv(4));
const int inv2 = (inv(2));
int dfs(int index,int pa)
{
    // cout<<index<<endl;
    int res(1);
    if(vis[index])return res;
    vis[index]=true;
    for(int tmp:ed[index])
    {
        if(tmp==pa||vis[tmp])continue;
        res = 1+dfs(tmp,index);
    }
    return res;
}
void solve()
{
    nums0.clear();
    nums1.clear();
    cin>>n;
    inc(i,1,n)ed[i].clear();
    inc(i,1,n){
        vis[i]=false;
        int a;
        cin>>a;
        ed[i].push_back(a);
        ed[a].push_back(i);
    }
    inc(i,1,n)
    {
        if(vis[i])continue;
        int tmp = dfs(i,0);
        if(tmp&1)nums1.push_back(tmp);
        else nums0.push_back(tmp);
    }
    // cout<<"#1"<<endl;
    // for(int tmp:nums1)cout<<tmp<<" ";cout<<endl;
    // cout<<"#0"<<endl;
    // for(int tmp:nums0)cout<<tmp<<" ";cout<<endl;
    if(nums1.size()==2)
    {
        sort(nums0.begin(),nums0.end());
        int cnt2(0);
        for(int tmp:nums0)if(tmp==2)cnt2++;else break;
        int T = fast_pow(2,nums0.size()-cnt2);
        cout<<mod_mul(nums1[0],mod_mul(nums1[1],T))<<endl;
    }
    else if(nums1.empty())
    {
        sort(nums0.begin(),nums0.end());
        int cnt2(0);
        for(int tmp:nums0)if(tmp==2)cnt2++;else break;
        int T = fast_pow(2,nums0.size()-cnt2);
        int ans(0);
        for(int tmp:nums0){
            int res = mod_mul(tmp,mod_mul(tmp,inv4));
            // int res(((tmp*tmp)%MOD*inv4)%MOD);
            if(tmp==2)res=(res*T)%MOD;
            else res=(res*(T*inv2)%MOD)%MOD;
            ans=(ans+res)%MOD;
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}
/*
2
4
1 3 4 2
6
3 4 5 6 2 1
*/