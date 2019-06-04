#include <vector>
#include <iostream>
#include "../all.cpp"
using namespace std;
// dynamic program

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int t_size = T.size();
        vector<int> result (t_size, 0);
        for (int i = t_size - 2; i >= 0; --i)
        {
            if (T[i + 1] > T[i])
            {
                result[i] = 1;
                continue;
            }
            int next = i + 2;
            while (next < t_size)
            {
                if(T[next] > T[i])
                {
                    result[i] = next-i;
                    break;
                }
                if (result[next] ==0)
                {
                    break;
                }
                next += result[next];
            }

        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> data = {55,38,53,81,61,93,97,32,43,78};
    vector<int> result = s.dailyTemperatures(data);
    print(result);
}