//0x09子题
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=n;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(105);
const double OFFSET(1e-7);
int n;
double matrix[MAXN][MAXN],ans[MAXN][MAXN];
double yy[MAXN],xx[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        inc(j,1,n)cin>>matrix[i][j];
        cin>>yy[i];
    }
    inc(i,1,n)ans[i][i]=1;
    bool isOK(true);
    inc(i,1,n-1)//删除下三角第i列
    {
        if(abs(matrix[i][i])<OFFSET)
        {
            int target=-1;
            inc(j,i+1,n)
            {
                if(abs(matrix[j][i])>OFFSET)
                {
                    target=j;
                    break;
                }
            }
            if(target==-1)
            {
                cout<<"No Solution"<<endl;
                return;
            }
            inc(k,1,n)
            {
                swap(matrix[i][k],matrix[target][k]);
                swap(ans[i][k],ans[target][k]);
            }
        }
        inc(j,i+1,n)//当前删除第j行的第i列
        {
            double tmp=matrix[j][i]/matrix[i][i];
            inc(k,1,n)//对第j行的第k个数进行计算
            {
                matrix[j][k]=matrix[j][k]-tmp*matrix[i][k];
                ans[j][k]=ans[j][k]-tmp*ans[i][k];
            }
        }
    }
    dec(i,n,2)//删除上三角第i列
    {
        if(abs(matrix[i][i])<OFFSET)
        {
            int target=-1;
            dec(j,i-1,1)
            {
                if(abs(matrix[j][i])>OFFSET)
                {
                    target=j;
                    break;
                }
            }
            if(target==-1)
            {
                cout<<"No Solution"<<endl;
                return;
            }
            inc(k,1,n)
            {
                swap(matrix[i][k],matrix[target][k]);
                swap(ans[i][k],ans[target][k]);
            }
        }
        dec(j,i-1,1)//当前删除第j行的第i列
        {
            double tmp=matrix[j][i]/matrix[i][i];
            inc(k,1,n)//对第j行的第k个数进行计算
            {
                matrix[j][k]=matrix[j][k]-tmp*matrix[i][k];
                ans[j][k]=ans[j][k]-tmp*ans[i][k];
            }
        }
    }
    // inc(i,1,n)
    // {
    //     inc(j,1,n)
    //     {
    //         ans[i][j]/=matrix[i][i];
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    inc(i,1,n)
    {
        // cout<<"xx["<<i<<"]=";
        inc(j,1,n)
        {
            ans[i][j]/=matrix[i][i];
            xx[i]+=ans[i][j]*yy[j];
            // cout<<ans[i][j]<<" X "<<yy[j]<<(j==n?" = ":" + ");
        }
        // cout<<xx[i]<<endl;
        printf("%.2Lf\n",xx[i]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
}
/*
3
1 2 8 1
2 5 6 1
5 1 2 1
*/

/*
3
3 2 4 1
7 2 9 1
2 4 3 1
*/

/*
3
1 2 3 1
1 2 5 1
1 3 2 1
*/

/*
3
1 3 4 5
1 4 7 3
9 3 2 2
*/