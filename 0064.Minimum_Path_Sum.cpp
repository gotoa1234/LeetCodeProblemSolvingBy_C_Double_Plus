#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution64
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0064.Minimum_Path_Sum.cpp"
    using namespace Solution64;

    int main()
    {
        Solution64::Minimum_Path_Sum useClass;
        Solution64::Minimum_Path_Sum::Minimum_Path_Sum_Model getTestModel = useClass.GetTestData001();
        int result = useClass.minPathSum(getTestModel.grid);

        getTestModel = useClass.GetTestData002();
        result = useClass.minPathSum(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 最小加總路徑
    /// </summary>
    class Minimum_Path_Sum
    {
#pragma region Model
    public:
        class Minimum_Path_Sum_Model
        {
        public:
            vector<vector<int>> grid;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// <returns></returns>
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.empty() || grid[0].empty())
                return 0;

            for (int yAxis = 0; yAxis < grid.size(); yAxis++)
            {
                for (int xAxis = 0; xAxis < grid[0].size(); xAxis++)
                {
                    if (yAxis == 0 && xAxis == 0)
                        continue;
                    
                    int upValue = yAxis == 0 ? INT_MAX : grid[yAxis - 1][xAxis];
                    int leftValue = xAxis == 0 ? INT_MAX : grid[yAxis][xAxis - 1];
					grid[yAxis][xAxis] += min(upValue, leftValue);
                }
            }
            return grid[grid.size() - 1][grid[0].size() - 1];
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Path_Sum_Model GetTestData001(void)
        {
            Minimum_Path_Sum_Model result;
			result.grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
            return result;//expected = 7
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Path_Sum_Model GetTestData002(void)
        {
            Minimum_Path_Sum_Model result;
            result.grid = { {1, 2, 3},{4, 5, 6}};
            return result;//expected = 12
        };

#pragma endregion TestData
    };
}