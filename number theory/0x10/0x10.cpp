//恶心，卡人long long
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
const int MAXN(15);
int x;
int a[MAXN],n[MAXN];
__int128 m[MAXN],c[MAXN];
void solve()
{
    int total(1);
    cin>>x;
    inc(i,1,x)
    {
        cin>>n[i]>>a[i];
        total*=n[i];
    }
    inc(i,1,x)
    {
        m[i]=total/n[i];
        c[i]=m[i]*getver(m[i],n[i]);
    }
    int ans(0);
    // inc(i,1,x)cout<<a[i]*c[i]<<" ";cout<<endl;
    inc(i,1,x)
    {
        ans=(c[i]*a[i]%total+ans)%total;
    }
    cout<<(ans%total+total)%total<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
3
3 1
5 1
7 2
*/

/*
3
99991 99990
99989 99988
99971 99970
*/