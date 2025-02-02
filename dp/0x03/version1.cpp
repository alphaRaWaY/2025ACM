#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
const int MaxN(3e3+5);
int dp[MaxN][MaxN];//记录各个状态下的最长数量。i为s1出的长度，j为s2出的长度。
int type[MaxN][MaxN];//记录各个状态下的最优决策类型：2:两个字符串都少一个 1:第二个字符串少一个 0:第一个字符串少一个
void solve()
{
    memset(dp,0,sizeof(dp));
    for(int i(0);i<=s2.length();i++)dp[0][i]=0;
    for(int i(0);i<=s1.length();i++)dp[i][0]=0;
    for(int i(0);i<=s1.length();i++)
    for(int j(0);j<=s2.length();j++)
    {type[i][j]=-1;}
    for(int i(1);i<=s1.length();i++)
    for(int j(1);j<=s2.length();j++)
    {
        if(s1[i-1]==s2[j-1])
        {
            dp[i][j]=dp[i-1][j-1]+1;
            type[i][j]=2;
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            dp[i][j]=dp[i][j-1];
            type[i][j]=1;
        }
        else
        {
            dp[i][j]=dp[i-1][j];
            type[i][j]=0;
        }
    }
    /*
    for(int i(1);i<=s1.length();i++)
    {
        for(int j(1);j<=s2.length();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;   
    }
    cout<<"====================================="<<endl;
    for(int i(1);i<=s1.length();i++)
    {
        for(int j(1);j<=s2.length();j++)
        {
            cout<<type[i][j]<<" ";
        }
        cout<<endl;   
    }
    */
    string ans="";
    int x(s1.length()),y(s2.length());
    while(x>0&&y>0)
    {
        switch (type[x][y])
        {
        case 2:
            //cout<<x<<" "<<y<<endl;
            ans=s1[x-1]+ans;
            x--,y--;
            break;
        case 1:
            y--;
            break;
        case 0:
            x--;
            break;
        default:
            break;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>s1>>s2){solve();}
}