//乘法逆元
//费马小定理
//超时

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int fast_pow(int a,int b,int p)
{
    int ans(1);
    while(b > 0)
    {
		if(b & 1)
        {
			ans *= a;
            ans %= p;
    	}
		
        a *= a;
        a %= p;
		b >>= 1;
	}
    return ans;
}
signed main()
{
    //ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    inc(_,1,n)
    {
        cout<<fast_pow(_,p-2,p)<<endl;
    }
    system("pause");
}
