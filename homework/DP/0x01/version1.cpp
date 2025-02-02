//  url:https://www.luogu.com.cn/problem/P3195

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int INF(0x3f3f3f3f);
const int MaxN(5e4+5);
int n,l;
int nums[MaxN],S[MaxN],dp[MaxN];
int getX(int i)
{
    return 2*S[i];
}
int getY(int i)
{
    return dp[i]+S[i]*S[i]+2*l*S[i];
}
double getK(int i,int j)
{
    return (getY(j)-getY(i))*1.0/(getX(j)-getX(i));
}
void solve()
{
    cin>>n>>l;
    inc(i,1,n)cin>>nums[i];
    partial_sum(nums+1,nums+n+1,S+1);
    
    //prepare
    dp[1]=(nums[1]-l)*(nums[1]-l);
    inc(i,1,n)S[i]+=i;
    l++;
    //fill
    inc(i,2,n)
    {
        int l(1),r(i-1),j;
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(getK(mid+1,mid)<=S[i])r=mid;
            else l=mid;
        }
        j=getK(r,l)>S[i]?l:r;
        dp[i]=dp[j]+(S[j]-S[i]-l)*(S[j]-S[i]-l);
    }
    inc(i,1,n)cout<<dp[i]<<endl;
    cout<<dp[n]<<endl;
    // inc(i,1,n)cout<<S[i]<<" ";cout<<endl;
}

signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}
/*
5 4
3
4
2
1
4
*/