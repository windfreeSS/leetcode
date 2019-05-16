#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nums_len = nums.size();
        if(nums_len<3)
        {
            return vector<vector<int>>();
        }

        std::sort(nums.begin(), nums.end());
        vector<vector<int>> equation_solution;
        vector<int> zeros_eq;
        zeros_eq.push_back(0);
        zeros_eq.push_back(0);
        zeros_eq.push_back(0);

        
        return equation_solution;

    }
};

int main()
{
    Solution s;
    vector<vector<int>> result;
    vector<int> data={-1, 0, 1, 2, -1, -4};
    result = s.threeSum(data);

    for(int i=0;i<result.size();++i)
    {
        printf("%d,%d,%d\n",result[i][0],result[i][1],result[i][2]);
    }

}