#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5);
char s1[MAXN],s2[MAXN];
int nxt[MAXN];
int a,b;
void solve()
{
    cin>>s1+1>>s2+1;
    a=strlen(s1+1);
    b=strlen(s2+1);
    int j(0);
    inc(i,2,b)
    {
        while(j&&s2[j+1]!=s2[i])
        {
            j=nxt[j];
        }
        if(s2[i]==s2[j+1])
        {
            j++;
            nxt[i]=j;
        }
    }
    j=0;
    inc(i,1,a)
    {
        while(j&&s1[i]!=s2[j+1])j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        if(j==b)
        {
            cout<<i-b+1<<endl;
            j=nxt[j];       
        }
    }
    inc(i,1,b)cout<<nxt[i]<<" ";cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    while(_--)solve();
    system("pause");
}
/*
aabcabacacaabcadb
abca
*/