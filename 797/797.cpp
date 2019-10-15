class Solution {
    vector<vector<int>> result;
    vector<int> current;
public:
    void dfs(vector<vector<int>>& graph,int node)
    {
        if(node==(graph.size()-1))
        {
            current.push_back(node);
            result.push_back(current);
            current.pop_back();
            return ;
        }
        current.push_back(node);
        for(int i=0;i<graph[node].size();++i)
        {
            dfs(graph,graph[node][i]);
        }
        current.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0);
        return result;
    }
};