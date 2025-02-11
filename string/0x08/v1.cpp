// 互斥相容
// 字典树
#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e4+5);
int n,m;
string msg[MAXN],pre[MAXN];
int treeSize(1);
int sz[MAXN*10];
int child[MAXN*10][2];
int add(bool p,int index)
{
    sz[index]++;
    if(!child[index][p])
    {
        treeSize++;
        child[index][p]=treeSize;
    }
    return child[index][p];
}
void solve()
{
    cin>>m>>n;
    inc(i,1,m)
    {
        int tmp;
        cin>>tmp;
        msg[i].resize(tmp);
        for(auto& in:msg[i])cin>>in;
    }
    // 建树
    inc(i,1,m)
    {
        int now(1);
        for(char tmp:msg[i])
        {
            now=add(tmp=='1',now);
        }
        sz[now]++;
    }
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        int now(1);
        int ans(sz[1]);
        inc(i,1,tmp)
        {
            bool in;cin>>in;
            if(!now)continue;
            ans-=sz[child[now][!in]];
            now=child[now][in];
        }
        cout<<ans<<endl;
    }
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