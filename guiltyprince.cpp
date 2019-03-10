 //Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
// God is Great------------/////\\\\--------------------------------
 #include <bits/stdc++.h>
 using namespace std;
 #define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 #define endl "\n"
 // #define int long long int 
 const int INF=1e9+5;//billion
 #define pb push_back
 #define mp make_pair
   
 typedef vector<int> vi;

 #define SZ 23
 char grid[SZ][SZ];
 bool visited[SZ][SZ];
 int ans;
 int r,c;

 	int X[]={0,1,0,-1};
 	int Y[]={-1,0,1,0};

 	bool boundary(int x,int y){
 		return ((x>=0) and (x<r) and (y>=0) and (y<c));
 	}

 void dfs(int x, int y){


 	for(int i=0; i<4; i++){
 		if( boundary(x+X[i],y+Y[i]) and !visited[x+X[i]][y+Y[i]] and grid[x+X[i]][y+Y[i]]=='.' ){
 			ans++;
 			visited[x+X[i]][y+Y[i]]=true;
 			dfs(x+X[i],y+Y[i]);
 		}
 	}



 }
 	 
 signed main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	freopen("error.txt", "w", stderr);
    crap;
    
    int t;
    cin>>t;
    int cases=0;
    while(t--){

    	memset(visited,false,sizeof(visited));
    	
   	cin>>c>>r;
   	int x,y;

   	for (int i = 0; i < r; ++i)
   	{
   		/* code */
   		for(int j=0; j<c; j++){

   			cin>>grid[i][j];
   			if(grid[i][j]=='@'){
   				x=i;
   				y=j;
   			}
   		}
   	}

   	visited[x][y]=true;
   	ans=1;

   	dfs(x,y);

   	cout<<"Case "<<++cases<<":"<<" "<< ans <<endl;
   	  
    }
   	
    return 0;
    
 }

