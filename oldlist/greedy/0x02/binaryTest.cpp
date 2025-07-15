#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5);
int nums[MAXN],n;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    sort(nums+1,nums+1+n);
    int check;
    while(cin>>check)
    {
        int l(0),r(n+1);
        while(r-l>1){
            int mid((l+r)/2);
            if(check>nums[mid])l=mid;
            else r=mid;
        }
        cout<<l<<endl;
    }
    system("pause");
}