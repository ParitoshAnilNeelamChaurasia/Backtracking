// https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    int n ;
    vector<string> result ;
    unordered_set<string> st ;

    void f(int i , string &curr_sen , string s)
    {
        if(i >= n)
        {
            result.push_back(curr_sen) ;
            return ;
        }
        for(int j = i ; j < n ; ++j)
        {
            string temp = s.substr(i , j-i+1) ;

            if(st.count(temp) == true)
            {
                string temp_sentence = curr_sen ;

                // if its Ist word -> add a space
                if(!curr_sen.empty())
                {
                    curr_sen += " ";
                }

                curr_sen += temp ;


                f(j+1 , curr_sen , s) ;

                curr_sen = temp_sentence ;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size() ;

        for(auto it : wordDict)
        {
            st.insert(it) ;
        }

        string curr_sen = "" ;

        f(0 , curr_sen , s) ;

        return result ;


    }
};
