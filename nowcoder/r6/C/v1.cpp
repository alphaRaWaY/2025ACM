#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

#define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream& operator<< (ostream& o,const pair<int,int>& a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

void solve()
{

}
void test()
{
    inc(n,1,10)
    {
        // cout<<"n="<<n<<endl;
        vector<int>p,out;
        map<int,int>cnt;
        int tot(0);
        inc(i,1,n)p.push_back(i);
        do{
            vector<int> ans;
            for(int tmp:p)
            {
                while(!ans.empty()&&tmp>ans.back())ans.pop_back();
                ans.push_back(tmp);
            }
            // out.push_back(ans.size());
            cnt[ans.size()]++;
        }while(next_permutation(p.begin(),p.end()));
        for(auto[x,y]:cnt)
        {
            cout<<y<<" ";
            tot+=x*x*x*y;    
        }
        cout<<"\t tot="<<tot<<endl;
        // sort(out.begin(),out.end());
        // debug1(out,0,out.size()-1);
    }
}
signed main()
{
    test();
    // ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}
/*
1        tot=1
1 1      tot=9
2 3 1    tot=53
6 11 6 1         tot=320
24 50 35 10 1    tot=2134
120 274 225 85 15 1      tot=15918
720 1764 1624 735 175 21 1       tot=132474
5040 13068 13132 6769 1960 322 28 1      tot=1222032
40320 109584 118124 67284 22449 4536 546 36 1    tot=12404856
362880 1026576 1172700 723680 269325 63273 9450 870 45 1         tot=137607096
*/
