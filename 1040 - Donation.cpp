//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India
//God is Great
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define int long long int
const int INF = 1e9 + 5; //billion
#define pb push_back
#define mp make_pair

#define MAX 53
int id[MAX];
int n;


void initialize() {
 
    for (int i = 0; i < MAX; ++i)
    {
        /* code */
        id[i] = i;
    }
}
 
int root(int x) {
 
    while (id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
 
    return x;
}
 
void union1(int x, int y) {
 
    id[root(x)] = id[root(y)];
}

int kruskal(vector< pair<int, pair<int, int>>> g ) {
	sort(g.begin(), g.end());
	initialize( );

	int x, y, wt, mc = 0, line = 0;

	for (auto edg : g) {

		wt = edg.first;
		x = edg.second.first;
		y = edg.second.second;

		if (root(x ) != root(y )) {
			mc += wt;
			union1(x, y );
			line++;
		}


	}

	if (line == n - 1)
		return mc;
	else
		return -1;
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	crap;

	int t;
	cin >> t;
	int tc = 0;
	while (t--) {

		n = 0;
		cin >> n;

		int cost = 0, totalcost = 0;
		std::vector<pair<int, pair<int, int>>> g;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			for (int j = 0; j < n; j++) {

				int x;
				cin >> x;

				if (i == j) cost += x;
				else {
					if (x != 0) {
						g.pb({x, {i, j}});
						totalcost += x;
					}
				}
			}
		}

		int val = kruskal(g);

		if (val != -1)
		{	cost += totalcost - val;

			cout << "Case " << ++tc << ":" << " " << cost << endl;
		}

		else {

			cout << "Case " << ++tc << ":" << " " << -1 << endl;
		}
		}



		//end of while
	 


	return 0;

}

