#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e8+5);
vector<int> primes;
bool vis[MaxN];
signed main()
{ 
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    inc(i,2,n)
    {
        if(!vis[i])
        {
            primes.push_back(i);
            for(int j(i);j<=n;j+=i)
            {
                vis[j]=true;
            }
        }
    }
    for(int tmp:primes)
    cout<<tmp<<" ";cout<<endl;
    while(q--)
    {
        int t;
        cin>>t;
        cout<<primes[t-1]<<endl;
    }
    system("pause");
}