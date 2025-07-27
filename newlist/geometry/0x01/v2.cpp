// https://www.luogu.com.cn/problem/P1652

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define debug1(c,l,r) inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr) inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
const int MaxN(55);
int n;
struct node{
    int x,y,r;
    int getDist(pair<int,int>a,pair<int,int>b)
    {
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }
    bool contain(node n)
    {
        return getDist({x,y},{n.x,n.y})<(n.r-r)*(n.r-r);
    }
    bool contain(int a,int b)
    {
        return getDist({a,b},{x,y})<r*r;
    }
    bool operator < (const node& n) const{
        return r<n.r;
    }
}cs[MaxN];
// 重载输出方法
ostream &operator<<(ostream& o,const node &n)
{
    o<<"{"<<n.x<<","<<n.y<<":"<<n.r<<"}";
    return o;
}
vector<int> ed[MaxN];
int ans;
void dfs(int index,int level,int pa,int t)
{
    if(ans)return;
    if(index==t)
    {
        ans=level;
        return;
    }
    for(int tmp:ed[index])
    {
        if(tmp==pa)continue;
        dfs(tmp,level+1,index,t);
    }
}
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>cs[i].x;
    inc(i,1,n)cin>>cs[i].y;
    inc(i,1,n)cin>>cs[i].r;
    sort(cs+1,cs+1+n);
    inc(i,1,n)
    {
        bool flag(false);
        inc(j,i+1,n)
        {
            if(cs[j].contain(cs[i]))
            {
                ed[i].push_back(j);
                ed[j].push_back(i);
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            ed[i].push_back(0);
            ed[0].push_back(i);
        }
    }
    int index1(0),index2(0);
    int a,b;
    cin>>a>>b;
    inc(i,1,n)
    {
        if(cs[i].contain({a,b}))
        {
            index1=i;
            break;
        }
    }
    cin>>a>>b;
    inc(i,1,n)
    {
        if(cs[i].contain({a,b}))
        {
            index2=i;
            break;
        }
    }
    dfs(index1,0,index1,index2);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}
/*
7
1 -3 2 5 -4 12 12
1 -1 2 5 5 1 1
8 1 2 1 1 1 2
-5 1 12 1
*/
/*
6
0 0 0 11 11 11 
0 0 0 0 0 0
1 3 5 1 3 5
2 0 11 0


6
0 0 0 11 11 11 
0 0 0 0 0 0
1 3 5 1 3 5
4 0 9 0
*/