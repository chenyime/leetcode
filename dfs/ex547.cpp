class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        vector<bool> visited(M.size(), false);
        for ( int i = 0; i < visited.size(); i++ ) {
            if(!visited[i]) 
            {
                bfs(i, visited, M);
                ret++;
            }
        }
        return ret;
    }
private:
    void bfs(int i, vector<bool>& visited, vector<vector<int>>& M) {
        visited[i] = true;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for ( int j = 0; j < M[cur].size(); j++ ) {
                if ( M[cur][j] == 1 && !visited[j] ) {
                    visited[j] = true;
                    Q.push(j);
                }
            }
        }

    }
};