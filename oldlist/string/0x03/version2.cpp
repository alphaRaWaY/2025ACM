// Problem: P3538 [POI2012] OKR-A Horrible Poem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3538
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 卡常数，质因数分解
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
const int INF(0x3f3f3f3f),mod1(137),mod2(149);
string int128ToString(__int128 x) {
  if (x == 0) return "0";
  string result;
  bool is = x < 0;
  if (is) x = -x;
  while (x > 0) {
    result.push_back('0' + (x % 10));
    x /= 10;
  }
  if (is) result.push_back('-');
  reverse(result.begin(), result.end());
  return result;
}
const int MaxN(5e5+5),base(mod1),mod(1e9+7);
int n,q;
char s[MaxN];
bool vis[MaxN];
int minP[MaxN],ha[MaxN],p[MaxN];
vector<int> primes;
void getP()
{
	inc(i,2,n)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			vis[i]=true;
			minP[i]=i;
		}
		for(int tmp:primes)
		{
			if(tmp*i>n)break;
			vis[tmp*i]=true;
			minP[tmp*i]=tmp;
			if(i%tmp==0)break;
		}
	}
}
int getH(int l,int r)
{
	return (ha[r]-ha[l-1]*p[r-l+1]%mod+mod*base)%mod;
}
signed main() {
  ios::sync_with_stdio(false);
	scanf("%lld%s%lld",&n,s+1,&q);
	getP();
	p[0]=1;
	inc(i,1,n)
	{
		p[i]=(p[i-1]*base)%mod;
		ha[i]=(ha[i-1]*base+s[i]-'a'+1)%mod;
		// cout<<ha[i]<<" "<<(ha[i]-ha[i-1]*base+mod*base)%mod<<endl;
	}
	while(q--)
	{
		int l,r,ans,len;
		scanf("%lld%lld",&l,&r);
		len=ans=r-l+1;
		if(getH(l,r-1)==getH(l+1,r))
		{
			cout<<1<<endl;
			continue;
		}
		while(len>1)
		{
			int temp=ans/minP[len];
			if(getH(l,r-temp)==getH(l+temp,r))
			{
				ans=temp;
			}			
			len/=minP[len];
		}
		cout<<ans<<endl;
	}
}