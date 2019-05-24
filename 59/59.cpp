#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> matrix;
    	for(int i=0;i<n;++i)
    	{
    		matrix.push_back(vector<int>(n,0));
    	}

    	int forward = 0;//0 right 1:bottom 2:left 3:top
    	int left=0;
    	int right=n;
    	int top=0;
    	int bottom=n;
    	int val = 1;
    	while(true)
    	{
    		if(left>=right
    			|| top >= bottom)
    		{
    			break;
    		}
    		switch(forward)
    		{
    			case 0:
    			{
    				for(int i=left;i<right;++i)
    				{
    					matrix[top][i]=val;
    					++val;
    				}
    				++top;
    			}
    			break;
    			case 1:
    			{
    				for(int i=top;i<bottom;++i)
    				{
    					matrix[i][right-1]=val;
    					++val;
    				}
    				--right;
    			}
    			break;
    			case 2:
    			{
    				for(int i=right-1;i>=left;--i)
    				{
    					matrix[bottom-1][i]=val;
    					++val;
    				}
    				--bottom;
    			}

    			break;
    			case 3:
    			{
    				for(int i=bottom-1;i>=top;--i)
    				{
    					matrix[i][left]=val;
    					++val;

    				}
    				++left;
    			}

    			break;
    		}
    		++forward;
    		if(forward>3)
    		{
    			forward=0;
    		}

    	}
    	return matrix;
        
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
	vector<vector<int>> result = s.generateMatrix(6);
	for(int i=0;i<result.size();++i)
	{
		print(result[i]);
	}
}