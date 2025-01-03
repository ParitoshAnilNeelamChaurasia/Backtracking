// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>> ans ;

    void f(int num , int k , int n , vector<int> &curr)
    {
        if(n == 0 && k == 0)
        {
            ans.push_back(curr) ;
            return ;
        }

        if(num > 9)
        {
            return ;
        }

        curr.push_back(num) ;

        f(num+1 , k-1 , n-num ,curr ) ;

        curr.pop_back() ;

        f(num+1 , k , n , curr) ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr ;
        f(1 , k , n , curr) ;

        return ans ;
    }
};
