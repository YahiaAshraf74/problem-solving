#include <ios>
static auto fastInput = []() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = (int)grid.size() , area = 0 , mx = 0 ;
        for (int i = 0 ; i < N ;i++){
            mx = 0 ;
        	for (int j = 0 ; j < N ; j++){
        		grid[i][j] ? ++area : 0 ;
        		mx = max(mx,grid[j][i]) ;
        	}
        	area += mx ;
        }
        for (int i = 0 ; i < N ;i++){
            mx = 0 ;
        	for (int j = 0 ; j< N ;j++){
        		mx = max(mx,grid[i][j]) ;
        	}
        	area += mx ;
        }
        return area ;
    }
};
