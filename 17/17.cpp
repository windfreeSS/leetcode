#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:
    vector<string> calcSubComb(string& digits)
    {
        
        static vector<string> phone_digit_chars = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int digits_len = digits.size();
        vector<string> comb_result;
        if(digits_len==0)
        {
            return comb_result;
        }
        if(digits_len==1)
        {
            int digit_val = digits[0]-'0';
            for(int i=0;i<phone_digit_chars[digit_val].size();++i)
            {
                string data;
                data+=phone_digit_chars[digit_val][i];
                comb_result.push_back(data);
            }
            return comb_result;
        }

        string left_str =digits.substr(0,digits_len/2);
        string right_str = digits.substr(digits_len/2);

        vector<string> left_comb = calcSubComb(left_str);
        vector<string> right_comb = calcSubComb(right_str);

        int left_size = left_comb.size();
        int right_size = right_comb.size();

        for( int left_i=0;left_i<left_size;++left_i)
        {
            for(int right_i =0;right_i < right_size;++right_i)
            {
                comb_result.push_back(left_comb[left_i]+right_comb[right_i]);
            }
        }

        return comb_result;

    }
    vector<string> letterCombinations(string digits) {
        static vector<string> phone_digit_chars = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int digits_len = digits.size();
        vector<string> comb_result;
        if(digits_len==0)
        {
            return vector<string>();
        }
        if(digits_len==1)
        {
            int digit_val = digits[0]-'0';
            for(int i=0;i<phone_digit_chars[digit_val].size();++i)
            {
                string data;
                data+=phone_digit_chars[digit_val][i];
                comb_result.push_back(data);
            }
            return comb_result;
        }

        string left_str = digits.substr(0,digits_len/2);
        string right_str = digits.substr(digits_len/2);
        vector<string> left_comb = calcSubComb(left_str);
        vector<string> right_comb = calcSubComb(right_str);
        int left_size = left_comb.size();
        int right_size = right_comb.size();

        for( int left_i=0;left_i<left_size;++left_i)
        {
            for(int right_i =0;right_i < right_size;++right_i)
            {
                comb_result.push_back(left_comb[left_i]+right_comb[right_i]);
            }
        }

        return comb_result;
    }
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         static vector<string> phone_digit_chars = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         static vector<int> phone_digit_chars_len={0,0,3,3,3,3,3,4,3,4};

//         int digits_len = digits.size();
//         vector<string> comb_result;

//         vector<int> digit_states(digits_len);
//         char* comb_str = new char[digits_len+1];
//         if(comb_str==0)
//         {
//             return comb_result;
//         }
//         memset(comb_str,0,digits_len+1);
        
//         int track_i = 0;
//         while(true)
//         {
//             if(track_i>=digits_len)
//             {
//                 comb_result.push_back(comb_str);
//                 --track_i;
//                 printf("size: %d\n",comb_result.size());
//                 continue;
//             }
//             int digit_val = digits[track_i] - '0' ;
//             if(digit_states[track_i] >= phone_digit_chars_len[digit_val])
//             {
//                 if(track_i==0)   
//                 {
//                     break;
//                 }
//                 digit_states[track_i]=0;
//                 --track_i;
//                 continue;
//             }
//             comb_str[track_i]= phone_digit_chars[digit_val][digit_states[track_i]];
//             ++digit_states[track_i];
//             ++track_i;
//         }

//         delete [] comb_str;
//         return comb_result;
//     }
// };

int main()
{
    Solution s;
    
    vector<string> result = s.letterCombinations("23348");
    for(int i=0;i<result.size();++i)
    {
        cout<<result[i]<<",";
    }
    cout<<"end"<<endl;

}

