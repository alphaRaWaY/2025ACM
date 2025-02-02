#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
int n,k,d1,d2;
vector<int> ed[MaxN];
int dis[MaxN];
map<double,int>cnt;
void dfs(int parent,int root)
{
    for(int p:ed[root])
    {
        if(p==parent)continue;
        dis[p]=dis[root]+1;
        dfs(root,p);
    }
}

void solve()
{
    cin>>n>>k;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dis[1]=0;
    dfs(0,1);
    int maxDis(0);
    inc(i,1,n)
    {
        if(dis[i]>maxDis)
        {
            maxDis=dis[i];
            d1=i;
        }
    }
    dis[d1]=0;
    dfs(0,d1);
    inc(i,1,n)maxDis=max(maxDis,dis[i]);
    inc(i,1,n)cnt[abs(dis[i]-1.0*maxDis/2)]++;
    inc(i,1,n)cout<<dis[i]<<" ";cout<<endl;
    // for(auto[x,y]:cnt)
    // {
    //     cout<<x<<" "<<y<<endl;
    // }
    double ans=0,px(0);
    int tot(0);
    for(auto[x,y]:cnt)
    {
        tot+=y;
        if(tot>k)
        {
            ans=px;
            break;
        }
        px=x;
    }
    cout<<ans<<" "<<tot<<endl;
    cout<<(int)(1.0*maxDis/2-ans+0.5)<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}
/*
7 1
1 2
2 3
2 4
1 5
5 6
6 7

7 3
1 2
2 3
2 4
1 5
5 6
6 7

6 3
1 2
2 3
2 4
1 5
5 6
*/
