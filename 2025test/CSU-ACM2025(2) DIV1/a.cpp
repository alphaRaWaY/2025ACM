#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
int a, b, c;
void exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return;
    }
    int tx, ty;
    exgcd(b, a % b, tx, ty);
    x = ty;
    y = tx - (a / b) * ty;
    return;
}
void solve()
{
    cin >> a >> b >> c;
    int x, y;
    exgcd(a, b, x, y);
    // cout<<a*x+b*y<<endl;
    int g=__gcd(a,b);
    int l=a*b/g;
    if(c%g)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        int xx=l/a,yy=l/b;
        // cout<<"#"<<xx<<" "<<yy<<endl;
        int mx = ((c/g%xx)*(x%xx)%xx+xx)%xx;
        int my = ((c/g%yy)*(y%yy)%yy+yy)%yy;
        if(!mx)mx+=xx;
        if(!my)my+=yy;
        int Mx = (c-b*my)/a;
        int My = (c-a*mx)/b;
        int num = (Mx-mx)/xx;
        if(num<0)
        {
            cout<<mx<<" "<<my<<endl;
        }
        else
        {
            cout<<num+1<<" "<<mx<<" "<<my<<" "<<Mx<<" "<<My<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
}

/*

100
2 11 100
3 18 6
192 608 17
19 2 60817
11 45 14
19 19 810
98 76 5432
*/