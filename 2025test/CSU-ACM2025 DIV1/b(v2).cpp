#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m,k;
/**
 * 发现能拓展的最大团
 * @param n 可用点数
 * @param l 剩余边数
 * @param used 用于产生闭包的点数
 */
bool check(int n,int ed,int used)
{
    ed-=used*(used+1)/2;
    n-=used;
    if(ed<n)return false;
    else return true;
}
/**
 * 发现能拓展的最大团
 * @param n 可用点数
 * @param l 剩余边数
 */
int findbag(int n,int ed)
{
    int l(0),r(n+1);
    while(r-l>1)
    {
        int mid(((r-l)>>1)+l);
        if(!check(n,ed,mid))r=mid;
        else l=mid;
    }
    return l;
}
void solve()
{
    cin>>n>>m>>k;
    if(n-1>m||m>(n-1)*n/2){
        cout<<"NO"<<endl;
        return;
    }
    //待拓展
    //可拓展
    //次拓展
    int n1(n-1),n2(1),n3(0);
    int ans(1);
    while(n1>0&&m>0)
    {
        if(m==n1)
        {
            if(!n3)ans++;
            break;
        }
        if(!n3)ans++;
        int tmp = findbag(n1,m);
        // cout<<"#"<<tmp<<endl;
        m-=(tmp+1)*tmp/2;
        if(n2==1)
        {
            n2=n3+tmp;
            n3=0;
            n1=n1-tmp;
        }
        else
        {
            n2--;
            n3+=tmp;
            n1-=tmp;
        }
    }
    // cout<<ans<<endl;
    if(ans<k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
100
1000000001 1000000000 4
1000000000 1000000000 3
1000000000 1000000000 2
1000000000 1000000000 5
1000000000 1000000000 6
1000000000 1000000000 7
1000000000 1000000000 8
*/