#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5);
string s1,s2;
int nxt[MAXN][30];
int pre(int i)
{
    return nxt[i][s2[i]-'A'];
}
vector<int> ans;
void solve()
{
    cin>>s1>>s2;
    int a(s1.length()),b(s2.length());
    s1="#"+s1;
    s2="#"+s2;
    inc(i,0,25)nxt[1][i]=0;
    inc(i,2,b)
    {
        inc(j,0,25)nxt[i][j]=nxt[i-1][j];
        nxt[i][s2[i-1]-'A']=i-1;
    }
    int j(0);
    inc(i,0,a-1)
    {
        while(j&&s1[i+1]!=s2[j+1])j=pre(j);
        if(s1[i+1]==s2[j+1])j++;
        if(j==b)
        {
            ans.push_back(i-b+2);
            j=pre(j);       
        }
    }
    for(int tmp:ans)cout<<tmp<<endl;
    inc(i,1,b)cout<<pre(i)<<" ";cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}