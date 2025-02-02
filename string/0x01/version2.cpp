// Problem: P3370 【模板】字符串哈希
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 单哈希
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
const int INF(0x3f3f3f3f);
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
void write(long long x)        
{        
  if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);        
  putchar(x%10+'0');        
  return;        
}
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f * x;
}
const int mod(1e9+7),MaxN(1e4+5),base(2);
int hases[MaxN];
int gethas(string s)
{
	int res(0);
	for(char c:s)
	{
		res=(res*base+c)%mod;
	}
	return res;
}
signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  string s;
  inc(i,1,n)
  {
  	cin>>s;
  	hases[i]=gethas(s);
  }
  sort(hases+1,hases+n+1);
  //inc(i,1,n)cout<<hases[i]<<" ";cout<<endl;
  int ans(0);
  inc(i,1,n-1)
  {
  	if(hases[i+1]!=hases[i])ans++;	
  }
  cout<<ans+1<<endl;
}