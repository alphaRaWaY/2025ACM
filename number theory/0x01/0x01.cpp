//快速幂，把幂转化为二进制进行相乘

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define d lld
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
    ios::sync_with_stdio(false);
    int a,b,p;
    cin>>a>>b>>p;
    printf("%d^%d mod %d=%d\n",a,b,p,fast_pow(a,b,p));
    system("pause");
}