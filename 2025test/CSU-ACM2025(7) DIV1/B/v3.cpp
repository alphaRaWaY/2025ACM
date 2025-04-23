#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5),MAXK(2e5+5);
struct node
{
    int x,y,z,ans,w;
    void print()
    {
        cout<<x<<" "<<y<<" "<<z<<" "<<ans<<" "<<w<<endl;
    }
    bool  operator < (const node& n)const 
    {
        if(x==n.x)
        {
            if(y==n.y)
            {
                return y<n.y;
            }
            else return z<n.z;
        }
        else return x<n.x;
    }
};
node a[MAXN];
map<node,int> in;
int n,k,z;
int cnt[MAXN];
struct TREE
{
    int tre[MAXK],kk;
    int lowbit(int x)
    {
        return x&(-x);
    }
    int ask(int i)
    {
        int ans=0;
        for(; i; i-=lowbit(i))
        {
            ans+=tre[i];
        }
        return ans;
    }
    void add(int i,int k)
    {
        for(; i<=kk; i+=lowbit(i))
        {
            tre[i]+=k;
        }
    }
} t;
bool cmp(node u,node v)
{
    if(u.y==v.y)
        return u.z<v.z;
    return u.y<v.y;
}
void cdq(int l,int r)
{
    if(l>=r)return;
    int mid(((r-l)>>1)+l);
    cdq(l,mid);
    cdq(mid+1,r);
    sort(a+l,a+mid+1,cmp);
    sort(a+mid+1,a+r+1,cmp);
    int i(mid+1),j(l);
    while(i<=r)
    {
        while(a[j].y<=a[i].y && j<=mid)
        {
            t.add(a[j].z,a[j].w);
            j++;
        }
        a[i].ans+=t.ask(a[i].z);
        i++;
    }
    inc(i,l,j-1)
    {
        t.add(a[i].z,-a[i].w);
    }
}
void solve()
{
    cin>>z>>k;
    t.kk=k;
    inc(i,1,z)
    {
        node tmp;
        cin>>tmp.x>>tmp.y>>tmp.z;
        in[tmp]++;
    }
    n=in.size();
    int index(1);
    for(auto [aa,bb]:in)
    {
        node tmp(aa);
        tmp.w=bb;
        tmp.ans=0;
        a[index]=tmp;
        index++;
    }
    // inc(i,1,n)cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    cdq(1,n);
    inc(i,1,n)
    {
        a[i].print();
        cnt[a[i].ans+a[i].w-1]+=a[i].w;
    }
    inc(i,0,z-1)
    {
        cout<<cnt[i]<<endl;
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