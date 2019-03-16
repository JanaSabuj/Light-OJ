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
typedef vector<int> vi;
#define MAX 105

int id[MAX];

void initialize() {

	for (int i = 0; i < MAX; i++) {
		id[i] = i;

	}
}

int root(int x ) {

	while (id[x] != x) {
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;

}

void union1(int x, int y ) {

	int p = root(x );
	int q = root(y );
	// id[p] = id[q];
	id[p] = id[q];

}

int kruskalmin(vector< pair<int, pair<int, int> > > g ) {
	sort(g.begin(), g.end());
	initialize( );

	int x, y, wt, mc = 0;

	for (auto edg : g) {

		wt = edg.first; 
		x = edg.second.first;
		y = edg.second.second;

		if (root(x ) != root(y )) {
			mc += wt;
			union1(x, y );

		}


	}

	return mc;

}

int kruskalmax(vector< pair<int, pair<int, int>>> g ) {
	sort(g.rbegin(), g.rend());
	initialize( );

	int x, y, wt, mc = 0;

	for (auto edg : g) {

		wt = edg.first; 
		x = edg.second.first;
		y = edg.second.second;

		if (root(x ) != root(y )) {
			mc += wt;
			union1(x, y );

		}


	}

	return mc;

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

		vector< pair<int, pair<int, int>>> g;

		int nodes, edges = 0;
		cin >> nodes;

		vector<int> id(nodes + 1);

		g.clear();

		while (1) {
			int x, y, wt;
			cin >> x >> y >> wt;
			if (x == 0 and y == 0 and wt == 0) break;
			g.pb({wt, {x, y}});
		}




		int mincost;
		mincost = kruskalmin(g);
		cerr << endl;

		int maxcost;

		maxcost = kruskalmax(g);



		cout << "Case " << ++tc << ":" << " ";
		if ( (mincost + maxcost) % 2 == 0) {
			cout << (mincost + maxcost) / 2 << endl;
		}
		else {
			cout << (mincost + maxcost) << "/" << 2 << endl;
		}


	}


	return 0;

}

