#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int first_not_nine = 0;
        int digit_count = digits.size();
        for(first_not_nine=digit_count-1;first_not_nine>=0;--first_not_nine)
        {
        	if(digits[first_not_nine]!=9)
        	{
        		break;
        	}
        }
        if(first_not_nine<0)
        {
        	vector<int> result(digit_count+1,0);
        	result[0]=1;
        	return result;
        }
        ++digits[first_not_nine] ;
        for(int i = first_not_nine+1;i<digit_count;++i)
        {
        	digits[i]=0;
        }
        return digits;
    }
};

int main()
{
	vector<int> data ={1,2,4,9};
	Solution s;
	vector<int> result = s.plusOne(data);
	for(int i=0;i<result.size();++i)
	{
		cout<<result[i];	
	}
	
}