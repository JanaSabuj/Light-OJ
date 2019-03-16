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
int nodes = 0;

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

int kruskal(vector<pair<int, pair<int, int>>> g) {

	sort(g.begin(), g.end());
	initialize();

	int x, y, wt, mc = 0,line=0;

	for (auto e : g) {

		wt = e.first;
		x = e.second.first;
		y = e.second.second;

		if (root(x) != root(y)) {

			mc += wt;
			union1(x, y);
			line++;
		}

	}

	if(line==nodes-1)
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

		int edges;
		cin >> edges;

		map<string, int> hash;
		std::vector<pair<int, pair<int, int>>> g;
		//take the edges input
		nodes = 0;
		for (int i = 0; i < edges; i++) {

			string s1, s2;
			int wt;
			cin >> s1 >> s2 >> wt;

			if (hash.find(s1) == hash.end()) {
				hash[s1] = hash.size();
				nodes++;
			}

			if (hash.find(s2) == hash.end()) {
				hash[s2] = hash.size();
				nodes++;
			}

			g.pb({wt, {hash[s1], hash[s2]}});


		}



		int mincost = kruskal(g);
		if (mincost == -1)
			cout << "Case " << ++tc << ":" << " " << "Impossible" << endl;
		else
			cout << "Case " << ++tc << ":" << " " << mincost << endl;


//end of while

		hash.clear();
	}

	return 0;

}

