#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m,k;
void solve()
{
    int ans;
    cin>>n>>m>>k;
    if(n-1>m||m>(n-1)*n/2){
        cout<<"NO"<<endl;
        return;
    }
    else if(m==(n-1)*n/2)ans=2;
    else ans=3;
    ans=min(ans,n);
    if(ans<k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}

/*
100
1 0 3
4 5 3
4 6 3
5 4 1
2 1 1
100
1000000001 1000000000 4
1000000000 1000000000 3
1000000000 1000000000 2
1000000000 1000000000 5
1000000000 1000000000 6
1000000000 1000000000 7
1000000000 1000000000 8
*/