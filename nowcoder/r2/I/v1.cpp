#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int a,b;
void solve()
{
   cin>>a>>b;
   if(a==1||b==1)
   {
        cout<<-1<<endl;
   }
   else
   {
        cout<<1<<endl;
   }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}