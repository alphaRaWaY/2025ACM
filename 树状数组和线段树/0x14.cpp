//吓人题，其实最暴力就可以

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int a){return a<<1;}
int rs(int a){return (a<<1)|1;}
int n,m; 
const int MAXN(1e5+5);
int nums[MAXN];
struct node
{
    int val,l,r;
    int len(){
        return r-l+1;
    }
}tree[MAXN*4];
void bt(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].val=nums[l];
        return;
    }
    int mid(((r-l)>>1)+l);
    bt(ls(i),l,mid);
    bt(rs(i),mid+1,r);
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
}
void update(int i,int l,int r)
{
    // cout<<"hello world"<<endl;
    if((tree[i].l>r||tree[i].r<l)||tree[i].val==tree[i].len()||tree[i].val==0)return;
    if(tree[i].l==tree[i].r&&tree[i].l>=l&&tree[i].r<=r)
    {
        
        tree[i].val=sqrt(tree[i].val);
        return;
    }
    update(ls(i),l,r);
    update(rs(i),l,r);
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
}
int query(int i,int l,int r)
{
    if(tree[i].l>r||tree[i].r<l)return 0;
    if(tree[i].l>=l&&tree[i].r<=r)return tree[i].val;
    return query(ls(i),l,r)+query(rs(i),l,r);
}
void dfs(int i)
{
    cout<<tree[i].l<<" - "<<tree[i].r<<endl;
    cout<<tree[i].val<<endl;
    if(tree[i].l==tree[i].r)return;
    dfs(ls(i));
    dfs(rs(i));
}
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    bt(1,1,n);
    cin>>m;
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
        else if(type==0)
        {
            int x,y;
            cin>>x>>y;
            update(1,x,y);
        }
    // inc(i,1,n)cout<<query(1,i,i)<<' ';cout<<endl;
    }
    // dfs(1);
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
}

/*
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8
*/