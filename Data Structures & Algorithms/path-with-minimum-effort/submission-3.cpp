using tiii = tuple<int, int, int>;

class Solution {
public:

    int inf = 1e9;

    int minimumEffortPath(vector<vector<int>>& heights) {
        // ideja je da idemo dijkstru na max razdaljinu i guess

        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<tiii, vector<tiii>, greater<tiii>> q;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<bool> visited(rows*cols, false);
        vector<int> dist(rows*cols, inf);
        dist[0] = 0;
        q.push({0, 0, 0});
        visited[0] = true;

        while(!q.empty()){
            auto [h, x, y] = q.top();
            q.pop();

            if(h > dist[x*cols + y])
                continue;
            
            if(x == rows-1 && y == cols-1){
                return h;
            }

            for(auto a:direction){
                int nx = x+a[0];
                int ny = y+a[1];

                if(nx < 0 || ny < 0 || nx > rows-1 || ny > cols-1)
                    continue;

                int newdist = max(dist[x*cols+y], abs(heights[nx][ny] - heights[x][y]));
                
                if(newdist < dist[nx*cols + ny]){
                    q.push({newdist, nx, ny});
                    dist[nx*cols + ny] = newdist;
                }
            }

        }



        return -1;

    }
};