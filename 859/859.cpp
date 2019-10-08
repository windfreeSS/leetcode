
// 两种情况，
// 1、A和B完全相等，但是本身含有重复的字符串。比如 aab aab ，交换前两个字母，还是相同的。


class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len_a = A.size();
        int len_b = B.size();

        if (len_a != len_b
                || len_a < 2)
        {
            return false;
        }

        vector<int> diffs;
        vector<int> ch_counts(26, 0);
        for (int i = 0; i < len_a; ++i)
        {
            ++ch_counts[A[i]-'a'];
            if(A[i]!=B[i])
            {
                diffs.push_back(i);
            }
        }

        int diff_len = diffs.size();
        if(diff_len==0)
        {
            for(int i=0;i<26;++i)
            {
                if(ch_counts[i]>1)
                {
                    return true;
                }
            }
        }
        else if(diff_len==2)
        {
            if(A[diffs[0]] == B[diffs[1]]
                && A[diffs[1]] == B[diffs[0]])
            {
                return true;
            }
        }

        return false;

    }
};