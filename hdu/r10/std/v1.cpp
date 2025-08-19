#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m;
/**
 * 欧拉筛
 * @param n 筛选质数最大不超过n
 */
vector<int> primes,pp;//质数、最小质因子
void initPrime(int n)
{
    primes.clear();
    pp.assign(n+5,0);
    inc(i,2,n)
    {
        if(!pp[i])primes.push_back(i);
        for(int tmp:primes)
        {
            if(tmp*i>n)break;
            pp[tmp*i]=tmp;
            if(i%tmp==0)break;
        }
    }
}
const int MaxN(5e5+5);
int degree[MaxN];
vector<int> order;
void dfs(int index,int val)
{
    if(val>n)return;
    if(index<0)
    {
        order.push_back(val);
        return;
    }
    int tmp(1);
    inc(i,0,degree[index])
    {
        dfs(index-1,val*tmp);
        tmp*=primes[index];
    }
}
void solve()
{
 
}
void test()
{
    cin>>n;
    initPrime(n);
    inc(i,0,primes.size()-1)degree[i]=log(n)/log(primes[i]);
    dfs(primes.size()-1,1);
    // for(int tmp:order)printf("%3d",tmp);cout<<endl;
    for(int check:order)
    {
        for(int tmp:order)
        {
            if(tmp%check==0)printf("%4d",tmp/check);
            else printf("    ");
        }
        cout<<endl;
    }
    
}
signed main()
{
    test();
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    return 0;
}