#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
vector<int> ed[MAXN];
int ans[MAXN],sz[MAXN];
void dfs(int i)
{
    if(ans[i])return;
    sz[i]=1;
    ans[i]=0;
    for(int tmp:ed[i])
    {
        dfs(tmp);
        ans[i]+=ans[tmp]+sz[tmp];
        sz[i]+=sz[tmp];
    }   
}
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        ed[i].clear();
        ans[i]=0;
    }
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
    }
    int cnt(0);
    inc(i,1,n)dfs(i);
    int total(0);
    inc(i,1,n)total+=ans[i];
    cout<<total<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");
}
/*
4
5
1 2
1 3
1 4
1 5
5
1 2
3 1
4 1
5 1
4
1 2
2 3
3 4
6
1 2
3 2
4 3
5 3
6 3
*/