#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num_len = nums.size();
        int one, two, three;
        for (int i = 0; i < num_len - 2; ++i)
        {
            // get one
            one = nums[i];

            // get two
            bool find_two = false;
            int two_pos;
            for (int j = i + 1; j < num_len - 1; ++j)
            {
                if ( (nums[j] - one ) > 1)
                {
                    two = nums[j];
                    two_pos = j;
                    find_two = true;
                    break;
                }
            }
            if (!find_two)
            {
                continue;
            }

            // get three
            bool find_three = false;
            for (int k = two_pos + 1; k < num_len; ++k)
            {
                if (nums[k] <= one)
                {
                    continue;
                }
                else if (nums[k] < two)
                {
                    return true;
                }
                else if (find_three && nums[k] < three)
                {
                    return true;
                }
                find_three = true;
                three = nums[k];
            }
        }
        return false;
    }
};

int main()
{
    vector<int> data = {-1, 3, 2, 0};
    Solution s;
    cout<<s.find132pattern(data)<<endl;

}