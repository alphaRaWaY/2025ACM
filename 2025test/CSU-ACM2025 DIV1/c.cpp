#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5),INF(0x3f3f3f3f);
int n,m,t0,t1,t2;
struct node
{
    int p,w1,w2;
};
int dis[MAXN];
vector<node> ed[MAXN];
void solve()
{
    cin>>n>>m;
    inc(i,1,n-1)dis[i] = INF;
    inc(i,1,n)ed[i].clear();
    cin>>t0>>t1>>t2;
    inc(i,1,m)
    {
        int p1,p2,w1,w2;
        ed[p1].push_back({p2,w1,w2});
        ed[p2].push_back({p1,w1,w2});
    }
    priority_queue<pair<int,int> >q;
    q.push({0,n});
    while(!q.empty())
    {
        auto[d,now] = q.top();
        q.pop();
        for(auto[target,w1,w2]:ed[now])
        {
            int w;
            if(d+w1>t0-t2||d<t0-t1)w=w2;
            else w=w1;
            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}
/*
7
5 5
100 20 80
1 5 30 100
1 2 20 50
2 3 20 50
3 4 20 50
4 5 20 50
2 1
100 50 60
1 2 55 110
4 4
100 40 60
1 2 30 100
2 4 30 100
1 3 20 50
3 4 20 50
3 3
100 80 90
1 2 1 10
2 3 10 50
1 3 20 21
3 2
58 55 57
2 1 1 3
2 3 3 4
2 1
12 9 10
2 1 6 10
5 5
8 5 6
2 1 1 8
2 3 4 8
4 2 2 4
5 3 3 4
4 5 2 6
*/