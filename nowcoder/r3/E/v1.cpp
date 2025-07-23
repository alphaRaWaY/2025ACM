#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e6+5),MaxA(5e6+5);
vector<int> primes,nums;
int pp[MaxA];
int n;
void getPrimes()
{
    pp[1]=1;
    // cout<<"ciallo world!"<<endl;
    inc(i,2,MaxA-5)
    {
        if(!pp[i]){
            primes.push_back(i);
            pp[i]=i;
        }
        for(int tmp:primes)
        {
            if(tmp*i>=MaxA)break;
            pp[tmp*i]=tmp;
            if(i%tmp==0)break;
        }
        // cout<<i<<endl;
    }
}
map<int,int>cnt;
void solve()
{
    cnt.clear();
    cin>>n;
    nums.resize(n+1);
    inc(i,1,n)cin>>nums[i];
    if(n&1)cout<<"YES"<<endl;
    else if(n==2)cout<<(nums[1]==nums[2]?"YES":"NO")<<endl;
    else
    {
        inc(i,1,n){
            int tmp = nums[i];
            while(tmp!=1){
                cnt[pp[tmp]]++;
                tmp/=pp[tmp];
            }
        }
        for(auto[x,y]:cnt)
        {
            if(y&1)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
}
signed main()
{
    getPrimes();
    // int tmp;
    // while(cin>>tmp)
    // {
    //     do{
    //         // cnt[pp[tmp]]++;
    //         cout<<pp[tmp]<<" ";
    //         tmp/=pp[tmp];
    //     }while(tmp!=1);
    //     cout<<endl;
    // }
    ios::sync_with_stdio(false);
    
    int _;
    cin>>_;
    while(_--)solve();
}