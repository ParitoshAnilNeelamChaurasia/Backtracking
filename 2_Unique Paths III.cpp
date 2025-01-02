// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    int m , n ;

    int empty_cells ;
    int res = 0 ;

    vector<vector<int>> directions {
                {0,1},
        {-1,0},        {1,0},
                {0,-1} 
    } ;

    void dfs(vector<vector<int>>& grid , int curr_count , int i , int j)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
        {
            return ;
        }

        if(grid[i][j] == 2)
        {
            if(curr_count == empty_cells)
            {
                res++ ;
            }
            return ;
        }

        grid[i][j] = -1 ; // mark it visited

        for(auto &dir : directions)
        {
            int new_i = i + dir[0] ;
            int new_j = j + dir[1] ;
            dfs(grid , curr_count+1 , new_i , new_j) ;
        }
        grid[i][j] = 0 ;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        int st_i , st_j ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(grid[i][j] == 0)
                {
                    empty_cells++ ;
                }
                if(grid[i][j] == 1)
                {
                    st_i = i , st_j = j ;
                }
            }
        }

        // for starting square (1)
        empty_cells += 1 ;
        int curr_count = 0 ;

        dfs(grid , curr_count , st_i , st_j) ;

        return res ;
    }
};
