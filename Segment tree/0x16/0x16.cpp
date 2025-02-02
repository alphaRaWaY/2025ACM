#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int a){return a<<1;}
int rs(int a){return (a<<1)|1;}
const int MAXN(1e5+5);
struct node{
    int l,r,x,val;//区间左右端点和颜色
    int len()
    {
        return r-l+1;
    }
    void calVal()
    {
        if(x)
        {
            if(x>l&&x<r)
            {
                int a,b;
                a=x-l;
                b=r-x;
                val+=(a+1)*a/2+(b+1)*b/2;
            }
            else
            {
                val+=abs((r+l-2*x)*len()/2);
            }
        }
    }
}tree[MAXN];
void bt(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].val=0;
    if(l==r)
    {
        tree[i].x=l;
        return;
    }
    bt(ls(i),l,r);
    bt(rs(i),l,r);
    tree[i].x=-1;
}
void sd(int i)
{
    tree[ls(i)].x=tree[rs(i)].x=tree[i].x;
    tree[ls(i)].calVal();
    tree[rs(i)].calVal();
    tree[i].x=-1;
}
void us(int i)
{
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
}
void update(int i,int l,int r,int x)
{
    if(tree[i].l>r||tree[i].r<l)return;
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].x=x;
        tree[i].calVal();
        return;
    }
    sd(i);
    update(ls(i),l,r,x);
    update(rs(i),l,r,x);
    us(i);
}
int query(int i,int l,int r)
{
    if(tree[i].l>r||tree[i].r<l)return 0;
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        return tree[i].val;
    }
    sd(i);
    query(ls(i),l,r);
    query(rs(i),l,r);
    us(i);
    return tree[i].val;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    bt(1,1,n);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            update(1,l,r,x);
        }
        else if(type==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,l,r)<<endl;
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