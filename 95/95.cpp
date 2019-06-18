#include "../all.cpp"


//dp solution

class Solution {
public:
    
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0)
        {
            return vector<TreeNode*>();
        }

        
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> data = s.generateTrees(4);
    cout<<data.size()<<endl;
}