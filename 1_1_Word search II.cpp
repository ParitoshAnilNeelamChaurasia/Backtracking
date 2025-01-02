// https://leetcode.com/problems/word-search-ii/description/


// Time Limit exceeded -> Use Trie
class Solution {
public:
    int m, n;                              
    vector<string> ans;                    
    vector<vector<int>> directions = {     
        {0, 1},  // Right
        {-1, 0}, // Up
        {1, 0},  // Down
        {0, -1}  // Left
    };

    bool find(int i, int j, vector<vector<char>>& board, string& word, int idx) 
    {
        // Check boundaries and if the cell is already visited or doesn't match the current character
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[idx]) 
        {
            return false;
        }

        // If all characters in the word are matched
        if (idx == word.size() - 1) 
        {
            return true;
        }

        char temp = board[i][j];  // Save the current cell value
        board[i][j] = '$';        // Mark the cell as visited

        // Explore all four directions
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(new_i, new_j, board, word, idx + 1)) 
            {
                board[i][j] = temp; // Restore the cell before returning
                return true;
            }
        }

        board[i][j] = temp; // Restore the cell during backtracking
        return false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();      
        n = board[0].size();   
        ans.clear();           

        for (string& word : words) 
        {
            bool found = false; 
            // Check every cell in the board for the starting character of the word
            for (int i = 0; i < m && !found; ++i) 
            {
                for (int j = 0; j < n && !found; ++j) 
                {
                    if (board[i][j] == word[0] && find(i, j, board, word, 0)) 
                    {
                        ans.push_back(word); // Add the word to the result if found
                        found = true;        // Avoid adding duplicates
                    }
                }
            }
        }
        return ans;
    }
};
