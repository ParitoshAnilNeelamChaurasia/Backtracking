// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    int n ;

    vector<vector<int>> ans ;

    void f(int idx , vector<int> &curr , int target , vector<int>& candidates)
    {

        if(target < 0)
        {
            return  ;
        }

        if(target == 0)
        {
            ans.push_back(curr) ;
            return  ;
        }

        // take 

        for(int i = idx ; i < n ; ++i)
        {
            if(i > idx && candidates[i] == candidates[i-1])
            {
                continue ;
            }
        curr.push_back(candidates[i]) ;
        f(i+1 , curr , target - candidates[i] , candidates) ;
        curr.pop_back() ;
        }

        // not_take

        // f(idx+1 , curr , target , candidates) ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size() ;

        vector<int> curr ;

        sort(candidates.begin() , candidates.end()) ;

        f(0 , curr , target , candidates) ;

        return ans ;
    }
};
