#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5),MAXK(2e5+5);
struct node
{
    int x,y,z,ans,w;
};
node a[MAXN],b[MAXN];
int n,cnt[MAXK];
int k,z;
bool cmp1(node u,node v)
{
    if(u.x==v.x)
    {
        if(u.y==v.y)
            return u.z<v.z;
        return u.y<v.y;
    }
    return u.x<v.x;
}
bool cmp2(node u,node v)
{
    if(u.y==v.y)
        return u.z<v.z;
    return u.y<v.y;
}
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
void cdq(int l,int r)
{
    if(l==r)
    {
        return;
    }
    int mid(((r-l)>>1)+l);
    cdq(l,mid);
    cdq(mid+1,r);
    sort(a+l,a+mid+1,cmp2);
    sort(a+mid+1,a+r+1,cmp2);
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
        cin>>b[i].x>>b[i].y>>b[i].z;
    }
    sort(b+1,b+z+1,cmp1);
    int c(0);
    inc(i,1,z)
    {
        c++;
        if(b[i].x!=b[i+1].x || b[i].y!=b[i+1].y || b[i].z!=b[i+1].z )
            a[++n]=b[i],a[n].w=c,c=0;
    }
    // cout<<"#"<<n<<endl;
    // for(int i(1);i<=n;i++)cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    cdq(1,n);
    inc(i,1,n)
    {
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