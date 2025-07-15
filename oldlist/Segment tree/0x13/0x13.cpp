//究级水题，在0x12上面多一个update即可

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e4+5);
int ls(int a){return (a<<1);}
int rs(int a){return (a<<1)|1;}
int nums[MAXN],pre[MAXN];
int n,m;
struct node{
    int l,r;
    int val;
    int lv,rv;
    int sum;
    int len()
    {
        return r-l+1;
    }
    bool has(int x,int y)
    {
        return r>=x&&l<=y;
    }
}tree[4*MAXN];
void us(int i)
{
    tree[i].lv=max(tree[ls(i)].lv,tree[ls(i)].sum+tree[rs(i)].lv);
    tree[i].rv=max(tree[rs(i)].rv,tree[rs(i)].sum+tree[ls(i)].rv);
    tree[i].val=max(max(tree[ls(i)].val,tree[rs(i)].val),tree[ls(i)].rv+tree[rs(i)].lv);    
}
void bt(int i,int l,int r)
{ 
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].lv=
        tree[i].val=
        tree[i].rv=
        tree[i].sum=nums[l];
        return;
    }
    int mid(((r-l)>>1)+l);
    bt(ls(i),l,mid);
    bt(rs(i),mid+1,r);
    tree[i].sum=tree[ls(i)].sum+tree[rs(i)].sum;
    us(i);
}
void update(int i,int pos,int val)
{
    if(tree[i].l==pos&&tree[i].r==pos){
        nums[pos]=
        tree[i].lv=
        tree[i].val=
        tree[i].rv=
        tree[i].sum=val;
        return;
    }
    if(tree[ls(i)].has(pos,pos))update(ls(i),pos,val);
    else if(tree[rs(i)].has(pos,pos))update(rs(i),pos,val);
    tree[i].sum=tree[ls(i)].sum+tree[rs(i)].sum;
    us(i);
}
node query(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        return tree[i];
    }
    if(!tree[ls(i)].has(l,r))return query(rs(i),l,r);
    if(!tree[rs(i)].has(l,r))return query(ls(i),l,r);
    else
    {
        node ans,a,b;
        a=query(ls(i),l,r);
        b=query(rs(i),l,r);
        ans.sum=a.sum+b.sum;
        ans.val=max(max(a.val,b.val),a.rv+b.lv);
        ans.lv=max(a.lv,a.sum+b.lv);
        ans.rv=max(b.rv,b.sum+a.rv);
        ans.l=ans.r=0;
        return ans;
    }
}
void dfs(int i)
{
    cout<<tree[i].l<<"-"<<tree[i].r<<endl;
    cout<<"maxl: "<<tree[i].lv<<endl;
    cout<<"maxr: "<<tree[i].rv<<endl;
    cout<<"max: "<<tree[i].val<<endl;
    cout<<"sum: "<<tree[i].sum<<endl;
    if(tree[i].l==tree[i].r)return;
    dfs(ls(i));
    dfs(rs(i));
}
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    partial_sum(nums+1,nums+1+n,pre+1);
    // inc(i,1,n)cout<<nums[i]<<" ";cout<<endl;
    bt(1,1,n);
    // dfs(1);
    cin>>m;
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y).val<<endl;
        }
        else if(type==0)
        {
            int pos,val;
            cin>>pos>>val;
            update(1,pos,val);
        }
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
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3
*/