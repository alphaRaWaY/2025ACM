#include <bits/stdc++.h>  
using namespace std;  
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
struct Option {  
    int price;  
    int base;  
    int bonus;  
};  
Option options[7] = {  
    {1, 10, 8},  
    {6, 60, 18},  
    {28, 280, 28},  
    {88, 880, 58},  
    {198, 1980, 128},  
    {328, 3280, 198},  
    {648, 6480, 388}  
};  
int n;  
int ans(0);  
bool used[7];  
void dfs(int index,int money,int val) {  
    if (money==0) {  
        ans=max(ans,val);  
        return;  
    }  
    if (index==7||money<0) {  
        return;  
    }  
    dfs(index+1,money,val);  
    if (!used[index]&&money>=options[index].price){  
        used[index]=true;  
        dfs(index+1,money-options[index].price,val+options[index].base+options[index].bonus);  
        used[index]=false;  
    }  
}  
signed main() {  
    ios::sync_with_stdio(false);  
    // cin.tie(nullptr);  
    cin>>n;  
    ans=0;  
    memset(used, false, sizeof(used));  
    dfs(0,n,0);  
    cout<<ans<<endl;  
    system("pause");
}  