#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
map<int,int> ys[MaxN];
int n,k;
// 维护最大值的线段树
struct ST_MX
{
    // 树的大小
    int sz;
    // 树维护的数组
    // 各个结点的最大值
    // 各个结点的左端点
    // 各个结点的右端点
    // 各个结点的懒标签
    vector<int> nums,mx,l,r,tag;
    int ls(int a){return a<<1;}
    int rs(int a){return a<<1|1;}
    void push_down(int index)
    {
        mx[ls(index)]+=tag[index];
        mx[rs(index)]+=tag[index];
        tag[ls(index)]+=tag[index];
        tag[rs(index)]+=tag[index];
        tag[index]=0;
    }
    void push_up(int index)
    {
        mx[index]=max(mx[ls(index)],mx[rs(index)]);
    }
    void build(int index,int L,int R)
    {
        l[index]=L;
        r[index]=R;
        if(L==R)
        {
            mx[index]=nums[L-1];
            return;
        }
        int mid(((R-L)>>1)+L);
        build(ls(index),L,mid);
        build(rs(index),mid+1,R);
        push_up(index);
    }
    void update(int index,int L,int R,int val)
    {
        if(r[index]<L||l[index]>R)return;
        if(r[index]<=R&&l[index]>=L)
        {
            mx[index]+=val;
            tag[index]+=val;
            return;
        }
        push_down(index);
        update(ls(index),L,R,val);
        update(rs(index),L,R,val);
        push_up(index);
    }
    int query(int index,int L,int R)
    {
        if(r[index]<L||l[index]>R)return 0;
        if(r[index]<=R&&l[index]>=L)
        {
            return mx[index];
        }
        int ans(0);
        push_down(index);
        ans=query(ls(index),L,R);
        ans=max(ans,query(rs(index),L,R));
        return ans;
    }
    /**
     * 构造函数
     * @param a 下标从0开始的数组
     */
    ST_MX(vector<int> a)
    {
        sz=a.size();
        nums=a;
        mx.resize((sz+1)<<2);
        tag.resize((sz+1)<<2);
        l.resize((sz+1)<<2);
        r.resize((sz+1)<<2);
        build(1,1,sz);
    }
};
int cal(int width,int height)
{
    // 此处ST_MX维护的nums[y]是y-weight+1~y的价值总和
    ST_MX tree(vector<int>(n,0));
    int ans(0);
    inc(i,1,n)
    {
        if(i-height>=1)
        {
            for(auto[y,weight]:ys[i-height])tree.update(1,y,y+width-1,-weight);
        }
        for(auto[y,weight]:ys[i])tree.update(1,y,y+width-1,weight);
        ans=max(ans,tree.mx[1]);
    }
    return ans;
}
void solve()
{
    cin>>n>>k;
    int ans(0);
    inc(i,1,n)ys[i].clear();
    inc(i,1,n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ys[a][b]+=c;
    }
    inc(i,1,sqrt(k))
    {
        ans=max(ans,cal(i,k/i));
        if(i!=k/i)
            ans=max(ans,cal(k/i,i));
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}