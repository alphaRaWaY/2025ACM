#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define endl '\n'

const int MaxN(4e5+5);
int n,L;
int nums[MaxN],dp[MaxN],S[MaxN];
int X(int j){return S[j];}
int Y(int j){return dp[j]+(S[j]+L)*(S[j]+L);}
int B(int j,int i){return Y(j)-2*S[i]*X(j);}
void solve()
{
    cin>>n>>L;
    inc(i,1,n)cin>>nums[i];
    partial_sum(nums+1,nums+1+n,S+1);
    dp[1]=(nums[1]-L)*(nums[1]-L);
    inc(i,1,n)S[i]+=i;
    L++;

    inc(i,2,n)
    {
        int l(1),r(i-1),j;
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(B(mid+1,i)>B(mid,i))r=mid;
            else l=mid;
        }
        j=(B(r,i)>B(l,i)?l:r);
        dp[i]=dp[j]+(S[i]-S[j]-L)*(S[i]-S[j]-L);
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
