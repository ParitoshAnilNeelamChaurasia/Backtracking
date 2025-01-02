// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    int n ;

    vector<vector<string>> res ;
    vector<string> curr ;



    bool is_palindrome(string &s , int i , int j)
    {
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++ ;
                j-- ;
            }
            else
            return false ;
        }
        return true ;
    }

    void backtrack(int idx , string s )
    {
        if(idx == n)
        {
            res.push_back(curr) ;
            return ;
        }

        for(int i = idx ; i < n ; ++i)
        {
            if(is_palindrome(s , idx , i) == true)
            {
                curr.push_back(s.substr(idx , i - idx + 1)) ;

                backtrack(i+1 , s ) ;

                curr.pop_back() ;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size() ;
        
        backtrack(0 , s ) ;

        return res ;

    }
};
