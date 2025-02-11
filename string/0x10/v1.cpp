#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const string s("Just a legend");
const int MAXN(1e6+5);
char in[MAXN],s1[MAXN],s2[MAXN];
int nxt[MAXN];
int l,a,b;
void solve()
{
    cin>>in+1;
    l=strlen(in+1);
    int j(0);
    inc(i,2,l)
    {
        while(j&&in[j+1]!=in[i])
        {
            j=nxt[j];
        }
        if(in[i]==in[j+1])
        {
            j++;
            nxt[i]=j;
        }
    }
    b=nxt[l];
    a=l-2;
    strcpy(s2+1,in+1);
    strcpy(s1+1,in+2);
    memset(nxt,0,sizeof(nxt));
    inc(i,1,a)cout<<s1[i];cout<<endl;
    inc(i,1,b)cout<<s2[i];cout<<endl;
    j=0;
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
    int ans(0);
    inc(i,1,a)
    {
        while(j&&s1[i]!=s2[j+1])j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        ans=max(ans,j);
        if(j==b)j=nxt[j];       
    }
    if(!ans)cout<<s;
    else inc(i,1,ans)cout<<s2[i];
    cout<<endl;
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
fixprefixsuffix
*/

/*
abcdabc
*/

/*
abcdabcabcdabc
*/