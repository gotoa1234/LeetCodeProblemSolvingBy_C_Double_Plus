#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution733
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0733.Flood_Fill.cpp"
    using namespace Solution733;
    
    int main()
    {
    	Solution733::Flood_Fill useClass;
    	Solution733::Flood_Fill::Flood_Fill_Model getTestModel = useClass.GetTestData001();
    	vector<vector<int>> result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);
    	return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 洪水填充
    /// </summary>
    class Flood_Fill
    {
#pragma region Model
    public:
        class Flood_Fill_Model
        {
        public:
            vector<vector<int>> image;
            int sr;
            int sc;
            int color;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 :利用DFS (Depth-First Search，深度優先搜尋)加上遞迴找出上下左右可以填充的顏色值
        ///      Runtime :    7 ms, faster than 95.33% of C++ online submissions for Flood Fill.
        /// Memory Usage : 13.8 MB,   less than 98.78% of C++ online submissions for Flood Fill.
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
			dfs(image, sr, sc, color, image[sr][sc]);
            return image;
        }
    private:
        void dfs(vector<vector<int>>& image, int x, int y, int color, int currentColor) {
            //不符合條件就結束
            if (x < 0 || y < 0 ||
                x == image.size() || y == image[0].size() ||
                image[x][y] == color ||
                image[x][y] != currentColor)
            {
                return;
            }
            //可以影響的點，變為指定顏色
            image[x][y] = color;
            //上下左右移動
            dfs(image, x, y + 1, color, currentColor);
            dfs(image, x, y - 1, color, currentColor);
            dfs(image, x+1, y, color, currentColor);
            dfs(image, x-1, y, color, currentColor);
        }
        
    public:

#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Flood_Fill_Model GetTestData001(void)
        {
            Flood_Fill_Model result;
			vector<vector<int>> input = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
            result.image = input;
            result.sc = 1;
            result.sc = 1;
            result.sc = 2;
            return result;
            //Expect: [[2,2,2],[2,2,0],[2,0,1]]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Flood_Fill_Model GetTestData002(void)
        {
            Flood_Fill_Model result;
            vector<vector<int>> input = {{0, 0, 0}, {0, 0, 0}};
            result.image = input;
            result.sc = 0;
            result.sc = 0;
            result.sc = 0;
            return result;
            //Expect:  [[0,0,0],[0,0,0]]
        };
#pragma endregion TestData
    };
}