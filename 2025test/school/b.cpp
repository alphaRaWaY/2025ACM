#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int nums[MAXN];
string ss[3]={"AND","OR","XOR"};
int n,m;
bool op[2][40];
void solve()
{
    inc(i,0,35)op[1][i]=1;
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    inc(_,1,m)
    {
        string s;
        int val;
        cin>>s>>val;
        inc(i,0,32)
        {
            if(s==ss[0])
            {
                op[0][i]=(op[0][i]&(val>>i))&1;
                op[1][i]=(op[1][i]&(val>>i))&1;
            }
            if(s==ss[1])
            {
                op[0][i]=(op[0][i]|(val>>i))&1;
                op[1][i]=(op[1][i]|(val>>i))&1;
            }
            if(s==ss[2])
            {
                op[0][i]=(op[0][i]^(val>>i))&1;
                op[1][i]=(op[1][i]^(val>>i))&1;
            }
        }
    }
    inc(i,1,n)
    {
        int val(0);
        dec(j,32,0)
        {
            val<<=1;
            val|=op[(nums[i]>>j)&1][j];
        }
        cout<<val<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    // system("pause");
}
/*

*/