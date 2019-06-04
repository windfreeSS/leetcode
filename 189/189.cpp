#include <vector>
#include <iostream>
using namespace std;
#include "..\useful_code\helper.cpp"

class Solution {
public:
    void rotate_v1(vector<int>& nums, int k, int num_size) {
        for (int i = 0; i < k; ++i)
        {
            int tmp = nums[num_size - 1];
            for (int j = num_size - 1; j > 0; --j)
            {
                nums[j] = nums[j - 1];
            }
            nums[0] =  tmp;
        }
    }
    // [begin end)
    void reverse(vector<int>& nums, int begin, int end)
    {
        int mid = (begin + end) / 2;
        for (int i = begin; i < mid; ++i)
        {
            int tmp = nums[i];
            nums[i] = nums[end - i + begin - 1];
            nums[end - i + begin - 1] = tmp;
        }
    }
    void rotate_v2(vector<int>& nums, int k, int num_size)
    {
        int visit_count = 0;
        int next_assign_pos = 0;
        int correct_num = nums[num_size-k];

        while (visit_count < num_size)
        {
            int old_num = nums[next_assign_pos];
            nums[next_assign_pos] = correct_num;
            correct_num = old_num;
            next_assign_pos = (next_assign_pos + k) % num_size;
            ++visit_count;
        }
    }

    void rotate_v3(vector<int>& nums, int k, int num_size)
    {
        reverse(nums, 0, num_size);
        reverse(nums, 0, k);
        reverse(nums, k, num_size);

    }
    void rotate(vector<int>& nums, int k) {
        int num_size = nums.size();
        if (num_size < 2)
        {
            return ;
        }
        k = k % num_size;
        if (k == 0)
        {
            return ;
        }
        return rotate_v3(nums, k, num_size);
    }
};

int main()
{
    Solution s;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(data, 3);
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << ",";
    }
    cout << endl;
}