// https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:
    int n ;
    int dp[201][1001] ;

    int f(int idx , vector<int> &nums , int target)
    {
        if(idx >= n || target < 0)
        {
            return 0 ;
        }
        if(target == 0)
        {
            return 1 ;
        }

        if(dp[idx][target] != -1)
        {
            return dp[idx][target];
        }


        int take = f(0 , nums , target - nums[idx]) ;

        int not_take = f(idx+1 , nums , target) ;

        return dp[idx][target] = take + not_take ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size() ;

        memset(dp,-1,sizeof(dp)) ;

        return f(0 , nums , target) ;
    }
};
