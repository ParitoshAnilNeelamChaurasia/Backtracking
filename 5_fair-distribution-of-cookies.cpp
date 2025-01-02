// https://leetcode.com/problems/fair-distribution-of-cookies/description/

class Solution {
public:
    int n ;
    int res = INT_MAX ;

    void f(int ind , vector<int> &ans , vector<int> &cookies , int k)
    {
        if(ind == n)
        {
            int an = *max_element(ans.begin() , ans.end()) ;
            res = min(res , an) ;
            return ;
        }

        int candy = cookies[ind] ;

        for(int i = 0 ; i < k ; ++i)
        {
            ans[i] += candy ;

            f(ind+1 ,ans , cookies , k) ;

            ans[i] -= candy ;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size() ;

        vector<int> ans(k) ;

        f(0 , ans , cookies , k) ;
        return res ;
    }
};
