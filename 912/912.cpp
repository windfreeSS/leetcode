class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int base_len = 100001;
        vector<int> base_num(base_len);
        for(int i=0;i<nums.size();++i)
        {
            ++base_num[nums[i]+50000];
        }

        vector<int> result;
        for(int i=0;i<base_len;++i)
        {
            for(int j=0;j<base_num[i];++j)
            {
                result.push_back(i-50000);
            }
        }
        return result;
    }
};