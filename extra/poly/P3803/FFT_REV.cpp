// 位逆序置换
// 必备板子
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
// 方便本地调试的板子
// #define LOCAL
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
位逆序置换：
每一个数的下标都是它二进制左右对称后的位置

蝶形运算优化：
直接在数组下标为k和k+n/2的位置进行覆写而不额外开数组保存值
*/

// 圆周率
const double PI = acos(-1);
// 位逆序置换表
vector<int> rev;
void initRev(int lim,int bit)
{
    rev.assign(lim,0);
    inc(i,0,lim-1)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    }
}

/**
 * 快速傅里叶变换（位逆序置换版）
 * @param a 复数数组
 * @param n 变换长度，为数组长度（必须为2的幂）
 * @param dir 变换方向：1=正向DFT，-1=逆向IDFT
 */
void FFT(
    complex<double>* a,
    int n,
    int dir
){
    inc(i, 0, n-1)if(i < rev[i])swap(a[i],a[rev[i]]);

    // 对区间长度从小到大遍历（蝶形运算）
    for(int wid(2); wid <= n; wid <<= 1)
    {
        // 初始化单位根
        complex<double>dw(cos(2 * PI / wid), sin(2 * PI / wid) * dir);
        // 枚举区间左端点
        for(int index(0); index < n; index += wid)
        {
            // 初始化旋转因子
            complex<double>w(1, 0);
            // 把区间的左右半部分分开处理
            inc(k, index, index + wid / 2 - 1)
            {
                complex<double> x = a[k];
                complex<double> y = a[k+wid/2];
                a[k]=x+y*w;
                a[k+wid/2]=x-y*w;
                // 注意旋转旋转因子
                w*=dw;
            }
        }
    }
}
const int MaxN(1e6+5);
// 留足4倍方便把数组长度拓展到2的幂次
complex<double> f[MaxN*4], g[MaxN*4], ans[MaxN*4];
void solve()
{
    int n, m;
    cin >> n >> m;
    inc(i, 0, n)cin >> f[i];
    inc(i, 0, m)cin >> g[i];

    int bit(0), len(1);
    while(len <= n + m)len <<= 1,bit++;

    initRev(len, bit);

    FFT(f, len, 1);
    FFT(g, len, 1);

    inc(i, 0, len-1)ans[i] = f[i] * g[i];

    FFT(ans, len, -1);

    inc(i, 0, n + m)cout << (int)(ans[i].real() / len + 0.5) << " ";cout << endl;
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
    _ = 1;
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