// https://leetcode.com/problems/path-with-maximum-gold/description/

class Solution {
public:
    int mx_gold = INT_MIN ;
    int m , n ;

    vector<vector<int>> directions{
            {0,1},
        {-1,0},  {1,0},
            {0,-1}
    } ;
    int f(int i , int j , vector<vector<int>> &grid)
    {
        int gold = 0 ;
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        {
            return 0 ;
        }

        int orig_gold = grid[i][j] ;
        grid[i][j] = 0 ;

        for(auto &dir : directions)
        {
            int new_i = i + dir[0] ;
            int new_j = j + dir[1] ;

            gold = max(gold , f(new_i , new_j , grid)) ;
        }

        grid[i][j] = orig_gold ;

        return orig_gold + gold ;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(grid[i][j] != 0)
                {
                   mx_gold = max(mx_gold , f(i , j , grid )) ;
                }
            }
        }
        return max(0 , mx_gold) ;
    }
};
