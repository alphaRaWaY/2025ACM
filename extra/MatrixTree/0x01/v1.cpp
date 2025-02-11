// 给定一张无向图，求出其生成树的个数 (请使用Matrix定理求解)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m;
const int MAXN(405);
double matrix[MAXN][MAXN];
/**
 * 高斯消元，消除下三角
 * (long double)matrix   需要消元的矩阵
 * (int)n    方阵的大小
 * 最后计算det(matrix)只需要将对角线的所有数字相乘即可
 */
void gauss(int n)
{
    inc(j,1,n-1)
    {
        if(!matrix[j][j])
        {
            int target(0);
            inc(i,j+1,n)
            {
                if(matrix[i][j])
                {
                    target=i;
                    break;
                }
            }
            if(target)
            {
                inc(k,1,n)
                {
                    matrix[j][k]*=-1;   
                    swap(matrix[j][k],matrix[target][k]);
                }
            }
            else continue;
        }
        inc(i,j+1,n)
        {
            double tmp=matrix[i][j]/matrix[j][j];
            inc(k,1,n)
            {
                matrix[i][k]-=matrix[j][k]*tmp;
            }
        }
    }
}
int degree[MAXN];
void solve(){
    cin>>n>>m;
    inc(i,1,n)degree[i]=0;
    inc(i,1,n)inc(j,1,n)matrix[i][j]=0;
    inc(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
        matrix[a][b]=matrix[b][a]=-1;
    }
    inc(i,1,n)matrix[i][i]=degree[i]-matrix[i][i];
    gauss(n-1);
    double ans(1);
    inc(i,1,n-1)ans*=matrix[i][i];
    // 输出long double一定要限制位数，不然会输出科学计数法
    cout<<fixed<<setprecision(0)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
5
4 5
3 4
4 2
2 3
1 2
1 3

2 1
2 1

1 0

3 3
1 2
2 3
3 1

10 45
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
3 4
3 5
3 6
3 7
3 8
3 9
3 10
4 5
4 6
4 7
4 8
4 9
4 10
5 6
5 7
5 8
5 9
5 10
6 7
6 8
6 9
6 10
7 8
7 9
7 10
8 9
8 10
9 10
*/