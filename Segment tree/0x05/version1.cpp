#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN = 305,MaxC(100);
int n,m,q;
int tree[MaxN][MaxN][MaxC];
int weight[MaxN][MaxN];     
void update(int x,int y,int val,int to)
{
    while(x<=n)
    {
        int ty = y;
        while(ty<=m)
        {
            tree[x][ty][to]+=val;
            ty+=ty&-ty;
        }
        x+=x&-x;
    }
}
int sum(int x,int y,int to)
{
    int res(0);
    while(x)
    {
        int ty = y;
        while(ty)
        {
            res+=tree[x][ty][to];
            ty-=ty&-ty;
        }
        x-=x&-x;
    }
    return res;
}
int sum(int x1,int y1,int x2,int y2,int to)
{
    return sum(x2,y2,to)+sum(x1-1,y1-1,to)-sum(x2,y1-1,to)-sum(x1-1,y2,to);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    inc(i,1,n)inc(j,1,m){cin>>weight[i][j];update(i,j,1,weight[i][j]);}
    cin>>q;
    inc(_,1,q)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,y,to;
            cin>>x>>y>>to;
            update(x,y,-1,weight[x][y]);
            weight[x][y]=to;
            update(x,y,1,weight[x][y]);
        }
        else
        {
            int x1,x2,y1,y2,to;
            cin>>x1>>x2>>y1>>y2>>to;
            cout<<sum(x1,y1,x2,y2,to)<<endl;
        }
    }
    system("pause");
}