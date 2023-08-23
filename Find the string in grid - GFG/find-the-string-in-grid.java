//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s1[0]);
            int m = Integer.parseInt(s1[1]);
            char[][] grid = new char[n][m];
            for(int i = 0; i < n; i++){
                String S = br.readLine().trim();
                for(int j = 0; j < m; j++){
                    grid[i][j] = S.charAt(j);
                }
            }
            String word = br.readLine().trim();
            Solution obj = new Solution();
            int[][] ans = obj.searchWord(grid, word);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++){
                    System.out.print(ans[i][j] + " ");
                }
                System.out.println();
            }
            if(ans.length==0)
            {
                System.out.println("-1");
            }

        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    int moves[][] = {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{1,-1},{1,1},{-1,-1}};
    boolean visit[][];
    int dp[][][][];
    boolean dfs(char grid[][],String word,int d,int x,int y,int idx){
        if(idx == word.length()) return true;
        if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) return false;
        if(grid[x][y] != word.charAt(idx)) return false;
        if(dp[x][y][d][idx] != -1) return dp[x][y][d][idx] == 1 ? true : false;
        if(dfs(grid,word,d,x + moves[d][0],y + moves[d][1],idx + 1)){
            dp[x][y][d][idx] = 1;
            return true;
        }
        dp[x][y][d][idx] = 0;
        return false;
    }
    public int[][] searchWord(char[][] grid, String word){
        List<int[]> ls = new ArrayList<>();
        int n = grid.length;
        int m = grid[0].length;
        visit = new boolean[n][m];
        dp = new int[n][m][moves.length][word.length()];
        for(var d:dp)for(var c:d) for(var a:c) Arrays.fill(a,-1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                boolean ans = false;
                for(int d = 0;d < moves.length;d++){
                    ans |= dfs(grid,word,d,i,j,0);
                }
                if(ans){
                    ls.add(new int[]{i,j});
                }
            }
        }
        return ls.toArray(new int[ls.size()][]);
    }
}