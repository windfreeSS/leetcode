#include "../all.cpp"


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < sizeof(int)*8; ++i)
        {
            int flag = 1 << i;
            int bit_cnt = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                if ((flag & nums[j]) != 0)
                {
                    ++bit_cnt;
                }
            }
            if ((bit_cnt % 3) != 0)
            {
                result |= flag;
            }
        }

        return  result;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {0, -1, 0, -1, 0, -1, -99};
    cout << s.singleNumber(data) << endl;
    return 0;
}