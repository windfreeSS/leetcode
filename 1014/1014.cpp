#include "../all.cpp"
// 动态规划

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max_score = 0;
        int a_size = A.size();
        int net_income = A[a_size-1] - 1; //每个节点的最大净收益

        max_score = net_income + A[a_size-2];
        for(int i = a_size -3; i>=0;--i)
        {
            if(A[i+1] > net_income)
            {
                net_income = A[i+1];
            }

            --net_income;
            if( (A[i]+net_income)>max_score)
            {
                max_score = A[i] + net_income;
            }

        }
        return max_score;
    }
};

int main()
{
    vector<int> data = {200,100,300,10000,20000,2,6};
    Solution s;
    cout<<s.maxScoreSightseeingPair(data)<<endl;
}