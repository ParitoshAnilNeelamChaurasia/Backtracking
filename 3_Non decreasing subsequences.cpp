// https://leetcode.com/problems/non-decreasing-subsequences/description/

class Solution {
public:
    int n ; 
    void f(vector<int> &nums , int idx , vector<int> &curr , vector<vector<int>> &res)
    {
        if(curr.size() >= 2)
        {
            res.push_back(curr) ;
        }

        unordered_set<int> st ;

        for(int i = idx ; i < n ; ++i)
        {
            if ((curr.empty() || nums[i] >= curr.back()) && st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]) ;
                curr.push_back(nums[i]) ;
                f(nums , i+1 , curr , res) ;
                curr.pop_back() ;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size() ;

        vector<vector<int>> res ;

        vector<int> curr ;

        f(nums , 0 , curr , res) ;

        return res ;
    }
};
