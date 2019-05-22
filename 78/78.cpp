#include <vector>
#include <iostream>
using namespace std;
void print(vector<int> data);
// backtracking
// Partition分治法
class Solution {
public:// [begin,end)
    vector<vector<int>> powerset_partition(vector<int>& nums, int begin, int end)
    {
        int nums_len = end - begin;
        if (nums_len == 1)
        {
            vector<vector<int>> result;
            vector<int> data;
            data.push_back(nums[begin]);
            result.push_back(data);
            return result;
        }
        int part_num = nums_len / 2;
        vector<vector<int>> a = powerset_partition(nums, begin, begin + part_num);
        vector<vector<int>> b = powerset_partition(nums, begin + part_num, end);


        int a_size = a.size();
        int b_size = b.size();
        vector<vector<int>> result;

        result=a;
        result.insert(result.end(),b.begin(),b.end());

        for (int i = 0; i < a_size; ++i)
        {
            for (int j = 0; j < b_size; ++j)
            {
                vector<int> data = a[i];
                data.insert(data.end(), b[j].begin(), b[j].end());
                result.push_back(data);
            }
        }
        return result;


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
        {
            vector<vector<int>> result;
            result.push_back(vector<int>());
            return result;
        }
        vector<vector<int>> result=powerset_partition(nums, 0, nums.size());
        result.push_back(vector<int>());
        return result;
    }
};

void print(vector<int> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << ",";
    }
}

int main()
{
    vector<int> data = {0,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19};
    Solution s;

    vector<vector<int>> result = s.subsets(data);
    for (int i = 0; i < result.size(); ++i)
    {
        print(result[i]);
        cout<<endl;
    }
}