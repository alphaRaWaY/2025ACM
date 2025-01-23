//和0x14一个思路，部分不能打tag的操作，很快就会达到最终状态，此时不采用打标签的方法提速，而是选择检测一个树是否已经达到最终状态。
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int a){return a<<1;}
int rs(int a){return (a<<1)|1;}
const int MAXN(1e5+5);
int n,m;
int nums[MAXN];
struct node
{
    int l,r,val,maxN;
}tree[4*MAXN];

void buildTree(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].maxN=tree[i].val=nums[l];
        return;
    }
    int mid(((r-l)>>1)+l);
    buildTree(ls(i),l,mid);
    buildTree(rs(i),mid+1,r);
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
    tree[i].maxN=max(tree[ls(i)].maxN,tree[rs(i)].maxN);
}
int query(int i,int l,int r)
{
    if(tree[i].l>r||tree[i].r<l)return 0;
    if(tree[i].l>=l&&tree[i].r<=r)return tree[i].val;
    return query(ls(i),l,r)+query(rs(i),l,r);
}
void getMod(int i,int l,int r,int mod)
{
    if(tree[i].l>r||tree[i].r<l||tree[i].maxN<mod)return;
    if(tree[i].l==tree[i].r&&tree[i].l>=l&&tree[i].r<=r)
    {
        nums[tree[i].l]= nums[tree[i].l]%mod;
        tree[i].maxN=tree[i].val= nums[tree[i].l];
        return;
    }
    getMod(ls(i),l,r,mod);
    getMod(rs(i),l,r,mod);
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
    tree[i].maxN=max(tree[ls(i)].maxN,tree[rs(i)].maxN);
}
void update(int i,int pos,int val)
{
    if(tree[i].l>pos||tree[i].r<pos)return;
    if(tree[i].l==pos&&tree[i].r==pos)
    {
        nums[pos]=val;
        tree[i].maxN=tree[i].val=val;
        return;
    }
    update(ls(i),pos,val);
    update(rs(i),pos,val);
    tree[i].val=tree[ls(i)].val+tree[rs(i)].val;
    tree[i].maxN=max(tree[ls(i)].maxN,tree[rs(i)].maxN);
}
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    buildTree(1,1,n);
    while(m--)
    {
        int type;
        cin>>type;
        int l,r,x,k;
        switch (type)
        {
        case 1:
            cin>>l>>r;
            cout<<query(1,l,r)<<endl;   
            break;
        case 2:
            cin>>l>>r>>x;   
            getMod(1,l,r,x);
            break;
        case 3:
            cin>>k>>x;   
            update(1,k,x);
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
    _=1;
    // cin>>_;
    while(_--)solve();
}
/*
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
*/

/*
10 10
6 9 6 7 6 1 10 10 9 5
1 3 9
2 7 10 9
2 5 10 8
1 4 7
3 3 7
2 7 9 9
1 2 4
1 6 6
1 5 9
3 1 10
*/