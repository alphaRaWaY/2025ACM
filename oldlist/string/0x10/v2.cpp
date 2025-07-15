#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5);
char s[MAXN];
/**
 * s1：待匹配的串
 * s2：子串
 */
char s1[MAXN],s2[MAXN];
int nxt[MAXN];
vector<int> kmp(int a,int b)
{
    vector<int> res;
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
            res.push_back(i-b+1);
            j=nxt[j];       
        }
    }
}
void solve()
{
    cin>>s+1;
    int len=strlen(s+1);
    strcpy(s1+1,s+2);
    int a=len-2;
    int l(0),r(len);
    int right(0),left(0);
    while(r-l>1)
    {
        int mid(((r-l)>>1)+l);
        strcpy(s2+1,s+1);
        int b=mid;
        vector<int> ans=kmp(a,b);
        if(!ans.empty())r=mid;
        else l=mid;
    }
    while(r-l>1)
    {
        int mid(((r-l)>>1)+l);
        strcpy(s2+1,s+len-mid);
        int b=mid;
        vector<int> ans=kmp(a,b);
        if(!ans.empty())r=mid;
        else l=mid;    
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    while(_--)solve();
    system("pause");
}