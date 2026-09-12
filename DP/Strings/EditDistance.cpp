// Memoization **
int solve(int i,int j,string& s1,string& s2, vector<vector<int>>& dp)
  {
      // base case

      // Delete Operation **
      if(j < 0) return i + 1;

      // Insert Operation **
      if(i < 0) return j + 1;

      if(dp[i][j] != -1) return dp[i][j];

      if(s1[i] == s2[j])
          return dp[i][j] = solve(i - 1,j - 1,s1,s2,dp);

      else
      {
          // we are converting first string to second 
          // all operations are performed on first string **
        
          // insertion **
          int x = 1 + solve(i,j - 1,s1,s2,dp);

          // deletion **
          int y = 1 + solve(i - 1,j,s1,s2,dp);

          // replacement **
          int z = 1 + solve(i - 1,j - 1,s1,s2,dp);

          return dp[i][j] = min(x,min(y,z));
      }
  }
  int minDistance(string s1, string s2)
  {
      int n = s1.size();
      int m = s2.size();

      vector<vector<int>>dp(n,vector<int>(m,-1));
      return solve(s1.size() - 1,s2.size() - 1,s1,s2,dp);
  }



  // Tabulation
    int minDistance(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n + 1,vector<int>(m + 1,0));

        // base case 
        // i = 0
        for(int j = 0; j <=m; j++)  dp[0][j] = j;

        // j = 0
        for(int i = 0; i <=n; i++)  dp[i][0] = i;




        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                {
                    // insertion **
                    int x = 1 + dp[i][j - 1];

                    // deletion **
                    int y = 1 + dp[i - 1][j];

                    // replacement **
                    int z = 1 + dp[i - 1][j -1];

                    dp[i][j] = min(x,min(y,z));
                }
            }
        }

        return dp[n][m];
    }
