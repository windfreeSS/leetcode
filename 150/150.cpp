#include "../all.cpp"

// 使用栈进行处理

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> data; 
        int data_len ;
        for(int i=0;i<tokens.size();++i)
        {
            data_len = data.size();
            if(tokens[i]=="+")
            {
                data[data_len-2] = data[data_len-2] + data[data_len-1];
                data.pop_back();
            }
            else if(tokens[i]=="-")
            {
                data[data_len-2] = data[data_len-2] - data[data_len-1];
                data.pop_back();
            }
            else if(tokens[i]=="*")
            {
                data[data_len-2] = data[data_len-2] * data[data_len-1];
                data.pop_back();
            }
            else if(tokens[i]=="/")
            {
                data[data_len-2] = data[data_len-2] / data[data_len-1];
                data.pop_back();
            }
            else
            {
                data.push_back(stoi(tokens[i]));
            }
        }

        return data[0];
    }
};

