#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
int ls(int a){return a<<1;}
int rs(int a){return (a<<1)|1;}
struct node{
    int val,l,r,tag;
    int length()
    {
        return r-l+1;
    }
}tree[MaxN*4];
int n,m;
int nums[MaxN];
void buildTree(int index,int l,int r)
{
    tree[index].l=l;
    tree[index].r=r;
    tree[index].tag=0;
    if(l==r)
    {
        tree[index].val=nums[l]-nums[l-1];
        return;
    }
    int mid(((r-l)>>1)+l);
    buildTree(ls(index),l,mid);
    buildTree(rs(index),mid+1,r);
    tree[index].val=tree[ls(index)].val+tree[rs(index)].val;
}
void pd(int index)
{
    tree[ls(index)].tag+=tree[index].tag;
    tree[rs(index)].tag+=tree[index].tag;
    tree[ls(index)].val+=tree[index].tag*tree[ls(index)].length();
    tree[rs(index)].val+=tree[index].tag*tree[rs(index)].length();
    tree[index].tag=0;
}
void update(int index,int l,int r,int val)
{
    if(tree[index].l>r||tree[index].r<l)return;
    if(tree[index].l>=l&&tree[index].r<=r)
    {
        tree[index].tag+=val;
        tree[index].val+=tree[index].length()*val;
        return;
    }
    pd(index);
    update(ls(index),l,r,val);
    update(rs(index),l,r,val);
    tree[index].val=tree[ls(index)].val+tree[rs(index)].val;
}
int searchTree(int index,int l,int r)
{
    if(tree[index].l>r||tree[index].r<l)return 0;
    if(tree[index].l>=l&&tree[index].r<=r)return tree[index].val;
    pd(index);
    return searchTree(ls(index),l,r)+searchTree(rs(index),l,r);
}
void solve()
{
    cin>>n>>m;
    inc(i,1,n)
    {
        cin>>nums[i];
    }
    buildTree(1,1,n);
    while(m--)
    {
        int type,l,r,k,d,p;
        cin>>type;
        switch (type)
        {
        case 1:
            cin>>l>>r>>k>>d;
            update(1,l,l,k);
            update(1,l+1,r,d);
            update(1,r+1,r+1,-(r-l)*d-k);
            break;
        case 2:
            cin>>p;
            cout<<searchTree(1,1,p)<<endl;
            break;
        case 3:
            inc(i,1,n)cout<<searchTree(1,1,i)<<" ";cout<<endl;
            break;
        default:
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
    // system("pause");
}
/*
5 100
1 2 3 4 5
1 2 4 1 2
2 3

*/