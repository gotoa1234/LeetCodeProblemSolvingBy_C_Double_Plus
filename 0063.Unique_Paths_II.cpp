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
    /// �W�S���|2
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
        ///         ��� �G�P0062. ��J����Y���ɭԫh�p���k0�A�M���~���DP �N�W�P�����Ȭۥ[������e��DP[y][x] ��
        ///      Runtime :   3 ms Beats 90.80 %
        /// Memory Usage : 7.8 MB Beats 69.85 %
        /// <returns></returns>
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

            //1. �ư����i�঳�Ȫ����p
            if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
                return 0;
            
            //2. �إ�dp���j�p Space : O(n*m)
            vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1));

            //3. �ѥ��W���_�I�}�l�]�A���� [m][n] �y�ЮɡA�N�O�̲׸�
            dp[0][1] = 1;
            for (int yAxis = 1; yAxis <=  obstacleGrid.size(); yAxis++)
            {
                for (int xAxis = 1; xAxis <= obstacleGrid[0].size(); xAxis++)
                {
                    //�J����Y�h���LDp�Ȫ��֭p
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