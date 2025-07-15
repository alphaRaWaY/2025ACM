// 仅消除下三角的高斯消元，可以用于计算行列式
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=n;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(505);
double matrix[MAXN][MAXN];
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
void solve()
{
    int n;
    cin>>n;
    inc(i,1,n)
    inc(j,1,n)
    {
        cin>>matrix[i][j];
    }
    gauss(n);
    inc(i,1,n)
    {
        inc(j,1,n)
        {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
    }
    double ans(1);
    inc(i,1,n)ans*=matrix[i][i];
    printf("det(M) = %f\n",ans);
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
3
3
1 2 8
2 5 6
5 1 2
3
3 2 4
7 2 9
2 4 3
4
1 2 3 6
1 2 5 7
1 3 2 4
3 2 5 6
*/