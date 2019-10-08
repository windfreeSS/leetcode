#include "../all.cpp"


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ret = 0;
        int n = citations.size();
        int begin = 0;
        int end = n;
        while(begin<end)        
        {
            int mid = begin+(end-begin)/2;
            int check_size = n-mid;
            if(citations[mid] == check_size )
            {
                return check_size;
            }
            else if(citations[mid] > check_size )
            {
                ret = check_size;
                end = mid;
            }
            else
            {
                begin = mid+1;
            }

        }

        return ret;
    }
};