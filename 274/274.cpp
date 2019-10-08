#include "../all.cpp"

class Solution {
public:

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> times(n+1,0); // 记录每个位置，满足要求的论文数量。比如如果总数量为10，一个引用次数为6的，起码在(10-6)=4以后可以使用

        for(int i=0;i<n;++i)
        {
            if(citations[i]>=n)
            {
                ++times[0];
            }
            else
            {
                ++times[n-citations[i]];
            }
        }
        int sum =0;
        for(int i=0;i<n;++i)
        {
            sum += times[i];
            if(sum >= (n-i) )
            {
                return (n-i);
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {3,0,6,1,5};
    cout<<s.hIndex(data)<<endl;
    return 0;
}