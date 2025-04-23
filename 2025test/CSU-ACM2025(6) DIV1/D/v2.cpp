#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using namespace std;
const int MAXN=2e6+5;
int n,m,fa[MAXN];
vector<pair<int,int> > v1,v2;
int fd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
void solve()
{
    v1.clear();v2.clear();
    cin>>n>>m;
    inc(i,1,n) fa[i]=i;
    bool isOK(true);
    inc(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        if(c&1) v1.push_back({a,b});
        else {
            if(!c&&a!=b) {
                isOK=false;
            }
            if(n==1&&c)
            {
                isOK=false;
            }
            v2.push_back({a,b});
        }
    }
    if(!isOK)
    {
        cout<<"No"<<endl;
        return;
    }
    for(auto [a,b] : v2) fa[fd(a)]=fd(b);
    for(auto [a,b] : v1) {
        if(fd(a)==fd(b)){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    return;
}
signed main(){
	ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
10
5 4
1 3 4
4 2 7
4 4 0
5 2 1
*/