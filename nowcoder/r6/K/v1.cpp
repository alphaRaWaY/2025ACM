// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define ri int
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int T, n, s, ans, a[N], b[N], d[N], pre[N], suf[N];
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
void deal(int x)
{
	int cnt1 = 0, res = 0;
	for(ri i = 1; i <= n; i++) b[i] = d[i] % x;
	for(ri i = 1; i <= n; i++)
	{
		if(b[i] == 0) cnt1++;
		else res += b[i];
	}
	if(cnt1 != n - 2) return;
	else
	{
		if(res % x == 0) ans = max(ans, x);
		return;
	}
}
void solve()
{
	ans = 1; a[0] = 0;
	scanf("%d", &n);
	for(ri i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		d[i] = a[i] - a[i - 1];
	}
	
	if(n == 1)
	{
		printf("0\n");
		return;
	}
	if(n == 2)
	{
		if(a[1] == a[2]) printf("0\n");
		else printf("%d\n", max(a[1], a[2]));
		return;
	}
	bool bk=false;
	for(ri i = 1; i <= n - 1; i++)
		if(a[i] != a[i + 1])
		{
			bk = true;
			break;
		}
	if(!bk)
	{
		printf("0\n");
		return;
	}
	
	s = a[n];
	for(ri i = 1; i <= (int)sqrt(s) + 1; i++)
		if(s % i == 0)
		{
			//printf("%d\n",i);
			deal(i);
			deal(s / i);
		}
	
	pre[0] = d[1], suf[n + 1] = d[n];
	for(ri i = 1; i <= n; i++) pre[i] = gcd(pre[i - 1], d[i]);
	for(ri i = n; i >= 1; i--) suf[i] = gcd(suf[i + 1], d[i]);
	for(ri i = 1; i <= n; i++)
	{
		if(i == 1)
		{
			ans = max(ans, suf[i + 1]);
		}
		else if(i == n)
		{
			ans = max(ans, pre[i - 1]);
		}
		else
		{
			ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}