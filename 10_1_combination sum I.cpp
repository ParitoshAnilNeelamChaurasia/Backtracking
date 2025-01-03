// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> ans ;
    int n ;

    void f(int idx , vector<int> &candidates , int target , vector<int> &curr)
    {
        if(idx >= n || target < 0)
        {
            return ;
        }

        if(target == 0)
        {
            ans.push_back(curr) ;
            return ;
        }

        // take
        curr.push_back(candidates[idx]) ;

        f(idx , candidates , target - candidates[idx] , curr) ;

        curr.pop_back() ;

        // not take

        f(idx+1 , candidates , target , curr) ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size() ;
        vector<int> curr ;
        f(0 , candidates , target , curr) ;

        return ans ;
    }
};
