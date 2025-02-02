//使用线段树实现

#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(5e5+5);
const int INF(0x3f3f3f3f);
struct node
{
    int l;
    int r;
    int val;
    node():val(0),l(0),r(0){}
};
vector<node> tree;
int nums[MaxN];
void build(int l,int r,int index)
{
    tree[index].l=l;
    tree[index].r=r;
    if(l==r)return;
    int mid = ((r+l)>>1);
    build(l,mid,2*index);
    build(mid+1,r,2*index+1);
}
int frame_add(int index)
{
    if(tree[index].l==tree[index].r) return tree[index].val=nums[tree[index].l];
    else return tree[index].val=frame_add(index*2)+frame_add(index*2+1);
}
void add(int index,int pos,int val)
{
    tree[index].val+=val;
    if(tree[index].l==tree[index].r)return;
    else
    {
        if(pos<=tree[index*2].r)
            add(index*2,pos,val);
        else if(pos>=tree[index*2+1].l)
            add(index*2+1,pos,val);
    }
}
int Search(int index,int left,int right)
{
    if(tree[index].l>=left&&tree[index].r<=right)
    {
        return tree[index].val;
    }
    else
    {
        int ans(0);
        if(tree[index*2].r>=left)
        {
            ans+=Search(index*2,left,right);
        }
        if(tree[index*2+1].l<=right)
        {
            ans+=Search(index*2+1,left,right);
        }
        return ans;
    }
}
signed main()
{
    //ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    int size = (1<<(int)floor(log(n)/log(2)+2))-1;
    tree.resize(size+5);
    build(1,n,1);
    frame_add(1);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int pos,val;
            cin>>pos>>val;
            add(1,pos,val);
        }
        else if(type==2)
        {
            int left,right;
            cin>>left>>right;
            cout<<Search(1,left,right)<<endl;
        }
    }
    #ifdef DEBUG
    inc(i,1,size)
    {
        if(tree[i].l==0||tree[i].r==0)continue;
        cout<<tree[i].val<<endl;
    }
    cout<<"#"<<Search(1,2,5)<<endl;
    add(1,3,2);
    inc(i,1,size)
    {
        if(tree[i].l==0||tree[i].r==0)continue;
        cout<<tree[i].val<<endl;
    }
    cout<<"#"<<Search(1,2,5)<<endl;
    #endif
    system("pause");
}