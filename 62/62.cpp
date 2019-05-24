#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> data);

// dynamic program

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
        {
            return 1;
        }
        vector<int> bottom_data(m,1);
        vector<int> top_data(m,1);
        for(int i=n-2;i>=0;--i)
        {
            for(int j=m-2;j>=0;--j)
            {
                top_data[j]=top_data[j+1]+bottom_data[j];
            }
            bottom_data = top_data;
        }
        return top_data[0];
        
    }
};
void print(vector<int> data)
{
    for(int i=0;i<data.size();++i)
    {
        cout<<data[i]<<",";
    }
    cout<<endl;
}

int main()
{
    Solution s;
    cout<<s.uniquePaths(10,10)<<endl;
}