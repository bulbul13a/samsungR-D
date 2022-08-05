//Bipartite graph
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100],n;

bool bfs(int src, int* color){
    color[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(arr[x][i]){
                if(color[i]==-1){
                    color[i]=1-color[x];
                    q.push(i);
                }
                else if(color[i]==color[x]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool isBipartite(int* color){
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(bfs(i,color)==false){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int m;
    cin>>n>>m;
    int color[n];
    for(int i=0; i<n; i++){
        color[i]=-1;
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        arr[x][y]=1;
    }
    isBipartite(color)? cout<<"Of course": cout<<"Not";
    return 0;
}
—---------------------------------###############################----------------------------------------
//Detect and print cycle in graph
//Undirected one
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100],n;

bool findCycle(bool* visited, int src, int parent, int& prev){
    visited[src]=true;
    for(int i=0; i<n; i++){
        if(arr[src][i] && !visited[i]){
            if(findCycle(visited,i,src,prev)){
                if(src==prev){
                    cout<<src<<" ";
                    prev=-1;
                }else if(prev!=-1){
                    cout<<src<<" ";
                }
                return true;
            }
        }else if(arr[src][i] && parent!=i && visited[i]){
                cout<<src<<" ";
                prev=i;
                return true;
        }
    }
    return false;
}

bool checkCycle(bool* visited){
    int prev=-1;
    for(int i=0; i<n; i++){
        if(!visited[i] && findCycle(visited,i,-1,prev)){
            return true;
        }
    }
    return false;
}

int main()
{
    int m;
    cin>>n>>m;
    bool visited[n]={false};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    checkCycle(visited)? cout<<"" :cout<<"No cycle";
    return 0;
}

//Directed one
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100],n;

bool findCycle(bool* visited, bool* inloop, int src, int& prev){
    visited[src]=true;
    inloop[src]=true;
    for(int i=0; i<n; i++){
        if(arr[src][i]){
            if(!visited[i]){
                if(findCycle(visited,inloop,i,prev)){
                    if(i==prev){
                        cout<<i<<" ";
                        prev=-1;
                    }else if(prev!=-1){
                        cout<<i<<" ";
                    }
                    return true;
                }
            }else if(inloop[i]){
                prev=i;
                return true;
            }
        }
    }
    inloop[src]=false;
    return false;
}

bool checkCycle(bool* visited){
    int prev=-1;
    bool inloop[n]={false};

    for(int i=0; i<n; i++){
        if(!visited[i] && findCycle(visited,inloop,i,prev)){
            return true;
        }
    }
    return false;
}

int main()
{
    int m;
    cin>>n>>m;
    bool visited[n]={false};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        arr[x][y]=1; 
    }
    checkCycle(visited)? cout<<"" :cout<<"No cycle";
    return 0;
}
—---------------------------------###############################----------------------------------------
//Balloons Burst 1
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+2];
    arr[0]=1;
    arr[n+1]=1;
    for(int i=1; i<=n; i++){
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
            int right=left+win-1;
            for(int i=left; i<=right; i++){
                dp[left][right]=max(dp[left][right],arr[left-1]*arr[i]*arr[right+1]+dp[left][i-1]+dp[i+1][right]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}

//Balloons Burst 2
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
//Endoscopy
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int row,col,x,y,l;
int arr[1000][1000],visited[1000][1000];

bool valid(int x,int y){
    return (x>=0 && x<row && y>=0 && y<col);
}
bool left(int x,int y){
    return (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==6 || arr[x][y]==7);
}
bool right(int x,int y){
    return (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==4 || arr[x][y]==5);
}
bool up(int x,int y){
    return (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==4 || arr[x][y]==7);
}
bool down(int x,int y){
    return (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==6 || arr[x][y]==5);
}
int solve(int x,int y,int l){
    int ans=0;
    queue<pair<int,int>>q;
    queue<int>p;
    q.push({x,y});
    p.push(l);
    visited[x][y]=1;
    while(!q.empty()){
        pair<int,int>pp=q.front();
        int x=pp.first;
        int y=pp.second;
        int l=p.front();
        q.pop();
        p.pop();
        if(l==0)continue;
        ans++;
        if(valid(x,y-1) && left(x,y) && right(x,y-1) && visited[x][y-1]==0){
            q.push({x,y-1});
            p.push(l-1);
            visited[x][y-1]=1;
        }
        if(valid(x,y+1) && right(x,y) && left(x,y+1) && visited[x][y+1]==0){
            q.push({x,y+1});
            p.push(l-1);
            visited[x][y+1]=1;
        }
        if(valid(x-1,y) && up(x,y) && down(x-1,y) && visited[x-1][y]==0){
            q.push({x-1,y});
            p.push(l-1);
            visited[x-1][y]=1;
        }
        if(valid(x+1,y) && down(x,y) && up(x+1,y) && visited[x+1][y]==0){
            q.push({x+1,y});
            p.push(l-1);
            visited[x+1][y]=1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col>>x>>y>>l;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>arr[i][j];
                visited[i][j]=0;
            }
        }
        if (arr[x][y]>0){
            cout<<solve(x,y,l)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
—---------------------------------###############################----------------------------------------
//Mr. Lee
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100],n,ans;

bool optimalPath(bool* visited,int src, int node, int val){
    if(node==n-1){
        if(arr[src][0]!=0){
            ans=min(ans,val+arr[src][0]);
        }
    }
    for(int i=0; i<n; i++){
        if(arr[src][i]!=0 && !visited[i]){
            visited[i]=true;
            optimalPath(visited, i, node+1,val+arr[src][i]);
            visited[i]=false;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        ans=INT_MAX;
        bool visited[n]={false};
        visited[0]=true;
        optimalPath(visited,0,0,0);
        if(ans!=INT_MAX){
            cout<< ans <<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}
—---------------------------------###############################----------------------------------------
//Mr. Kim
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int x[20],y[20];
int ans, n;
int dist(int i,int j){
    int x1=x[i],x2=x[j];
    int y1=y[i],y2=y[j];
    return abs(x1-x2)+abs(y1-y2);
}
void optimalPath(bool* visited,int src,int node,int val){
    if(n==node){
        ans=min(ans,val+dist(src,n+1));
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i]=true;
            optimalPath(visited,i,node+1,val+dist(src,i));
            visited[i]=false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int j=1; j<=t; j++){
        cin>>n;
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i=1; i<=n; i++){
            cin>>x[i]>>y[i];
        }
        bool visited[n+2]={false};
        ans=INT_MAX;
        optimalPath(visited,0,0,0);
        cout<<"#"<<j<<" "<<ans<<endl;

    }
    return 0;
}
—---------------------------------###############################----------------------------------------
//Research Team
—---------------------------------###############################----------------------------------------
//Spaceship//Bomb explosion
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[20][5],n,ans;

void maxCoins(int row, int col, int temp, int bomb, int effect){
    if(row==-1){
        ans=max(ans,temp);
        return;
    }
    for(int i=-1; i<=1; i++){
        if((col+i)<0 || (col+i)>4){
            continue;
        }
        if(arr[row][col+i]==1 || arr[row][col+i]==0){
            if(bomb==0){
                maxCoins(row-1,col+i,temp+arr[row][col+i],bomb,effect-1);
            }else{
                maxCoins(row-1,col+i,temp+arr[row][col+i],bomb,effect);
            }
        }else{
            if(bomb==0){
                if(effect>0){
                    maxCoins(row-1,col+i,temp,bomb,effect-1);
                }
            }else{
                maxCoins(row-1,col+i,temp,0,5);
            }
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }
    ans=0;
    maxCoins(n-1,2,0,1,0);
    cout<<ans;
    return 0;
}
—---------------------------------###############################----------------------------------------
//Wormhole
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,res,temp=0;
int w[35][5];
int visited[35];

int dist(int sx, int sy,int ex, int ey){
    return abs(sx-ex)+abs(sy-ey);
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
//Omnious Number
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOminous(int a, int b, int k, int *delNos, int n){
    int count = 0;
    for(int i = a; i <= b; i++){
        int temp = i;
        int digitArray[10] = {0};

        while(temp){
            digitArray[temp%10]++;
            temp /= 10;
        }
        
        int rougeK = 0;
        for(int i=0; i<n; i++){
            rougeK += digitArray[delNos[i]];
        }

        if(rougeK < k){
            count++;
        }

    }
    return count;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int *delNos = new int[n];
    for(int i=0; i<n; i++){
        cin >> delNos[i];
    }

    cout << numberOminous(a, b, k, delNos, n) << "\n";

    return 0;
}
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
//Flip columns
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[51][51],ans;

void flip(int i){
    for(int j=0; j<n; j++){
        if(a[j][i]==1){
            a[j][i]=0;
        }else {
            a[j][i]=1;
        }
    }
}

void solve(int k){
    if(k==0){
        int tempAns=0;
        for(int i=0; i<n; i++){
            int f=0;
            for(int j=0; j<m; j++){
                if(a[i][j]==0){
                    f=1;
                    break;
                }
            }
            if(f==0){
                tempAns++;
            }
        }
        ans=max(ans,tempAns);
        return;
    }
    for(int i=0; i<m; i++){
        flip(i);
        solve(k-1);
        flip(i);
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    solve(k);
    cout<<ans;
    return 0;
}
—---------------------------------###############################----------------------------------------
//Rock Climbing
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m,l=0,f=0;
int arr[15][15],visited[15][15];

void minDiff(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m){
        return;
    }
    if(visited[i][j]){
        return;
    }
    visited[i][j]=1;
    if(arr[i][j]==3){
        f=1;
        return;
    }
    if(j+1<m && (arr[i][j+1]==1 || arr[i][j+1]==3) && visited[i][j+1]==0){
        minDiff(i,j+1);
    }
    if(j-1>=0 && (arr[i][j-1]==1 || arr[i][j-1]==3) && visited[i][j-1]==0){
        minDiff(i,j-1);
    }
    for(int h=1; h<=l; h++){
        if(h<=l && i-h>=0 && (arr[i-h][j]==1||arr[i-h][j]==3) && visited[i-h][j]==0){
            minDiff(i-h,j);
        }
    }
    for(int h=1; h<=l; h++){
        if(h<=l && i+h<n && (arr[i+h][j]==1 || arr[i+h][j]==3) && visited[i+h][j]==0){
            minDiff(i+h,j);
        }
    }

}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(l=0; l<n; l++){
        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                visited[i][j]=0;
            }
        }
        f=0;
        minDiff(n-1,0);
        if(f){
            cout<<l;
            break;
        }
    }
    return 0;
}
//Finding in a infinite sequence
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define small 1000000
#define large 1000000000000000
long long ans,a,b,c,k;

long long val(long long x){
    return a*x+b*x*floor(log2(x))+c*x*x*x;
}

int main()
{
    a = 2, b = 1, c = 1;
    k = 12168587437017;
    
    long long start = 1, end = small;
    if(c==0){
        end=large;
    }
    ans=0;
    
    while(start<=end){
        long long mid=(start+end)/2;
        if(k==val(mid)){
            ans=mid;
            break;
        }
        else if(val(mid)>k){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
