#include "../all.cpp"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int num_size = nums.size();
        int find_pos = 0;
        int arr[3] = {0};

        // find first
        arr[2] = arr[1] = arr[0] = nums[find_pos];

        // find second
        for (++find_pos; find_pos < num_size; ++find_pos)
        {
            if (nums[find_pos] == arr[0])
            {
                continue;
            }
            if (nums[find_pos] > arr[0])
            {
                arr[1] = arr[0];
                arr[0] = nums[find_pos];
            }
            else
            {
                arr[1] = nums[find_pos];
            }
            break;
        }

        // find third
        for (++find_pos; find_pos < num_size; ++find_pos)
        {
            if (nums[find_pos] < arr[1])
            {
                arr[2] = nums[find_pos];
                break;
            }
            else if (nums[find_pos] == arr[1]
                     || nums[find_pos] == arr[0])
            {
            }
            else if (nums[find_pos] > arr[0])
            {
                arr[2] = arr[1];
                arr[1] = arr[0];
                arr[0] = nums[find_pos];
                break;
            }
            else // < arr[0] && > arr[1]
            {
                arr[2] = arr[1];
                arr[1] = nums[find_pos];
                break;
            }
        }

        // update 
        for (++find_pos; find_pos < num_size; ++find_pos)
        {
            if(nums[find_pos] == arr[0]
                || nums[find_pos] == arr[1]
                || nums[find_pos] == arr[2])
            {
                continue;
            }
            if (nums[find_pos] > arr[0])
            {
                arr[2] = arr[1];
                arr[1] = arr[0];
                arr[0] = nums[find_pos];
            }
            else if (nums[find_pos] > arr[1])
            {
                arr[2]=arr[1];
                arr[1]=nums[find_pos];
            }
            else if (nums[find_pos] > arr[2])
            {
                arr[2] = nums[find_pos];
            }
        }
        if(arr[1]==arr[0]
            ||arr[2]==arr[1])
        {
            return arr[0];
        }
        return arr[2];
    }
};

int main()
{
    Solution s;
    vector<int> data = {1,2};
    cout << s.thirdMax(data) << endl;
}