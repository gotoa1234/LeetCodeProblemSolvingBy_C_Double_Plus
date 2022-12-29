#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution63
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0063.Unique_Paths_II.cpp"
    using namespace Solution63;

    int main()
    {
        Solution63::Unique_Paths_II useClass;
        Solution63::Unique_Paths_II::Unique_Paths_II_Model getTestModel = useClass.GetTestData001();
        int result = useClass.uniquePathsWithObstacles(getTestModel.obstacleGrid);

        getTestModel = useClass.GetTestData002();
        result = useClass.uniquePathsWithObstacles(getTestModel.obstacleGrid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 獨特路徑2
    /// </summary>
    class Unique_Paths_II
    {
#pragma region Model
    public:
        class Unique_Paths_II_Model
        {
        public:
            vector<vector<int>> obstacleGrid;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：同0062. 當遇到石頭的時候則計算歸0，然後繼續用DP 將上與左的值相加成為當前的DP[y][x] 值
        ///      Runtime :   3 ms Beats 90.80 %
        /// Memory Usage : 7.8 MB Beats 69.85 %
        /// <returns></returns>
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

            //1. 排除不可能有值的狀況
            if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
                return 0;
            
            //2. 建立dp的大小 Space : O(n*m)
            vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1));

            //3. 由左上角起點開始跑，直到 [m][n] 座標時，就是最終解
            dp[0][1] = 1;
            for (int yAxis = 1; yAxis <=  obstacleGrid.size(); yAxis++)
            {
                for (int xAxis = 1; xAxis <= obstacleGrid[0].size(); xAxis++)
                {
                    //遇到石頭則跳過Dp值的累計
                    if (obstacleGrid[yAxis - 1][xAxis - 1] != 0)
                        continue;
                    dp[yAxis][xAxis] = dp[yAxis - 1][xAxis] + dp[yAxis][xAxis - 1];
                }
            }
            return dp[obstacleGrid.size()][obstacleGrid[0].size()];
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Unique_Paths_II_Model GetTestData001(void)
        {
            Unique_Paths_II_Model result;
			result.obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
            return result;//expected = 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Unique_Paths_II_Model GetTestData002(void)
        {
            Unique_Paths_II_Model result;
            result.obstacleGrid = { {0, 1},{0, 0}};
            return result;//expected = 1
        };

        /// <summary>
     /// test 3
     /// </summary>   
        Unique_Paths_II_Model GetTestData003(void)
        {
            Unique_Paths_II_Model result;
            result.obstacleGrid = { {0, 0},{0, 1} };
            return result;//expected = 1
        };


#pragma endregion TestData
    };
}