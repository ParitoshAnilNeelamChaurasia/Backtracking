// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    int n ;
    vector<string> ans ;

    void f(int idx , string &temp , unordered_map<char,string> mp , string digits)
    {
        if(idx >= n)
        {
            ans.push_back(temp) ;
            return ;
        }

        char ch = digits[idx] ;
        string str = mp[ch] ;

        for(int i = 0 ; i < str.size() ; ++i)
        {
            temp.push_back(str[i]) ;
            f(idx + 1 , temp , mp , digits) ;
            temp.pop_back() ;
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size() ;

        unordered_map<char,string> mp ;

        if(n == 0)
        {
            return {} ;
        }

        mp['2'] = "abc" ;
        mp['3'] = "def" ;
        mp['4'] = "ghi" ;
        mp['5'] = "jkl" ;
        mp['6'] = "mno" ;
        mp['7'] = "pqrs" ;
        mp['8'] = "tuv" ;
        mp['9'] = "wxyz" ;

        string temp = "" ;

        f(0 , temp , mp , digits) ;

        return ans ;
    }
};
