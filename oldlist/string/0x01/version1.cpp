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
signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  string s;
  set<string> ss;
  inc(i,1,n)
  {
    cin>>s;ss.insert(s);
  }
  cout<<ss.size()<<endl;
  system("pause");
}