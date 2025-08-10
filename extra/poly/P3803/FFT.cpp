// 必备板子
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
// 方便本地调试的板子
#define LOCAL
#ifdef LOCAL
ostream &operator<< (ostream & o,const pair<int,int> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#define split cout<<"-------------------------------"<<endl
#define debug0(c) cout<<"[DEBUG] "<<#c<<"="<<c<<endl
#define debug1(c,l,r)\
cout<<"[DEBUG] "<<#c<<": ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl 
#define debug2(c,l,r,ll,rr)\
cout<<"[DEBUG] "<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
#define T test()
#define case_ans cout<<"[ANSWER] "
#else
#define T
#define case_ans
#define split
#define debug0(c)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

/*
原理：
1、多项式的系数表示形式和点值表示形式可以通过傅里叶变换来相互转化
2、两个多项式的相乘可以使用点值表示法O(n)乘出来

FFT相互转化
单位根矩阵：D
系数矩阵：V
点值矩阵：A

FFT(V)=D x V = A
经过矩阵变换操作可以发现：
D/n = V^-1

因此如果把FFT反向跑一遍就相当于把点值转化为n倍的系数矩阵
这就是单位复根周期性
*/

const double PI = acos(-1);

/**
 * 快速傅里叶变换（递归版）
 * @param a 复数数组
 * @param n 变换长度，为数组长度的一半（必须为2的幂）
 * @param dir 变换方向：1=正向DFT，-1=逆向IDFT
 */
void FFT(
    complex<double>* a,
    int n,
    int dir
){
    if(!n)return;
    complex<double> a1[n],a0[n];
    inc(i,0,n-1)
    {
        a1[i]=a[i<<1|1];
        a0[i]=a[i<<1];
    }

    FFT(a1,n>>1,dir);
    FFT(a0,n>>1,dir);
    
    complex<double> w(1,0),dw(cos(PI/n),sin(PI/n)*dir);

    inc(i,0,n-1)
    {
        a[i]=a0[i]+a1[i]*w;
        a[i+n]=a0[i]-a1[i]*w;
        w*=dw;
    }
}
const int MaxN(1e6+5);
complex<double> f[MaxN],g[MaxN],ans[MaxN*2];
void solve()
{
    int n,m;
    cin>>n>>m;
    inc(i,0,n)cin>>f[i];
    inc(i,0,m)cin>>g[i];

    int len(1);while(len<=n+m)len<<=1;

    FFT(f,len>>1,1);
    FFT(g,len>>1,1);

    inc(i,0,len-1)ans[i]=f[i]*g[i];

    FFT(ans,len>>1,-1);

    inc(i,0,n+m)cout<<(int)(ans[i].real()/len+0.5)<<" ";cout<<endl;
}
// 用于在程序启动前预先测试
void test()
{

}
signed main()
{
    T;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)
    {
        // 样例分隔符，仅在#define LOCAL时生效
        split;
        solve();
    }
}
/*
1 2
1 2
1 2 1
*/