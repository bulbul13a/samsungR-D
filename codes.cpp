//Mr. Lee
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[20][20];
int n,res;

void optimalPath(bool* visited, int curr, int node, int val){
    if (node == n-1){
        if(arr[curr][0]!=0){
            res=min(res, val+arr[curr][0]);
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]&&arr[curr][i]!=0){
            visited[i]=true;
            optimalPath(visited, i, node+1,val+arr[curr][i]);
            visited[i]=false;
        }
    }
}

int main()
{
    int t;
    cin>>t;

    for(int i=0; i<t;i++){
        cin>>n;
        res = INT_MAX;
        bool visited[n]={false};

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        visited[0]=true;
        optimalPath(visited,0,0,0);
        res != INT_MAX ? cout<<endl<<"Test #"<<i+1<<" : "<<res<<endl : cout<<"-1"<<endl;
    }
    return 0;
}
—---------------------------------###############################----------------------------------------
//Mr. Kim
#include<iostream>
#include<climits>
using namespace std;
int x[20],y[20],n,ans;

int dist(int i, int j){//Calc dist between 2 points
    int x1 = x[i], x2 = x[j];
    int y1 = y[i], y2 = y[j];
    
    return (abs(x1-x2) + abs(y1-y2));
}

void optimalPath(int x,bool visited[],int nodes,int value){
	if(n == nodes){//If number of nodes equal n then set value of answer
		ans = min(ans,value + dist(x,n+1));
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			optimalPath(i,visited,nodes+1,value + dist(x,i));//Dfs call
			visited[i] = false;
		}
	}
}
int main(){
	int tCases;
	cin >> tCases;//For testcases
	for(int i=0;i<tCases;i++){
		ans=INT_MAX;//Set ans to max value
		cin >> n;
		cin >> x[n+1] >> y[n+1] >> x[0] >> y[0];//Input destination and source x,y coordinates
		for(int i=1;i<=n;i++){//Input drop off location coordinates
			cin >> x[i] >> y[i];
		}
		bool visited[n+2]={false};
		optimalPath(0,visited,0,0);
		cout << "#" << i+1 << " " << ans << endl;
	}
	return 0;
}

—---------------------------------###############################----------------------------------------
//wormhole
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,res,temp=0;
int w[35][5];
int visited[35];

int dist(int sx, int sy,int ex, int ey){
    return abs(sx-ey)+abs(sy-ey);
}

void optimalPath(int sx,int sy,int ex,int ey,int val){
    res=min(res,val+dist(sx,sy,ex,ey));
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            visited[i]=1;
            temp=dist(sx,sy,w[i][0],w[i][1])+w[i][4]+val;
            optimalPath(w[i][2],w[i][3],ex,ey,temp);
            temp=dist(sx,sy,w[i][2],w[i][3])+w[i][4]+val;
            optimalPath(w[i][0],w[i][1],ex,ey,temp);
            visited[i]=0;           
        }
    }
}
int main()
{
    cin>>n;
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    for(int i=0; i<n; i++){
        visited[i]=0;
        for(int j=0; j<5; j++){
            cin>>w[i][j];
        }
    }
    
    res=INT_MAX;
    optimalPath(sx,sy,ex,ey,0);
    
    cout<<res;
    return 0;
}
—---------------------------------###############################----------------------------------------
//cycle in directed graph
#include<iostream>
using namespace std;

int graph[100][100];
int n;

bool dfs(bool *visited, bool *inloop,int node,int prev){
	if(!visited[node]){
	    visited[node] = 1;
	    inloop[node] = 1;
        
        for(int i=0; i<n; i++){
            if(graph[node][i]){
                if(!visited[i]&&dfs(visited,inloop,i,node)){
                    return true;
                }else if(inloop[i] && i!=prev&&node!=i){
                    return true;
                }
            }
        }
	}
	inloop[node]=0;  
	return false;			 
}

bool checkCycle (bool *visited){
	bool inloop[n] = {false};
	
	for(int i=0; i<n; i++)
	    if( !visited[i] && dfs(visited, inloop,i,-1)){
	        return true;
	    }

	return false; 
}

int main(){
	// Input nodes
	cin>>n;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        graph[i][j]=0;
	 
	// Input Edges 
	int t; 
	cin>>t;   
	int x,y;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		graph[x][y]=1;
	}

	bool visited[n] = {false};

	cout<<checkCycle(visited)<<endl;     
	
	return 0;
}




























—---------------------------------###############################----------------------------------------

//cycle in undirected graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int n;

bool dfs(int node,int parent,bool* visited){
    visited[node]=true;

    for(int i=0; i<n; i++){
        if(arr[node][i]){
            if(!visited[i]){
                if (dfs(i,node, visited)){
                    return true;
                }
            }else if(i!=parent && i!=curr){
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(bool* visited){
    for (int i=0; i<n; i++){
        if(!visited[i]){
            if(dfs(i,-1,visited)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    int t;
    cin>>t;
    int x,y;
    for(int i=0; i<t; i++){
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    bool visited[n]={false};

    cout<<hasCycle(visited)<<endl;
    return 0;
}






























—---------------------------------###############################----------------------------------------
//Bipartite graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[100][100],n;

bool isBipartite(int x,int* color){
    color[x]=0;
    queue<int>q;
    q.push(x);
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(arr[x][x]==1){
            return false;
        }
        for(int i=0; i<n; i++){
            if(arr[x][i]==1 && color[i]==-1){
                color[i]=1-color[x];
                q.push(i);
            }else if(arr[x][i]==1 && color[i]==color[x]){
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(int* color){
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(isBipartite(i,color)==false){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin>>n;
    int color[n];
    for(int i=0; i<n; i++){
        color[i]=-1;
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    checkBipartite(color)?cout<<"Yes":cout<<"No";
    return 0;
}


































—---------------------------------###############################----------------------------------------
//2316. Count Unreachable Pairs of Nodes in an Undirected Graph
class Solution {
public:
    void DFS(int curr,int& ans, vector<vector<int>>&adj, vector<bool>&visited){
        visited[curr]=true;
        ans++;
        for(auto i: adj[curr]){
            if(!visited[i]){
                DFS(i,ans,adj,visited);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>res;
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int ans=0;
                DFS(i,ans,adj,visited);
                res.push_back(ans);
                count++;
            }
        }
        long long d=0;
        for (auto i: res){
            d+=(long long)(i)*(long long)(n-i);
        }
        return d/2;
        
    }
};



—---------------------------------###############################----------------------------------------
//burst balloon
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+2];
    arr[0]=1;
    arr[n+1]=1;
    for(int i=1; i<=n;i++){
        cin>>arr[i];
    }
    
    int dp[n+2][n+2];
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++){
            dp[i][j]=0;
        }
    }
    
    for(int win=1; win<=n; win++){
        for(int left=1; left<=n-win+1; left++){
            int right = left+win-1;
            for(int i=left; i<=right; i++){
                dp[left][right]=max(dp[left][right],arr[left-1]*arr[i]*arr[right+1]+dp[left][i-1]+dp[i+1][right]);
            }
        }
    }
    cout<<dp[1][n];

    return 0;
}

//failed version
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    n=t+2;
    int nums[n];
    nums[0]=1;
    nums[n-1]=1;
    for(int i=1; i<=t; i++){
        cin>>nums[i];
    }
    int dp[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }
    for(int win=2; win<n; win++){
        for(int left=0; left<n-win; left++){
            int right = left+win;
            for(int i=left+1; i<right; i++){
                if(left==0 && right==n-1){
                    dp[left][right]=max(nums[left]*nums[i]*nums[right]+dp[left][i]+dp[i][right], dp[left][right]);
                }else{
                    dp[left][right]=max(nums[left]*nums[right]+dp[left][i]+dp[i][right],dp[left][right]);
                }
            }
        }
    }

    cout<<dp[0][n-1];
    return 0;
}







—---------------------------------###############################----------------------------------------
//802. Find Eventual Safe States
class Solution {
public:
    bool cycle(vector<vector<int>>& adj, vector<int> &vis, vector<int> &rec,int x){
        vis[x]=1;
        rec[x]=1;
        for(auto i: adj[x]){
            if(vis[i]==0 && cycle(adj,vis,rec,i)){
                return true;
            }else if(rec[i]){
                return true;
            }
        }
        return rec[x]=0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>rec(n,0);
        vector<int>res;
        for(int i=0; i<n; i++){
            if(cycle(graph,vis,rec,i)==0){
                res.push_back(i);
            }
        }
        return res;
    }
    
};














—---------------------------------###############################----------------------------------------
//Fishermen 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,arr[20],res;
int gp1,gp2,gp3,nf1,nf2,nf3;

void solve(){
    for(int i=1; i<=n-nf2-nf3; i++){
        for(int j=i+nf1; j<=n-nf3; j++){
            for(int k=j+nf2; k<=n; k++){
                int c=0;
                for(int p=i; p<i+nf1; p++){
                    c=c+abs(gp1-p);
                }
                for(int p=j; p<j+nf2; p++){
                    c=c+abs(gp2-p);
                }
                for(int p=k; p<k+nf3; p++){
                    c=c+abs(gp3-p);
                }
                c=c+nf1+nf2+nf3;
                res = min(res,c);
            }
        }
    }
}

int main()
{
    cin>>n;
    cin>>gp1>>gp2>>gp3;
    cin>>nf1>>nf2>>nf3;
    
    res=INT_MAX;
    solve();
    cout<<res;

    return 0;
}



