#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int read()
{
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return f*x;
}
struct midUtil{
    multiset<int> q1;
    multiset<int> q2;
    
    void justify()
    {
        while(q1.size()>q2.size()+1)
        {
            int tmp=*--q1.end();
            auto t = q1.find(tmp);
            q1.erase(t),q2.insert(tmp);
        }
        while(q1.size()<q2.size())
        {
            int tmp=*q2.begin();
            auto t = q2.find(tmp);
            q2.erase(t),q1.insert(tmp);
        }
        
    }
    void insert_q(int p)
    {
        if(q1.empty()||p<=(*q2.begin())){
            q1.insert(p);
        } 
        else q2.insert(p);
        justify();
    }
    void erase_q(int q)
    {
        auto tmp1 = q1.find(q);
        auto tmp2 = q2.find(q);
        if(tmp1!=q1.end()) {
            q1.erase(tmp1);
        }
        else q2.erase(tmp2);
        justify();
    }
    int getMid()
    {
        return *--q1.end();
    }
    void clear(){
        q1.clear();
        q2.clear();
    }
}MM;
const int MaxN(2005);
int nums[MaxN],mid[MaxN][MaxN];
int n;
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    inc(i,1,n)
    {
        MM.clear();
        for(int j(i);j<=n;j+=2)
        {
            MM.insert_q(nums[j]);
            if(j!=i)MM.insert_q(nums[j-1]);
            mid[i][j]=mid[j][i]=MM.getMid();
        }
    }
    int ans(0);
    inc(i,1,n)
    {
        for(int j(i);j<=n;j+=2)
        {
            ans+=i*j*mid[i][j];
        }
    }
    cout<<ans<<endl;
    // inc(i,1,n){
    //     inc(j,1,n)cout<<mid[i][j]<<" ";cout<<endl;
    // }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    // cin>>_;
    _=read();
    while(_--)solve();
}

/*
3
20
20 19 9 10 11 2 18  3 12 1 8 13 4 7 14 5 16 6 15 17
7
5 1 3 2 7 4 6
5
1 2 5 4 3
*/
