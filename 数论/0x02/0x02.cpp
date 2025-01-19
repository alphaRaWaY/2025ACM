//欧拉线性筛模板
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e8+5);
int n,q;
vector<int> primes;
bool vis[MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    inc(i,2,n)
    {
        if(!vis[i])primes.push_back(i);
        for(int tmp:primes)
        {
            if(tmp*i>n)break;
            vis[tmp*i]=1;
            if(i%tmp==0)break;
        }
    }
    while(q--)
    {
        int tmp;
        cin>>tmp;
        cout<<primes[tmp-1]<<endl;
    }
    system("pause");
}