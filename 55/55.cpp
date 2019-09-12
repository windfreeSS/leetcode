#include "../all.cpp"

class Solution {
public:

    bool canJump(vector<int>& nums)
    {
        if (nums.empty())
            return false;
        else if (nums.size() == 1)
            return true;

        int valid_access_distance = 0;  //当前能访问到的最大索引位置.检测某个点是否可以到达,只需要判断该点的索引,是否小于这个最大索引
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > valid_access_distance)
                return false;
            valid_access_distance = max(valid_access_distance, i + nums[i]);
        }
        return true;

    }

    // 从后遍历 更新状态
    bool canJump_v1(vector<int>& nums) {
        int v_len = nums.size();

        vector<bool> access_state(v_len, false);
        access_state[v_len - 1] = true;
        for (int i = v_len - 1; i >= 0; --i)
        {
            if (!access_state[i])
            {
                continue;
            }
            for (int upd_i = i - 1; upd_i >= 0; --upd_i)
            {
                if ( nums[upd_i] >= (i - upd_i) )
                {   // upd_i can access i
                    access_state[upd_i] = true;
                }
            }
        }

        return access_state[0];
    }
};




int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {3, 2, 1, 0, 4};
    cout << s.canJump(data) << endl;
    return 0;
}