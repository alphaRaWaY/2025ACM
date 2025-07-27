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
array<int,2> x,y,root,level;
int fa[MaxN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>cs[i].x;
    inc(i,1,n)cin>>cs[i].y;
    inc(i,1,n)cin>>cs[i].r;
    sort(cs+1,cs+1+n);
    cin>>x[0]>>y[0]>>x[1]>>y[1];
    inc(i,1,n)fa[i]=i;
    inc(i,1,n)
    {
        inc(j,i+1,n)
        {
            // cout<<cs[i].getDist({cs[i].x,cs[i].y},{cs[j].x,cs[j].y})<<" ";
            if(cs[j].contain(cs[i]))
            {
                fa[i]=j;
                break;
            }
        }
        // cout<<endl;
    }
    // debug1(cs,1,n);
    // debug1(fa,1,n);
    inc(j,0,1)inc(i,1,n)if(cs[i].contain(x[j],y[j])){root[j]=i;break;}
    
    // debug1(root,0,1);
    inc(j,0,1)
    {
        if(!root[j])continue;
        level[j]=1;
        while(fa[root[j]]!=root[j])
        {
            root[j]=fa[root[j]];
            level[j]++;
        }
    }
    // debug1(root,0,1);
    // debug1(level,0,1);
    if(root[0]!=root[1])cout<<level[0]+level[1]<<endl;
    else cout<<labs(level[0]-level[1])<<endl;
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