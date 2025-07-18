#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5),MOD(998244353),INF(0x7f7f7f7f7f7f7f7f);
vector<int> ed[MaxN],ed1[MaxN];
int d1[MaxN],dn[MaxN];

struct node
{
    int u,v,t,w;
    int y(){
        return d1[u]+dn[v]+t; 
    }
    int x(){
        return w;
    }
    bool operator < (node& n){
        if(x()<n.y())return y()<n.y(); 
        return x()<n.x();
    }
};

int dist[MaxN];
int n,m,q;
void solve()
{
    cin>>n>>m;
    inc(i,1,m)
    {
        int a,b,c;

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
1
4 4
1 2 15 1
1 3 20 2
2 4 10 1
3 4 10 1
2
9
1
*/