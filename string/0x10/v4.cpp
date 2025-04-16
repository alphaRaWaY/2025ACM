#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e7+5);
char s[MAXN],out[MAXN];
int nxt[MAXN][2];
void solve(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    nxt[1][0]=1;
    int j(0);
    inc(i,2,n)
    {
        while(s[j+1]!=s[i]&&j>1)j=nxt[j][0];
        if(s[j+1]==s[i])
        {
            j++;
            nxt[i][0]=j;
        }
    }
    nxt[n][1]=n;
    j=n+1;
    dec(i,n-1,1)
    {
        while(j<n&&s[j-1]!=s[i])j=nxt[j][1];
        if(s[i]==s[j-1])
        {
            j--;
            nxt[i][1]=j;
        }
        else nxt[i][1]=n+1;
    }
    inc(i,1,n)nxt[i][1]=n+1-nxt[i][1];
    
    // inc(i,1,n)cout<<nxt[i][0]<<" ";cout<<endl;
    // inc(i,1,n)cout<<nxt[i][1]<<" ";cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");
}