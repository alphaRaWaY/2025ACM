#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2005);
int ll[MaxN][MaxN],rr[MaxN][MaxN];
int n;
int nums[MaxN];
void solve()
{
    cin>>n;
    inc(i,1,n)inc(j,1,n){ll[i][j]=0;rr[i][j]=MaxN;}
    inc(i,1,n){ll[i][0]=rr[i][0]=i;}
    inc(i,1,n)cin>>nums[i];
    inc(i,1,n)
    {
        int cntl(0),cntr(0);
        dec(j,i-1,1)
            if(nums[j]<=nums[i])ll[i][++cntl]=j;
        inc(j,i+1,n)
            if(nums[j]<=nums[i])rr[i][++cntr]=j;
    }
    int ans(0);
    inc(i,1,n)  
    inc(j,1,n)
    {
        if(!ll[i][j])break;
        int greater = i-ll[i][j]-j;
        if(greater==j)ans+=(ll[i][j]*i*nums[i]);
        
    }
    inc(j,0,n-1)
    {
        inc(i,1,n)cout<<ll[i][j]<<' ';cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}

/*
2
3
1 3 2
5
2 3 1 5 4
*/