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

#define MAX 10007
int id[MAX];
int nodes, edges, air, noofair = 0;

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

			union1(x, y );
			line++;

			if (air <= wt) {
				noofair++;

			}
			else
				mc += wt;
		}


	}

	// if (line == n - 1)
	// 	return mc;
	// else
	// 	return -1;

	noofair += nodes - line;
	mc += noofair * air;

	return mc;
}



signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	crap;

	int t, tc = 0;
	cin >> t;

	while (t--) {

		cin >> nodes >> edges >> air;
		noofair = 0;

		std::vector<pair<int, pair<int, int>>> g;

		for (int i = 0; i < edges; ++i)
		{
			/* code */
			int x, y, wt;
			cin >> x >> y >> wt;
			g.pb({wt, {x, y}});
		}


		int cost = 0;
		cost += kruskal(g);



		cout << "Case " << ++tc << ":" << " " << cost << " " << noofair << endl;


		//end of while
	}


	return 0;

}

