#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void makeComb(const vector<int>& states, const vector<int>&data, vector<int>&result)
    {
        for (int i = 0; i < states.size(); ++i)
        {
            for(int j=0;j<states[i]-1;++j)
            {
                result.push_back(data[i]);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        // sort
        std::sort(candidates.begin(), candidates.end());

        vector<int> comb;
        int can_size = candidates.size();
        vector<int> states(can_size, 0); //states[i] * candidates[i]
        int curr_sum = 0;
        int test_pos = 0;
        while (true)
        {
            if (test_pos < 0)
            {
                break;
            }
            if (test_pos >= can_size)
            {
                --test_pos;
                continue;
            }

            if (states[test_pos] > 0)
            {
                curr_sum += candidates[test_pos];
            }

            if (curr_sum < target)
            {
                ++states[test_pos];
                ++test_pos;
            }
            else if (curr_sum == target)
            {
                vector<int> comb;
                ++states[test_pos];
                makeComb(states,candidates,comb);
                --states[test_pos]; // align
                result.push_back(comb);
                curr_sum -= states[test_pos] * candidates[test_pos];
                states[test_pos] = 0 ;
                --test_pos;   
            }
            else
            {
                curr_sum -= states[test_pos] * candidates[test_pos];
                states[test_pos] = 0 ;
                --test_pos;
            }
        }

        return result;

    }
};

int main()
{
    vector<int> data = {3,4,5};
    Solution s;
    vector<vector<int>> result = s.combinationSum(data,2);
    for(int i=0;i<result.size();++i)
    {
        for(int j=0;j<result[i].size();++j)
        {
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
}