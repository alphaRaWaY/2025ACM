//使用树状数组实现

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5);
int n,q,nums[MAXN],tree[MAXN];
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
    inc(i,1,n)
    {
        update(i,nums[i]);
    }
}
int sum(int n)
{
    int res(0);
    while(n)
    {
        res+=tree[n];
        n-=n&-n;
    }
    return res;
}
int search(int l,int r)
{
    return sum(r)-sum(l-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    inc(i,1,n) cin>>nums[i];
    build();
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int index,val;
            cin>>index>>val;
            update(index,val);
        }
        else
        {
            int left,right;
            cin>>left>>right;
            cout<<search(left,right)<<endl;
        }
    }
    system("pause");
}