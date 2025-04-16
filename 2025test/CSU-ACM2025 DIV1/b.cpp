#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m,k;
/**
 * @param n1 剩余未连接的点数
 * @param n2 可以连接的点数
 * @param n3 将来可能可以连接的点数
 * @param ed 剩余的边数
 */
int getL(int n1,int n2,int n3,int ed)
{
    if(ed<=0)return 0;
    int l(0),r(n1+1);
    while(r-l>1)
    {
        int mid(((r-l)>>1)+l);
        if(mid*(mid-1)/2>ed)r=mid;
        else l=mid;
    }
    int result=l;//能连接的凸包的最大点数
    if(l<=1)return 0;
    //如果剩下最后一个可连接的点
    if(n2==1)
    {
        return getL(n1-(l-1),n3+(l-1),0,ed-l*(l-1)/2);
    }
    //如果没有将来可能可以连接的点
    else if(n3)
    {
        return getL(n1-(l-1),n2-1,l-1,ed-l*(l-1)/2)+1;
    }
    //一般情况
    else
    {
        return getL(n1-(l-1),n2-1,l-1,ed-l*(l-1)/2);
    }
}
void solve()
{
    cin>>n>>m>>k;
    if(n-1>m||m>(n-1)*n/2){
        cout<<"NO"<<endl;
        return;
    }
    int ans = getL(n-1,1,0,m);
    if(ans>k)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}

/*
100
1 0 3
4 5 3
4 6 3
5 4 1
2 1 1

*/