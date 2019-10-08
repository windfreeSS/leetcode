#include "../all.cpp"

// 动态规划
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗 :9 MB, 在所有 C++ 提交中击败了87.43%的用户
// 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<bool>> grid(s.size(), vector<bool>(s.size(), false));

        for (int i = 0; i < wordDict.size(); ++i)
        {
            size_t start = 0;
            while (true)
            {
                size_t pos = s.find(wordDict[i], start);
                if (pos == std::string::npos)
                {
                    break;
                }
                size_t end = pos + wordDict[i].size();
                grid[pos][end - 1] = true;
                // start = end;
                ++start;
            }
        }


        vector<bool> dp = grid[s.size()-1];  // dp[pos] 表示从pos处到末尾的字符串，是可以分割的
        for (int i = s.size() - 2; i >= 0; --i)
        {
            for (int col = i; col < s.size(); ++col)
            {
                if(!grid[i][col])
                {
                    continue;
                }
    
                if(col==(s.size()-1))
                {
                    dp[i] = true;
                }
                else if(dp[col+1])
                {
                    dp[i] = true;
                }
            }

        }


        return dp[0];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> data = {"aaaa","aaa"};
    s.wordBreak("aaaaaaa",data);
    return 0;
}
