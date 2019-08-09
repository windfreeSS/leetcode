#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int num_size = nums.size();
        int left_sum = 0;
        int right_sum = 0;

        for (int i = 0; i < num_size; ++i)
        {
            right_sum += nums[i];
        }

        for (int i = 0; i < num_size; ++i)
        {
            right_sum -= nums[i];
            if ( left_sum == right_sum )
            {
                return i;
            }
            left_sum += nums[i];
        }

        return -1;

    }
};

int main()
