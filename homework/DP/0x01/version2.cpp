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
int n,L;
int nums[MaxN],S[MaxN],dp[MaxN];
int X(int i)
{
    return S[i];
}
int Y(int i)
{
    return dp[i]+(S[i]+L)*(S[i]+L);
}
int B(int index,int i)
{
    return Y(index)-2*S[i]*X(index);
}
void solve()
{
    cin>>n>>L;
    inc(i,1,n)
    cin>>nums[i];
    partial_sum(nums+1,nums+1+n,S+1);
    dp[1]=(nums[1]-L)*(nums[1]-L);
    L++;
    inc(i,1,n)S[i]+=i;
    // inc(i,1,n)cout<<S[i]<<' ';cout<<endl;
    inc(i,2,n)
    {
        int pos(0);

        // int m(INF);
        // inc(j,1,i)
        // {
        //     if(B(j,i)<m)
        //     {
        //         m=B(j,i);
        //         pos=j;
        //     }
        // }

        int l(1),r(i);
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(B(mid,i)<B(mid+1,i))r=mid;
            else l=mid;
        }
        pos=l;
        if(B(l,i)>B(r,i)&&r<n)pos=r;

        cout<<pos<<endl;

        dp[i]=dp[pos]+(S[i]-S[pos]-L)*(S[i]-S[pos]-L);
    }
    cout<<dp[n]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    // system("pause");
}
/*
5 4
3
4
2
1
4
*/

/*
1
2
2
4
*/