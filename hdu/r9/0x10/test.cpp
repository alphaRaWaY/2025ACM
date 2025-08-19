#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define ll long long
#define MAXN 500005
using namespace std ;
 
vector <int> G[MAXN] ;//初始图 
vector <int> g[MAXN] ;//缩点后的图 
stack <int> S ; 
int m , n , ans ;
int sta ;
int w[MAXN] , d[MAXN] ;//w点权，d表示该点所属分量 
bool inS[MAXN] ;//inS是否在栈中 ,vis在SPFA ,inQ是否在队列 
int DFN[MAXN] , low[MAXN] ;//Tarjan用 
int cnt , W[MAXN] , num , be , fsum , f[MAXN] ;//缩点信息 
 
struct node{
    int from , to ;
}way[MAXN];
 
void Tarjan( int x ) {//求强连通分量，缩点 
    num ++ ;
    DFN[x] = low[x] = num ;
    S.push(x);
    inS[x] = 1 ;
    for(int i = 0 ; i < G[x].size() ; ++ i ) {
        int s = G[x][i] ;
        if( !DFN[s] ) {
            Tarjan( s );
            low[x] = min( low[x] , low[s] );
        }
        else if( inS[s] )
            low[x] = min( low[x] , DFN[s] );
    }
    if( low[x] == DFN[x] ) {
        cnt ++ ;
        int now ;
        do{
            now = S.top() ;
            S.pop();
            d[now] = cnt ;
            inS[now] = 0 ;
            if( now == sta )
                be = cnt ;
            W[cnt] += w[now] ;
        }while( now != x );
    }
}
 
int main() {
    scanf("%d%d", &n , &m );//基本输入 
    for( int i = 1 ; i <= m ; ++ i ) {
        int a , b ;
        scanf("%d%d", &a , &b );
        G[a].push_back(b);
        way[i].from = a , way[i].to = b ;
    }
    for( int i = 1 ; i <= n ; ++ i )
        scanf("%d", &w[i] );
    scanf("%d%d", &sta );
    for( int i = 1 ; i <= n ; ++ i ) {//缩点 
        num = 0 ;
        if( !DFN[i] )
            Tarjan( i );
    }
    for( int i = 1 ; i <= m ; ++ i ) {//连接缩点后的图 
        int a = d[way[i].from] ;
        int b = d[way[i].to] ;
        if( a != b )
            g[a].push_back(b); 
    }
}