//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    bool valid(int i,int j,vector<vector<int>>&visited,vector<vector<int>>& A,int N,int M) 
    {
      if(i< 0 || i>=N || j<0 || j>=M || visited[i][j]==1 || A[i][j]==0)
      {
          return false;
      }
      
      return true;
    }
      
      
 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)
        {
            return -1;
        }
        vector<vector<int>>visited(N,vector<int>(M,0));
        vector<vector<int>>distance(N,vector<int>(M,INT_MAX));
        queue< pair<pair<int,int>, int> >q;
        
        
        q.push({{0,0},0});
        visited[0][0]=1;
        
        int row[]={0,0,-1,1};
        int col[]={-1,1,0,0};
        while(!q.empty())
        {
            pair<pair<int,int>,int>front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            
           
            int dist = front.second;
            if(r==X && c==Y)
            {
                return dist;
            }
            for(int i=0;i<4;i++)
            {
                int nr = r+row[i];
                int nc = c+col[i];
                
                if(valid(nr,nc,visited,A,N,M))
                {
                    visited[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                }
            }
            
        }
         return -1;
       
    }
   
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends