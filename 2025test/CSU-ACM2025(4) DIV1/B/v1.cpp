#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(1e18);
int N,M,X;
vector<int> ed[MAXN][2];

struct node
{
    bool status;//是否反转
    int cost;//当前花费
    int a;//当前点
    bool operator < (const node& n) const {
        return cost>n.cost;
    }
};
priority_queue<node> q;
int dis[MAXN][2];
void solve()
{
    cin>>N>>M>>X;
    inc(i,1,N)dis[i][0]=dis[i][1]=INF;
    inc(i,1,M)
    {
        int a,b;
        cin>>a>>b;
        ed[a][0].push_back(b);
        ed[b][1].push_back(a);
    }
    q.push({false,0ll,1ll});
    int ans(INF);
    while(!q.empty()&&q.top().cost<ans)
    {
        auto[status,cost,p] = q.top();
        q.pop();
        if(cost>=ans)break;
        if(p==N)
        {
            ans=min(ans,cost);
            continue;
        }
        if(cost>=dis[p][status])continue;
        else dis[p][status]=cost;
        if(cost+X<ans)q.push({!status,cost+X,p});
        for(int n:ed[p][status])
        {
            if(cost+1ll<ans)q.push({status,cost+1ll,n});
        }
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
}
/*
100
5 6 5
1 2
2 4
3 1
3 5
4 3
5 2


*/