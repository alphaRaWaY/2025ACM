#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define MAXN 500005
#define PI 3.141592653589793L 
#define EPS 1e-9
#define INF 0x7f7f7f7f7f7f7f7f
using namespace std;

long long x[MAXN], y[MAXN], dis[MAXN];
long double arc[MAXN];
vector< long double > vl, vh;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vh.clear();
		vl.clear();
		bool fin = false;
		long long n, px, py;
		cin >> n >> px >> py;
		for (int i = 0; i < n; i++)
			scanf("%lld%lld", &x[i], &y[i]);
		long long Mdis = 0, mdis = INF;
		for (int i = 0; i < n; i++) {
			long long dx = (x[i]-px), dy = (y[i]-py);
			dis[i] = dx*dx + dy*dy;
			Mdis = max(dis[i], Mdis);
			mdis = min(dis[i], mdis);
			if (dx == 0 && dy == 0)
				fin = true;
			else
				arc[i] = atan2(dy, dx);
		}
		long double tot = 0;
		for (int i = 0; i < n; i++) {
			long double darc = arc[(i + 1) % n] - arc[i];
			if (fabs(darc - PI) < EPS || fabs(darc + PI) < EPS) fin = true;
			if (darc < -PI) darc += 2 * PI;
			if (darc > PI) darc -= 2 * PI;
			tot += darc;
		}
		fin |= fabs(tot - 2 * PI) < EPS;
		long double ans = 0;
		for (int i = 0; i < n; i++) {
			if (dis[i] == Mdis)
				vh.push_back(arc[i]);
			if (dis[i] == mdis)
				vl.push_back(arc[i]);
		}
		for (int i = 0; i < (int)vh.size(); i++) {
			long double darc = vh[(i + 1) % vh.size()] - vh[i];
			while (darc < EPS) darc += 2 * PI;
            cout<<darc<<" ";
			ans = max(ans, darc);
		}
        cout<<endl;
		if (!fin)	
			ans = 2 * PI;
		printf("%.15Lf\n", ans);
//		printf("%.15Lf\n",tot);
//		cout<<fin<<endl;
//		cout<<vh.size()<<' '<<vl.size()<<endl;
	}
	return 0;
}