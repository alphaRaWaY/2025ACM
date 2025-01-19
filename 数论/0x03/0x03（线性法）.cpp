//线性法求逆元
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(3e6+5);
int inv[MaxN];
void inver(int n,int mod)
{
    inv[1]=1;
    inc(i,2,n)
    {
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    inver(n,p);
    inc(_,1,n)
    {
        cout<<inv[_]<<endl;
    }
    system("pause");
}
