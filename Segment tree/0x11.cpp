//最左最右合并实现跨子树更新父亲节点
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e4+5);
int ls(int a){return (a<<1);}
int rs(int a){return (a<<1)|1;}
int n,m;
struct node{
    int sum;
    int l,r;
    int lmax,rmax;
    int tag;
    int len(){return r-l+1;}
}tree[4*MAXN];
void buildTree(int index,int l,int r)
{
    tree[index].l=l;
    tree[index].r=r;
    tree[index].tag=0;
    tree[index].lmax=tree[index].rmax=tree[index].sum=tree[index].len();
    if(l==r)
    {
        tree[index].sum=tree[index].lmax=tree[index].rmax=1;
        return;
    }
    int mid(((r-l)>>1)+l);
    buildTree(ls(index),l,mid);
    buildTree(rs(index),mid+1,r);
}
void downSpread(int i)
{
    if(tree[i].tag==0)return;
    else if(tree[i].tag==1)//入住
    {
        tree[ls(i)].tag=1;
        tree[rs(i)].tag=1;
        tree[ls(i)].lmax=
        tree[ls(i)].rmax=
        tree[ls(i)].sum=0;
        tree[rs(i)].lmax=
        tree[rs(i)].rmax=
        tree[rs(i)].sum=0;
    }
    else if(tree[i].tag==2)//退房
    {
        tree[ls(i)].tag=2;
        tree[rs(i)].tag=2;
        tree[ls(i)].lmax=
        tree[ls(i)].rmax=
        tree[ls(i)].sum=tree[ls(i)].len();
        tree[rs(i)].lmax=
        tree[rs(i)].rmax=
        tree[rs(i)].sum=tree[rs(i)].len();
    }
    tree[i].tag=0;
}
void upSpread(int i)
{
    if(tree[ls(i)].lmax==tree[ls(i)].len())
    {
        tree[i].lmax=tree[ls(i)].len()+tree[rs(i)].lmax;
    }
    else
    {
        tree[i].lmax=tree[ls(i)].lmax;
    }
    if(tree[rs(i)].rmax==tree[rs(i)].len())
    {
        tree[i].rmax=tree[rs(i)].len()+tree[ls(i)].rmax;
    }
    else
    {
        tree[i].rmax=tree[rs(i)].rmax;
    }
    tree[i].sum=max(max(tree[ls(i)].sum,tree[rs(i)].sum),tree[ls(i)].rmax+tree[rs(i)].lmax);
}
void getIn(int i,int l,int r)
{
    if(tree[i].r<l||tree[i].l>r)return;
    // cout<<"hello world"<<endl;
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].sum=tree[i].lmax=tree[i].rmax=0;
        tree[i].tag=1;
        return;
    }
    downSpread(i);
    getIn(ls(i),l,r);
    getIn(rs(i),l,r);
    upSpread(i);
}
void getOut(int i,int l,int r)
{
    if(tree[i].r<l||tree[i].l>r)return;
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].sum=tree[i].lmax=tree[i].rmax=tree[i].len();
        tree[i].tag=2;
        return;
    }
    downSpread(i);
    getOut(ls(i),l,r);
    getOut(rs(i),l,r);
    upSpread(i);
}
void findRoom(int i,int val,int& ans)
{
    if(ans||tree[i].sum<val)return;
    if(tree[i].lmax>=val)
    {
        ans=tree[i].l;
        return;
    }
    downSpread(i);
    if(tree[ls(i)].sum>=val)findRoom(ls(i),val,ans);
    if(ans)return;
    if(tree[ls(i)].rmax+tree[rs(i)].lmax>=val)
    {
        ans=tree[ls(i)].r-tree[ls(i)].rmax+1;
        return;
    }
    else if(tree[rs(i)].sum>=val)findRoom(rs(i),val,ans);
}
void dfs(int i)
{
    cout<<"l: "<<tree[i].l<<" ,r: "<<tree[i].r<<endl;
    cout<<"sum: "<<tree[i].sum<<endl;
    cout<<"maxl: "<<tree[i].lmax<<endl;
    cout<<"maxr: "<<tree[i].rmax<<endl;
    if(tree[i].len()==1)return;
    dfs(ls(i));
    dfs(rs(i));
}
void solve()
{
    cin>>n>>m;
    buildTree(1,1,n);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int i,ans(0);
            cin>>i;
            if(tree[1].sum<i)
            {
                cout<<0<<endl;
                continue;
            }
            findRoom(1,i,ans);
            getIn(1,ans,ans+i-1);
            cout<<ans<<endl;
        }
        else if(type==2)
        {
            int i,j;
            cin>>i>>j;
            getOut(1,i,i+j-1);
            // dfs(1);
        }
    // dfs(1);
    // cout<<"=========================="<<endl;
    }
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
10 6
1 3
1 3
1 3
1 3
2 5 5
1 6
*/