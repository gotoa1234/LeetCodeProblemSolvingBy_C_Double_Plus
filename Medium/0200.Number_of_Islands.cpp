#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution200
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0200.Number_of_Islands.cpp"
    using namespace Solution200;
    
    int main()
    {
        Solution200::Number_of_Islands useClass;
        Solution200::Number_of_Islands::Number_of_Islands_Model getTestModel = useClass.GetTestData2();
        int result = useClass.numIslands(getTestModel.grid);
    
        getTestModel = useClass.GetTestData002();
        result = useClass.numIslands(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 島的數量
    /// </summary>
    class Number_of_Islands
    {
#pragma region Model
    public:
        class Number_of_Islands_Model
        {
        public:
            vector<vector<char>> grid;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 遍歷二維陣列每個元素，每當看到'1'時，開始做dfs延伸，如果走到'1' 加1 並且標記為x表示走過。
        ///      Runtime:    42 ms, faster than 81.30% of C++ online submissions for Number of Islands.
        /// Memory Usage : 12.2 MB,   less than 97.02% of C++ online submissions for Number of Islands.
        int numIslands(vector<vector<char>>& grid) {
            int result = 0;
            int xMax = grid.size();
            int yMax = grid[0].size();
            for (int xIndex = 0; xIndex < xMax; xIndex++)
            {
                for (int yIndex = 0; yIndex < yMax; yIndex++)
                {
                    if (grid[xIndex][yIndex] == '1')
                    {
                        island(grid, xIndex, yIndex, xMax, yMax);
                        result += 1;
                    }
                }
            }
            return result;
        }
    private:
        void island(vector<vector<char>>& grid, int x, int y, int xMax, int yMax) {
            if (x >= xMax || 
                y >= yMax ||
                x < 0 || 
                y < 0 || 
                grid[x][y] != '1'
                )
                return;

            //標記走過
            grid[x][y] = 'x';
            island(grid, x + 1, y, xMax, yMax);
            island(grid, x - 1, y, xMax, yMax);
            island(grid, x, y + 1, xMax, yMax);
            island(grid, x, y - 1, xMax, yMax);
        };
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Number_of_Islands_Model GetTestData001(void)
        {
            Number_of_Islands_Model result;
			vector<vector<char>> input =
			{
				{'1', '1', '1', '1', '0'},
				{'1', '1', '0', '1', '0'},
				{'1', '1', '0', '0', '0'},
				{'0', '0', '0', '0', '0'}
			};
            result.grid = input;
            return result;
            //Expect: 1
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Number_of_Islands_Model GetTestData002(void)
		{
			Number_of_Islands_Model result;
			vector<vector<char>> input =
			{
				{'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
			};
			return result;
            //Expect:3
		};
#pragma endregion TestData
    };
}