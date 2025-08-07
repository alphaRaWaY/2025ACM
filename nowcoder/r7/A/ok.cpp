// Memory Limit: 2048 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define ri int
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int n, ans = 0;
int a[110][110], b[110][110];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
inline int random(int n) { return (ll)rand() * rand() % n; }
void rot(int x1, int y1)
{
    x1--, y1--;
    b[x1 + 1][y1 + 4] = a[x1 + 1][y1 + 1];
    b[x1 + 2][y1 + 4] = a[x1 + 1][y1 + 2];
    b[x1 + 3][y1 + 4] = a[x1 + 1][y1 + 3];
    b[x1 + 4][y1 + 4] = a[x1 + 1][y1 + 4];
    
    b[x1 + 1][y1 + 3] = a[x1 + 2][y1 + 1];
    b[x1 + 2][y1 + 3] = a[x1 + 2][y1 + 2];
    b[x1 + 3][y1 + 3] = a[x1 + 2][y1 + 3];
    b[x1 + 4][y1 + 3] = a[x1 + 2][y1 + 4];

    b[x1 + 1][y1 + 2] = a[x1 + 3][y1 + 1];
    b[x1 + 2][y1 + 2] = a[x1 + 3][y1 + 2];
    b[x1 + 3][y1 + 2] = a[x1 + 3][y1 + 3];
    b[x1 + 4][y1 + 2] = a[x1 + 3][y1 + 4];
    
    b[x1 + 1][y1 + 1] = a[x1 + 4][y1 + 1];
    b[x1 + 2][y1 + 1] = a[x1 + 4][y1 + 2];
    b[x1 + 3][y1 + 1] = a[x1 + 4][y1 + 3];
    b[x1 + 4][y1 + 1] = a[x1 + 4][y1 + 4];
    
    for(ri i = 1; i <= 4; i++)
        for(ri j = 1; j <= 4; j++)
            a[x1 + i][y1 + j] = b[x1 + i][y1 + j];
}
void rotate()
{
    int cnt = 0;
    while(cnt < 1000)
    {
        int x = random(10) + 1, y = random(10) + 1;
        if(x + 3 <= n && y + 3 <= n)
        {
            rot(x, y);
            cnt++;
        }        
    }
}
int main()
{
    srand((unsigned)time(0));
    // scanf("%d", &n);
    n=10;
    cout<<1<< " "<<100<< " "<<10<< " "<<10<<endl;
    for(ri i = 1; i <= n; i++)
        for(ri j = 1; j <= n; j++)
            a[i][j] = (i - 1) * n + j;
            
    rotate();
    
    for(ri i = 1; i <= n; i++)
    {
        for(ri j = 1; j <= n; j++) printf("%3d ", a[i][j]);
        printf("\n");
    }
    for(ri i = 1; i <= n; i++)
        for(ri j = 1; j <= n; j++)
            for(ri k = 0; k <= 3; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if(abs(a[nx][ny] - a[i][j]) == 1 && (i - 1) * n + j <= 100) ans++;
            }
    //printf("%d", ans);
    return 0;
}