#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100010
#define maxk 200010
using namespace std;
struct node
{
    int x,y,z,ans,w;
};
node a[maxn],b[maxn];
int n,cnt[maxk];
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
    int tre[maxk],kk;
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
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(a+l,a+mid+1,cmp2);
    sort(a+mid+1,a+r+1,cmp2);
    int i=mid+1,j=l;
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
    for(i=l; i<j; i++)
    {
        t.add(a[i].z,-a[i].w);
    }
}
int main()
{
    scanf("%d%d",&z,&k);
    t.kk=k;
    for(int i=1; i<=z; i++)
    {
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
    }
    sort(b+1,b+z+1,cmp1);
    int c=0;
    for(int i=1; i<=z; i++)
    {
        c++;
        if(b[i].x!=b[i+1].x || b[i].y!=b[i+1].y || b[i].z!=b[i+1].z )
            a[++n]=b[i],a[n].w=c,c=0;
    }
    cout<<"#"<<n<<endl;
    for(int i(1);i<=n;i++)cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    cdq(1,n);
    for(int i=1; i<=n; i++)
    {
        cnt[a[i].ans+a[i].w-1]+=a[i].w;
    }
    for(int i=0; i<z; i++)
    {
        printf("%d\n",cnt[i]);
    }
    system("pause");
    return 0;
}