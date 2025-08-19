#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ri int
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
const ll INF = 1e18;
ll T, n, m, x, v, a[N];
struct tree
{
	ll l, r;
	ll c[5][5];
} tr[4 * N];
inline ll read()
{
	ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+(c&15),c=getchar());
	return x*f;
}
void print(ll x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}
inline void init(ll now)
{
	for(ri i = 0; i <= 3; i++)
		for(ri j = 0; j <= 3; j++)
			tr[now].c[i][j] = -INF;
}
inline void pushup(ll now, ll l, ll r)
{
	if(r - l + 1 > 3)
	{
		if(tr[now << 1].r - tr[now << 1].l + 1 == 2 && tr[now << 1 | 1].r - tr[now << 1 | 1].l + 1 == 2)
		{
			tr[now].c[0][0] = a[l + 1] + a[r - 1];
			tr[now].c[0][1] = a[l + 1] + a[r];
			tr[now].c[0][2] = a[r - 1] + a[r];
			tr[now].c[0][3] = a[r - 2] + a[r - 1] + a[r];
					
			tr[now].c[1][0] = a[l] + a[l + 2];
			tr[now].c[1][1] = a[l] + a[r];
			tr[now].c[1][2] = a[l] + a[r - 1] + a[r];
					
			tr[now].c[2][0] = a[l] + a[l + 1];
			tr[now].c[2][1] = a[l] + a[l + 1] + a[r];
					
			tr[now].c[3][0] = a[l] + a[l + 1] + a[l + 2];
		}
		else if(tr[now << 1].r - tr[now << 1].l + 1 == 2 || tr[now << 1 | 1].r - tr[now << 1 | 1].l + 1 == 2)
		{
			tr[now].c[0][0] = a[l + 1] + a[l + 2] + a[l + 3];
			tr[now].c[0][1] = a[l + 1] + a[l + 2] + a[r];
			tr[now].c[0][2] = a[l + 1] + a[r - 1] + a[r];
			tr[now].c[0][3] = a[r - 2] + a[r - 1] + a[r];
					
			tr[now].c[1][0] = a[l] + a[r - 2] + a[r - 1];
			tr[now].c[1][1] = a[l] + a[l + 2] + a[r];
			tr[now].c[1][2] = a[l] + a[r - 1] + a[r];
			tr[now].c[1][3] = a[l] + a[r - 2] + a[r - 1] + a[r];
					
			tr[now].c[2][0] = a[l] + a[l + 1] + a[r - 1];
			tr[now].c[2][1] = a[l] + a[l + 1] + a[r];
			tr[now].c[2][2] = a[l] + a[l + 1] + a[r - 1] + a[r];
			tr[now].c[2][3] = -INF;
					
			tr[now].c[3][0] = a[l] + a[l + 1] + a[l + 2];
			tr[now].c[3][1] = a[l] + a[l + 1] + a[l + 2] + a[r];
		}
		else
		{
			ll res = -INF;
			for(ri x = 0; x <= 3; x++)
				for(ri y = 0; y <= 3; y++)
				{
					for(ri i = 0; i <= 3; i++)
						for(ri j = 0; j <= 3 - i; j++)
							res = max(res, tr[now << 1].c[x][i] + tr[now << 1 | 1].c[j][y]);
					tr[now].c[x][y] = res;		
				}
		}
	}
	else if(r - l + 1 == 3)
	{
		if(tr[now << 1].l == tr[now << 1].r) //左1 右2
		{
			tr[now].c[0][0] = a[(l + r) / 2];
			tr[now].c[0][1] = tr[now << 1 | 1].c[0][1];
			tr[now].c[0][2] = a[r - 1] + a[r];
			
			tr[now].c[1][0] = tr[now << 1].c[1][1];
			tr[now].c[1][1] = tr[now << 1].c[1][1] + tr[now << 1 | 1].c[0][1];
			
			tr[now].c[2][0] = tr[now << 1].c[1][1] + tr[now << 1 | 1].c[1][0];
		}
		else //左2 右1
		{
			tr[now].c[0][0] = a[(l + r) / 2];
			tr[now].c[0][1] = tr[now << 1 | 1].c[1][1];
			tr[now].c[0][2] = tr[now << 1].c[0][1] + tr[now << 1 | 1].c[1][1];
			
			tr[now].c[1][0] = tr[now << 1].c[1][0];
			tr[now].c[1][1] = tr[now << 1].c[1][0] + tr[now << 1 | 1].c[1][1];
			
			tr[now].c[2][0] = a[l] + a[l + 1];
		}
	}
	else if(r - l + 1 == 2)
	{
		tr[now].c[1][0] = tr[now << 1].c[1][1];
		tr[now].c[0][1] = tr[now << 1 | 1].c[1][1];
	}
}
inline void nbuild(ll now, ll l, ll r)
{
	init(now);
	tr[now].l = l, tr[now].r = r;
	if(l == r) return;
	ll mid = (l + r) >> 1;
	nbuild(now << 1, l, mid), nbuild(now << 1 | 1, mid + 1, r);
}
inline void build(ll now, ll l, ll r)
{
	tr[now].l = l, tr[now].r = r;
	if(l == r)
	{
		tr[now].c[1][1]=a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(now << 1, l, mid), build(now << 1 | 1, mid + 1, r);
	pushup(now, l, r);
}
inline void update(ll ux, ll k, ll now, ll l, ll r)
{
	if(l == r)
	{
		tr[now].c[1][1] = k;
		return;
	}
	ll mid = (l + r) >> 1;
	if(ux <= mid) update(ux, k, now << 1, l, mid);
	if(ux > mid) update(ux, k, now << 1 | 1, mid + 1, r);
	pushup(now, l, r);
}
inline ll get()
{
	ll res = -INF;
	for(ri i = 0; i <= 3; i++)
		for(ri j = 0; j <= 3 - i; j++)
			res = max(res, tr[1].c[i][j]);
	return res;
}
void solve()
{
	n = read(), m = read();
	nbuild(1, 1, n);
	for(ri i = 1; i <= n; i++) a[i] = read();
	build(1, 1, n);
	print(get()); printf("\n");
	for(ri i = 1; i <= m; i++)
	{
		x = read(), v = read();
		a[x] = v;
		update(x, v, 1, 1, n);
		print(get()); printf("\n");
	}
}
int main()
{
	T = read();
	while(T--) solve();
	return 0;
}
/*

1
4 10
1 2 1 2 
1 5
5 1
3 1

*/