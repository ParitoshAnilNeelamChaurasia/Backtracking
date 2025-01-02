// https://leetcode.com/problems/permutations/

class Solution {
public:
    int n ;
    vector<vector<int>> res ;
    unordered_set<int> st ;

    void f(vector<int> &nums , vector<int> &curr)
    {
        if(curr.size() == n )
        {
            res.push_back(curr) ;
            return ;
        }

        for(int i = 0 ; i < n ; ++i)
        {
            if(st.find(nums[i]) == st.end())
            {
                curr.push_back(nums[i]) ;
                st.insert(nums[i]) ;

                f(nums , curr) ;

                curr.pop_back() ;
                st.erase(nums[i]) ;
            }
            else
            {
                continue ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size() ;
        
        // vector<int> curr(n); 
// initialized curr with size n, which creates a vector with default values
        vector<int> curr ;

        f(nums , curr) ;

        return res ;
    }
};
