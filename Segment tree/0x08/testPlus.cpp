#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int i)
{
    return (i<<1);
}
int rs(int i)
{
    return (i<<1)|1;
}
const int MaxN(1e5+5);
int n,q,mode;
int nums[MaxN];

struct node
{
    int val,l,r;
    int tag;
}tree[4*MaxN];
void buildtree(int index,int l,int r)
{
    tree[index].l=l;
    tree[index].r=r;
    if(tree[index].l==tree[index].r)
    {
        tree[index].val=nums[l];
        return;
    }
    int mid(((r-l)>>1)+l);
    buildtree(ls(index),l,mid);
    buildtree(rs(index),mid+1,r);
    tree[index].val=tree[ls(index)].val+tree[rs(index)].val;
}
void pd(int index)
{
    tree[ls(index)].tag+=tree[index].tag;
    tree[rs(index)].tag+=tree[index].tag;
    tree[ls(index)].val+=tree[index].tag*(tree[ls(index)].r-tree[ls(index)].l+1);
    tree[rs(index)].val+=tree[index].tag*(tree[rs(index)].r-tree[rs(index)].l+1);
    tree[index].tag=0;
}
int searchTree(int index,int l,int r)
{
    if(tree[index].l>=l&&tree[index].r<=r)return tree[index].val;
    if(tree[index].r<l||tree[index].l>r)return 0;
    pd(index);
    return searchTree(ls(index),l,r)+searchTree(rs(index),l,r);
}
void add(int index,int l,int r,int val)
{
    if(tree[index].r<l||tree[index].l>r)return;
    if(tree[index].l>=l&&tree[index].r<=r)
    {
        tree[index].tag+=val;
        tree[index].val+=val*(tree[index].r-tree[index].l+1);
        return;
    }
    pd(index);
    add(ls(index),l,r,val);
    add(rs(index),l,r,val);
    tree[index].val=tree[ls(index)].val+tree[rs(index)].val;
}
void dfs(int index)
{
    cout<<tree[index].l<<"-"<<tree[index].r<<" val: "<<tree[index].val<<",tag: "<<tree[index].tag<<endl;
    if(tree[index].l==tree[index].r)return;
    dfs(ls(index));
    dfs(rs(index));
}
void solve()
{
    cin>>n>>q>>mode;
    inc(i,1,n)
    {
        cin>>nums[i];
    }
    buildtree(1,1,n);
    while(q--)
    {
        int type;
        int a,b,val;
        cin>>type;
        switch (type)
        {
        case 0:
            dfs(1);
            break;
        case 1:
            cin>>a>>b;
            cout<<searchTree(1,a,b)<<endl;
            break;
        case 2:
            cin>>a>>b>>val;
            add(1,a,b,val);
            break;
        default:
            cout<<"please enter the true type!"<<endl;
            break;
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
    system("pause");
}
/*
5 100 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4
*/