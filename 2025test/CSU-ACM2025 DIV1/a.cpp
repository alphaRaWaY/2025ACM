#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
int n,q,m;
const int MAXN(1e5+5);
struct node{
    int l,r,val,add,mul;
    int length(){return r-l+1;}
}tree[MAXN*4];
int nums[MAXN];
void bt(int index,int l,int r)
{
    tree[index].l=l;
    tree[index].r=r;
    tree[index].mul=1;
    tree[index].add=0;
    if(l==r)
    {
        tree[index].val=nums[l];
        return;
    }
    int mid(((r-l)>>1)+l);
    bt(ls(index),l,mid);
    bt(ls(index),mid+1,r);
    tree[index].val=tree[ls(index)].val+tree[rs(index)].val;
}
void pd(int index)
{
    tree[ls(index)].mul=tree[rs(index)].mul=tree[index].mul;
    tree[ls(index)].add=tree[rs(index)].add=tree[index].add;
    tree[ls(index)].val=(tree[ls(index)].val*tree[index].mul%m+tree[index].val*tree[ls(index)].length()%m)%m;
    tree[rs(index)].val=(tree[rs(index)].val*tree[index].mul%m+tree[index].val*tree[rs(index)].length()%m)%m;
    tree[index].add=0;
    tree[index].mul=1;
}
void add(int index,int l,int r,int val)
{
    if(tree[index].l>r||tree[index].r<l)return;
    if(tree[index].l>l&&tree[index].r<r)
    {
        tree[index].val=(tree[index].val+tree[index].length()*val)%m;
        tree[index].add=(tree[index].add+val)%m;
        return;
    }
    pd(index);
    add(ls(index),l,r,val);
    add(rs(index),l,r,val);
}
void mul(int index,int l,int r,int val)
{
    if(tree[index].l>r||tree[index].r<l)return;
    if(tree[index].l>l&&tree[index].r<r)
    {
        tree[index].val=(tree[index].val*val)%m;
        tree[index].add=(tree[index].add*val)%m;
        tree[index].mul=(tree[index].mul*val)%m;
        return;
    }
    pd(index);
    mul(ls(index),l,r,val);
    mul(rs(index),l,r,val);
}
int query(int index,int l,int r)
{
    if(tree[index].l>r||tree[index].r<l)return 0;
    if(tree[index].l>l&&tree[index].r<r)
    {
        return tree[index].val;
    }
    pd(index);
    return query(ls(index),l,r)+query(rs(index),l,r);
}
void solve()
{
    cin>>n>>q>>m;
    inc(i,1,n)
    {
        cin>>nums[i];
    }
    bt(1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,val;
            cin>>l>>r>>val;
            mul(1,l,r,val);
        }
        else if(type==2)
        {
            int l,r,val;
            cin>>l>>r>>val;
            add(1,l,r,val);
        }
        else
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
    _=1;
    cin>>_;
    while(_--)solve();
}