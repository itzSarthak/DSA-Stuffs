
//  Longest Sub-string with K unique characters
//  https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

/*

    int longestKSubstr(string s, int k) 
    {
        int res = -1;
        map<char,int>m;         ** we need map so that we can store
        int i=0,j=0;            ** no of distinct characters as well as there occurance.
        
        while(j < s.size())
        {
            m[s[j]]++;
                
            if(m.size() == k)           ** m.size() represents no of distinct characters
                res = max(res,j-i+1);

            else if(m.size() > k)
            {
                while(m.size() > k )
                {
                        m[s[i]]--;
                        
                        if(m[s[i]] == 0)
                            m.erase(s[i]);
                            
                        i++;
                }
            }
            j++;
        }
        
        return res;
    }
    
    ** Why we need Map Data Structure ?
    **  So that we can store the elements and there occurance.

*/