#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5),INF(0x3f3f3f3f);
int n,m;
//带边权奇偶性的并查集
int fa[MAXN], parity[MAXN];  
int fd(int x) {  
    if (fa[x]==x) return x;  
    int root=fd(fa[x]);  
    parity[x]^=parity[fa[x]];  
    fa[x]=root;  
    return root;  
}  
bool unite(int x, int y, int w) {  
    int rootX=fd(x);  
    int rootY=fd(y);  
    if(rootX!=rootY) {  
        fa[rootX]=rootY;  
        parity[rootX]=parity[x]^parity[y]^w;  
        return true;
    }  
    else
    {
        return parity[rootX]!=parity[rootY];
    }
}
vector<pair<int,int> >diff;
void solve()
{
    diff.clear();
    cin>>n>>m;
    inc(i,1,n)fa[i]=i;  
    bool isOK(true);
    inc(i,1,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c&1)
        {
            isOK=unite(a,b,1ll);
        }
        else
        {
            if(a!=b)diff.push_back(make_pair(a,b));
        }
    }
    if(!isOK)
    {   
        cout<<"No"<<endl;
        return;
    }
    for(auto[x,y]:diff)
    {
        int rx=fd(x);
        int ry=fd(y);
        if(rx==ry&&parity[rx]!=parity[ry])
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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
5 4
1 3 4
4 2 7
4 4 0
5 2 1
*/