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
 int visited[26][26][26];
 int dist[26][26][26];
 #define forbidden -1
 #define not_visited 0
 #define done 1

struct point
{	
	int x,y,z;
	point(){};
	point(int x,int y,int z){
		this->x=x;
		this->y=y;
		this->z=z;
	}
	
};

int X[]={0,0,1,0,0,-1};
int Y[]={0,1,0,0,-1,0};
int Z[]={1,0,0,-1,0,0};

 	 
 signed main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	freopen("error.txt", "w", stderr);
    crap;
	
    int t;
    cin>>t;
    int cases=0;
    while(t--){
    	string start,finish;
    	int n;
    	cin>>start>>finish>>n;

    	memset(visited,0,sizeof(visited));
        
    	//forbidden forest
        while(n--){

        	string s1,s2,s3;
        	cin>>s1>>s2>>s3;

        	for(int i=0; i<s1.length(); i++){
        		for(int j=0; j<s2.length(); j++){
        			for(int k=0; k<s3.length(); k++){
        				visited[s1[i]-'a'][s2[j]-'a'][s3[k]-'a']=forbidden;

        			}
        		}
        	}


        }
//////

       //base cases
        if(visited[start[0]-'a'][start[1]-'a'][start[2]-'a']==forbidden)
        	{ cout<<"Case "<<++cases<<":"<<" "<< -1 <<endl; continue;} 
        if(visited[finish[0]-'a'][finish[1]-'a'][finish[2]-'a']==forbidden)
        	{ cout<<"Case "<<++cases<<":"<<" "<< -1 <<endl; continue;}

        // bfs
        bool flag=true;
        queue<point> q;
        q.push(point(start[0]-'a', start[1]-'a', start[2]-'a'));
        visited[start[0]-'a'][start[1]-'a'][start[2]-'a']=done;
        dist[start[0]-'a'][start[1]-'a'][start[2]-'a']= 0;

         int answer;
         while(!q.empty() and flag){

         	point temp= q.front();
         	q.pop();

         	//base case 
         	if(temp.x==finish[0]-'a' and temp.y==finish[1]-'a' and temp.z==finish[2]-'a' )
         	{
         		flag=false;
         		answer= dist[finish[0]-'a'][finish[1]-'a'][finish[2]-'a'];
         		break;

         	}

         	for(int i=0; i<6; i++){

         		int l= (temp.x+ X[i])%26;
         		int m= (temp.y+ Y[i])%26;
         		int n= (temp.z+ Z[i])%26;

         		if(l<0) l+=26;
         		if(m<0) m+=26;
         		if(n<0) n+=26;

         		if(visited[l][m][n]==not_visited){
         			if(visited[l][m][n]!=forbidden){
         				q.push(point(l,m,n));
         				visited[l][m][n]=done;
         				dist[l][m][n]=dist[temp.x][temp.y][temp.z]+1;

         			}

         		}


         	}


         }


         if(flag==false)
         {
         	 cout<<"Case "<<++cases<<":"<<" "<<  answer<<endl; 
         }
         else {
         	cout<<"Case "<<++cases<<":"<<" "<<  -1<<endl; 
         }

    } 
    return 0;
    
 }

