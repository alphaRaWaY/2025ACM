#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
#define LOCAL
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e4+5),INF(0x3f3f3f3f);
int n,M[MAXN],nums[MAXN],ans1,ans2;
signed main()
{
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    #ifdef LOCAL
    freopen("input.txt","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	freopen("output.txt","w",stdout); //输出重定向，输出数据将保存在D盘根目录下的out.txt文件中 
    #endif
    while(cin>>nums[++n])
    #ifdef DEBUG
    {
        if(!nums[n])break;
    }
    #endif
    ;
    n--;
    M[0]=INF;
    inc(i,1,n)
    {
        int l(0),r(i+1);
        while(r-l>1)
        {
            int mid = ((l+r)>>1);
            if(M[mid]>=nums[i]) l=mid;
            else r=mid;
        }
        M[1+l] = nums[i];
        ans1=max(ans1,l+1);
    }
    cout<<ans1<<endl;
    memset(M,0,sizeof(M));
    reverse(nums+1,nums+n+1);
    #ifdef DEBUG
    inc(i,1,n)cout<<nums[i]<<" ";
    cout<<endl;
    #endif
    inc(i,1,n)
    {
        int l(0),r(i+1);
        while(r-l>1)
        {
            int mid = ((l+r)>>1);
            if(M[mid]>nums[i]) l=mid;
            else r=mid;
        }
        M[1+l] = nums[i];
        ans2=max(ans2,l+1);
    }
    cout<<ans2<<endl;
    system("pause");
}