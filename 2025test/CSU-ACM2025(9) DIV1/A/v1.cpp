#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int a[MAXN],b[MAXN];
vector<int> v1,v2;
int n,m;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>a[i];
    inc(i,1,m)cin>>b[i];
    inc(i,1,n)
    {
        if(a[i]==b[v1.size()+1])
        {
            v1.push_back(i);
            if(v1.size()>=m)break;
        }
    }
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+m);
    inc(i,1,n)
    {
        if(a[i]==b[v2.size()+1])
        {
            v2.push_back(i);
            if(v2.size()>=m)break;
        }
    }
    for(int &tmp:v2)tmp=n+1-tmp;
    reverse(v2.begin(),v2.end());
    // for(int tmp:v1)cout<<tmp<<" ";cout<<endl;
    // for(int tmp:v2)cout<<tmp<<" ";cout<<endl;
    if(v1.size()<m||v2.size()<m||v1==v2)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    while(_--)solve();
}
/*
4 2
1 2 1 2
1 2
*/