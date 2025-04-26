#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
pair<int,int> scheme[7]{{1,18},{6,78},{28,308},{88,938},{198,2108},{328,3478},{648,6868}};
int ans(0);
bool vis[10];
void dfs(int money,int type,int layer,int val)
{
    if(money<0)
    {
        val+=10*(scheme[type].first+money);
        ans=max(ans,val);
        return;
    }
    vis[type]=true;
    val+=scheme[type].second;
    if(layer==6)
    {
        ans=max(ans,val+money*10);
    }
    inc(i,0,6)
    {
        if(vis[i])continue;
        dfs(money-scheme[i].first,i,layer+1,val);
    }
    vis[type]=false;
}
void solve()
{
    ans=0;
    memset(vis,false,sizeof(vis));
    cin>>n;
    if(n>=1297)
    {
        cout<<10*(n-1297)+13796<<endl;
        return;
    }
    inc(i,0,6)
    {
        dfs(n-scheme[i].first,i,0,0);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    // system("pause");
}
/*

*/