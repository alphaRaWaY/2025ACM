//使用树状数组求前缀和

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5);
int n,q,origin[MAXN],nums[MAXN],tree[MAXN];
void update(int index,int val)
{
    while(index<=n)
    {
        tree[index]+=val;
        index+=index&-index;
    }
}
void build()
{
    inc(i,1,n)update(i,nums[i]);
}
int sum(int index)
{   
    int res(0);
    while(index)
    {
        res+=tree[index];
        index-=index&-index;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    inc(i,1,n)cin>>origin[i];
    inc(i,1,n)nums[i]=origin[i]-origin[i-1];
    build();
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            update(x,k);
            if(y+1<=n)
            update(y+1,-k);
        }
        else
        {
            int index;
            cin>>index;
            cout<<sum(index)<<endl;
        }
    } 
    system("pause");
}