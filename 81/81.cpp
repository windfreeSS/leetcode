#include "../all.cpp"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();

        while (start < end)
        {
            while (start < (end - 1) && nums[start] == nums[start + 1] ) ++start;
            while (start < (end - 1) && nums[end - 1] == nums[end - 2]) --end;
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] >= nums[start])
            {
                if (target<nums[mid] && target >=nums[start])
                {
                    end = mid;
                }
                else
                {
                    start = mid+1;
                }
            }
            else
            {
                if(target>nums[mid] && target<=nums[end-1])
                {
                    start = mid+1;
                }
                else{
                    end=  mid;
                }
            }


        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

// 使用二分查找，然后对不同的边界情况进行处理