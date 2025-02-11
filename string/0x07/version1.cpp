// 01tree
// 一个数，如果它两次异或同一个数，那么它是不会有改变的
// 在n个数中，在O(n)复杂度内找到两个数使得两个数的异或最大。
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5);
int n;
vector<pair<int,int> > ed[MAXN];
int val[MAXN];
int M;
void mark(int index,int pa,int v)
{
    M=max(M,v);
    val[index]=v;
    for(auto tmp:ed[index])
    {
        if(tmp.first==pa)continue;
        mark(tmp.first,index,v^(tmp.second));
    }
}
int treeSize(1);
int child[MAXN*32][2];
int build(bool p,int index)
{
    if(!child[index][p])
    {
        treeSize++;
        child[index][p]=treeSize;
    }
    return child[index][p];
}
void solve()
{
    M=0;
    cin>>n;
    inc(i,1,n-1)
    {
        int a,b,w;
        cin>>a>>b>>w;
        ed[a].push_back({b,w});
        ed[b].push_back({a,w});
    }
    mark(1,0,0);
    inc(i,1,n)
    {
        int now(1);
        dec(j,32,0)
        {
            now=build((val[i]>>j)&1,now);
        }
    } 
    int ans(0);
    inc(i,1,n)
    {
        int now=1,res(0);
        dec(j,32,0)
        {
            bool tmp=((val[i]>>j)&1);
            if(child[now][!tmp])
            {
                res=res<<1|1;
                now=child[now][!tmp];
            }
            else
            {
                now=child[now][tmp];
                res=res<<1;
            }
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
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