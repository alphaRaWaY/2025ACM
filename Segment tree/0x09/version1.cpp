//https://www.luogu.com.cn/problem/P3870

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
int ls(int a){return a<<1;}
int rs(int a){return (a<<1)|1;}
struct node
{
    int num,l,r;
    bool tag;
    int length()
    {
        return r-l+1;
    }
}tree[MaxN*4];
void buildTree(int index,int l,int r)
{
    tree[index].l=l;
    tree[index].r=r;
    tree[index].tag=false;
    tree[index].num=0;
    if(l==r)return;
    int mid(((r-l)>>1)+l);
    buildTree(ls(index),l,mid);
    buildTree(rs(index),mid+1,r);
}
void pd(int index)
{
    if(!tree[index].tag)return;
    tree[ls(index)].tag=!tree[ls(index)].tag;
    tree[rs(index)].tag=!tree[rs(index)].tag;
    tree[ls(index)].num=tree[ls(index)].length()-tree[ls(index)].num;
    tree[rs(index)].num=tree[rs(index)].length()-tree[rs(index)].num;
    tree[index].tag=false;
}
void update(int index,int l,int r)
{
    if(tree[index].l>r||tree[index].r<l)return;
    if(tree[index].l>=l&&tree[index].r<=r)
    {
        tree[index].tag=!tree[index].tag;
        tree[index].num=tree[index].length()-tree[index].num;
        return;
    }
    pd(index);
    update(ls(index),l,r);
    update(rs(index),l,r);
    tree[index].num=tree[ls(index)].num+tree[rs(index)].num;
}
int searchTree(int index,int l,int r)
{
    if(tree[index].l>r||tree[index].r<l)return 0;
    if(tree[index].l>=l&&tree[index].r<=r)return tree[index].num;
    pd(index);
    return searchTree(ls(index),l,r)+searchTree(rs(index),l,r);    
}
void dfs(int index)
{
    cout<<tree[index].l<<"-"<<tree[index].r<<"  num : "<<tree[index].num<<"  tag : "<<tree[index].tag<<endl;
    if(tree[index].l==tree[index].r)return;
    dfs(ls(index));
    dfs(rs(index));
}
int n,m;
void solve()
{
    cin>>n>>m;
    buildTree(1,1,n);
    while(m--)
    {
        int type,a,b;
        cin>>type>>a>>b;
        switch (type)
        {
        case 0:
            update(1,a,b);
            break;
        case 1:
            cout<<searchTree(1,a,b)<<endl;
            break;
        case 2:
            dfs(1);
            break;
        case 3:
            inc(i,1,n)
            {
                cout<<searchTree(1,i,i)<<" ";
            }
            cout<<endl;
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
    system("pause");
}
/*
4 10
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4
*/