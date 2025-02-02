#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(205);
//模板数量，牛棚数，牛数
struct node
{
    int ID;
    int dis;
    bool operator < (node & tmp) const {
        if(dis==tmp.dis) return ID>tmp.ID;
        else return dis>tmp.dis;
    }
}nodes[MaxN];
int m,s,c,nums[MaxN];
signed main()
{
    //ios::sync_with_stdio(false);
    cin>>m>>s>>c;
    if(m>=c)
    {
        cout<<c<<endl;
        return 0;
    }
    m--;
    inc(i,1,c)cin>>nums[i];
    sort(nums+1,nums+c+1);
    inc(i,1,c-1)
    {
        nodes[i].ID=i;
        nodes[i].dis=nums[i+1]-nums[i]-1;
    }
    sort(nodes+1,nodes+c);
    //inc(i,1,c-1)cout<<nodes[i].dis<<" "<<nodes[i].ID<<endl;
    int ans=0;
    ans+=nums[1]-1;
    ans+=s-nums[c];
    inc(i,1,c-1)
    {
        if(!m)break;
        ans+=nodes[i].dis;
        m--;
    }
    cout<<s-ans<<endl;
    system("pause");
}