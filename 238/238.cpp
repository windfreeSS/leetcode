#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int nums_len = nums.size();

        int* product_from_begin = new int[nums_len];
        if (product_from_begin == 0)
        {
            return result;
        }
        int* product_to_end = new int [nums_len]; //
        if (product_to_end == 0)
        {
            delete []product_from_begin;
            return result;
        }

        int mul_val = 1;
        for (int i = 0; i < nums_len; ++i) //calc product from begin
        {
            mul_val *= nums[i];
            product_from_begin[i] = mul_val;
        }

        mul_val = 1;
        for (int i = nums_len - 1; i >= 0; --i)//calc product from end
        {
            mul_val *= nums[i];
            product_to_end[i] = mul_val;
        }

        for (int i = 0; i < nums_len; ++i)
        {
            if (i == 0)
            {
                result.push_back(product_to_end[i + 1]);
                continue;
            }
            else if (i == (nums_len - 1))
            {
                result.push_back(product_from_begin[i - 1]);
                continue;
            }
            result.push_back( product_from_begin[i - 1]*product_to_end[i + 1]);
        }


        delete [] product_from_begin;
        delete [] product_to_end;

        return result;
    }
};


int main()
{
    Solution s;
    vector<int> data = {1, 2};
    vector<int> result = s.productExceptSelf(data);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ",";
    }
    cout << endl;
}
