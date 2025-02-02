//乘法逆元
//拓展欧几里得
//超时
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
void exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        exgcd(b,a%b,x,y);
        int tmp = x;
        x = y;
        y = tmp-(a/b)*y;
    }
}
int getver(int a,int mod)
{
    int x,y;
    exgcd(a,mod,x,y);
    //cout<<x<<" "<<y<<endl;
    x=(mod+x%mod)%mod;
    return x;
}
signed main()
{
    ios::sync_with_stdio(false);
    int n,p;
    while(cin>>n>>p)
    inc(i,1,n)cout<<getver(i,p)<<endl;
    system("pause");
}