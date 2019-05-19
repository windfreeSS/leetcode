#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string add_str_from_small(const string& s1,const string& s2)
	{
		std::string result;
		int carry=0;
		int sum=0;
		int s1_len = s1.size();
		int s2_len = s2.size();
		char ch;
		for(int i=s1_len-1;i>=0;--i)
		{
			
			sum = carry + (s1[i]-'0') + (s2[s2_len-s1_len+i]-'0');
			if(sum>=10)
			{
				carry = 1;
				ch =  '0' + (sum-10) ;
				result = ch+ result;
			}
			else
			{
				carry = 0;
				ch = '0' + sum;
				result =  ch+ result;
			}
		}

		for(int i=s2_len-s1_len-1;i>=0;--i)
		{
			sum = carry + (s2[i]-'0');
			if(sum>=10)
			{
				carry = 1;
				ch =  '0' + (sum-10) ;
				result = ch+ result;
			}
			else
			{
				carry = 0;
				ch = '0' + sum;
				result =  ch+ result;
			}
		}
		if(carry==1)
		{
			result='1' + result;
		}

		return result;
	}

	string add_str(const string& s1,const string& s2)
	{
		if(s1.size() > s2.size())
		{
			return add_str_from_small(s2,s1);
		}
		return add_str_from_small(s1,s2);
	}
	//  calc same size [num1_begin,num1_end)
	string calc_multi_karatsuba(const string& num1,const string& num2,int n1_begin,int n1_end,int n2_begin,int n2_end)
	{
		int n1_len = n1_end-n1_begin;
		int n2_len = n2_end-n2_begin;

		if( n1_len> 4 && n2_len >4)// x1x2 * y1y2
		{
			int x1_len = n1_len -4;
			int y1_len = n2_len -4;
		
			std::string x1_y1 = calc_multi_karatsuba(num1,num2,n1_begin,n1_end-4,n2_begin,n2_end-4);
			std::string x1_y2 = calc_multi_karatsuba(num1,num2,n1_begin,n1_end-4,n2_end-4,n2_end);
			std::string x2_y1 = calc_multi_karatsuba(num1,num2,n1_end-4,n1_end,n2_begin,n2_end-4);
			std::string x2_y2 = calc_multi_karatsuba(num1,num2,n1_end-4,n1_end,n2_end-4,n2_end);

			std::string high_val = x1_y1 + string(8,'0');
			std::string mid_val = add_str(x1_y2,x2_y1) + string(4,'0');
			std::string final_val = add_str(high_val,mid_val);
			final_val = add_str(final_val,x2_y2);
			return final_val;
		}
		else if( n1_len > 4 )
		{
			std::string x1_y2 = calc_multi_karatsuba(num1,num2,n1_begin,n1_end-4,n2_begin,n2_end);
			std::string x2_y2 = calc_multi_karatsuba(num1,num2,n1_end-4,n1_end,n2_begin,n2_end);

			std::string mid_val = x1_y2 + string(4,'0');
			std::string final_val = add_str(mid_val,x2_y2);
			
			return final_val;
		}
		else if( n2_len > 4)
		{
			std::string x2_y1 = calc_multi_karatsuba(num1,num2,n1_begin,n1_end,n2_begin,n2_end-4);
			std::string x2_y2 = calc_multi_karatsuba(num1,num2,n1_begin,n1_end,n2_end-4,n2_end);

			std::string mid_val = x2_y1 + string(4,'0');
			std::string final_val = add_str(mid_val,x2_y2);
			return final_val;
		}
		else // all less then 4
		{	
			int n1 = 0;
			int n2 = 0;
			int base = 1;
			for(int i = n1_end-1;i>=n1_begin;--i)
			{
				n1+=base*(num1[i]-'0');
				base*=10;
			}
			base =1;
			for(int i=n2_end-1;i>=n2_begin;--i)
			{
				n2+=base*(num2[i]-'0');
				base*=10;
			}
			
			char chs[10]={0};
			sprintf(chs,"%d",n1*n2);
			return chs;
		}

		return "";
	}
    string multiply(string num1, string num2) {
    	int n1_len = num1.size();
    	int n2_len = num2.size();

        std::string result = calc_multi_karatsuba(num1,num2,0,n1_len,0,n2_len);
        size_t not_zero = result.find_first_not_of('0');
        if(not_zero==std::string::npos)
        {
        	return "0";
        }
        return result.substr(not_zero);
    }
};

int main()
{
	Solution s;
	cout<<s.multiply("12345678987654321","12345678987654321")<<endl;

}