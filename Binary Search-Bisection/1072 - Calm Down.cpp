//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India 
//God is Great 
 #include <bits/stdc++.h>
 using namespace std;
 #define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 //cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
 #define endl "\n"
 #define int long long int 
 #define double long double
 const int INF=1e9+5;//billion
 #define pb push_back
 #define mp make_pair
 #define PI acos(-1)
   	 
 signed main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	freopen("error.txt", "w", stderr);
    crap;
    
    int t,tc=0;
    cin>>t;

    while(t--){

    	double R,n;
    	cin>>R>>n;

    	double sini= sin(PI/n);

    	double ans= (R*sini)/(1+sini);

    	cout<<"Case "<<++tc<<":"<<" ";
    	cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;



    	//end
    }
                  
     
    return 0;
    
 }


