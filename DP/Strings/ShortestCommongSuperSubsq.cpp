
  string shortestCommonSupersequence(string s1, string s2)
  {
      int n = s1.size();
      int m = s2.size();

      // Here we do shifting to accomodated base case from memoization **
      vector<vector<int>>dp(n + 1,vector<int>(m + 1,0));



      // base case **
      for(int idx1 = 0; idx1 <= n; idx1++)
          dp[idx1][0] = 0;

      for(int idx2 = 0; idx2 <= m; idx2++)
          dp[0][idx2] = 0;


      for(int idx1 = 1; idx1 <= n; idx1++)
      {
          for(int idx2 = 1; idx2 <= m; idx2++)
          {
              if(s1[idx1 - 1] == s2[idx2 - 1])
                  dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                  // here idx1 & idx2 in the dp array corresponds to idx - 1th index of str

              else
                  dp[idx1][idx2] = max(dp[idx1 - 1][idx2],dp[idx1][idx2 - 1]);
          }
      }

      // now we have dp array which we can use 
      int i = n,j = m;
      string ans = "";

      while(i > 0 && j > 0)
      {
          if(s1[i - 1] == s2[j - 1])
          {
              ans+= s1[i - 1];
              i--;
              j--;
          }
          else if(dp[i - 1][j] > dp[i][j - 1])
          {
              ans+= s1[i - 1];
              i--;
          }
          else
          {
              ans+= s2[j - 1];
              j--;
          }

      }

      while(i > 0)
      {
          ans+= s1[i - 1];
          i--;
      }

      while(j > 0)
      {
          ans+= s2[j - 1];
          j--;
      }

      reverse(ans.begin(),ans.end());
      return ans;
  }
