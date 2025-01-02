// https://leetcode.com/problems/combinations/description/

class Solution {
public:
    vector<vector<int>> res ;
    void f(int st_ind , int k , vector<int> &curr , int n)
    {
        if(k == 0)
        {
            res.push_back(curr) ;
            return ;
        }

        for(int i = st_ind ; i <= n ; ++i)
        {
        curr.push_back(i) ;

        f(i+1 , k-1 , curr , n) ;

        curr.pop_back() ;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr ;

        f(1 , k , curr , n) ;

        return res ;
    }
};
