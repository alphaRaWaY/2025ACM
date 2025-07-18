#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int read()
{
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return f*x;
}
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
const int MaxN(425);
int n;
int nums[MaxN];
struct node{
    int l,r,val;
}tree[MaxN*4];

void solve()
{
    n=read();
    inc(i,1,n)
    {
        nums[i]=read();
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    // cin>>_;
    _=read();
    while(_--)solve();
}