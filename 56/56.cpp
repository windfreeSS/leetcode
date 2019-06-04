#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
	// [begin ,end)
	list<int> merge_sort(vector<vector<int>>& intervals,int begin ,int end)
	{
		if( (end-begin) == 1 )
		{
			list<int> data = {begin};
			return data;
		}
		int mid = (begin+end)/2;
		list<int> left = merge_sort(intervals,begin,mid);
		list<int> right = merge_sort(intervals,mid,end);
		list<int> result;

		while(!left.empty() 
			&& !right.empty())
		{
			if(intervals[left.front()][0]>intervals[right.front()][0])
			{
				result.push_back(right.front());
				right.pop_front();
			}
			else
			{
				result.push_back(left.front());
				left.pop_front();
			}
		}
		while(!left.empty())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		while(!right.empty())
		{
			result.push_back(right.front());
			right.pop_front();
		}

		return result;

	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int para_size = intervals.size();
        if(para_size<2)
        {
        	return intervals;
        }
        list<int> sort_begins = merge_sort(intervals,0,para_size);

        vector<vector<int>> result;
        list<int>::iterator it = sort_begins.begin();
        while(it!=sort_begins.end())
        {
        	list<int>::iterator next = it;
        	bool find_flag = false;
        	int right = intervals[*it][1];
        	++next;
        	while(next!=sort_begins.end())
        	{
        		if(intervals[*next][0]<=right)
        		{
        			right=::max(right,intervals[*next][1]);
        			++next;
        		}
        		else
        		{
        			break;
        		}
        	}
        	vector<int> data = {intervals[*it][0],right};
        	result.push_back(data);
        	it = next;


        }
        return result;
    }
};

int main()
{
	vector<vector<int>> data = {
		{1,4},{0,4}
	};
	Solution s;
	vector<vector<int>> result = s.merge(data);
	for(int i=0;i<result.size();++i)
	{
		printf("[%d,%d],",result[i][0],result[i][1]);
	}
	printf("\n");
}

// 排序合并