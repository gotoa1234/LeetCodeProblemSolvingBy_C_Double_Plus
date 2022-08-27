#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution62
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0062.Unique_Paths.cpp"
    using namespace Solution62;

    int main()
    {
        Solution62::Unique_Paths useClass;
        Solution62::Unique_Paths::Unique_Paths_Model getTestModel = useClass.GetTestData001();
        int result = useClass.uniquePaths(getTestModel.m, getTestModel.n);

        getTestModel = useClass.GetTestData002();
        result = useClass.uniquePaths(getTestModel.m, getTestModel.n);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �W�S���|
    /// </summary>
    class Unique_Paths
    {
#pragma region Model
    public:
        class Unique_Paths_Model
        {
        public:
            int m;
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�i�H�αƦC�զX�ѬO���u�ѡA���Y�O�{��������qDP�U��
        ///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
        /// Memory Usage : 5.8 MB,   less than 98.66 % of C++ online submissions for Unique Paths.
        /// <returns></returns>
        int uniquePaths(int m, int n) {
            // ���� : (m+n-2)! / (n-1)! (m-1)! 
            int pathCount = m + n - 2;//�̵u�i����I��l��
            int yMax = m - 1;//y�b����
            double result = 1;
            for (int index = 1; index <= yMax; index++)
                result *= (pathCount - yMax + index) / index;
            return result;
        }

    public:
        int uniquePaths2(int m, int n) {
        
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return solve2(0, 0, m, n, dp);
        };
    private:
        int solve2(int x, int y, int maxX, int maxY, vector<vector<int>>& dp)
        {
            if (x == maxX - 1 && y == maxY - 1)
                return 1;            
            if (x >= maxX || y >= maxY)
                return 0;
            
            if (dp[x][y] != -1)
                return dp[x][y];

			int right = solve2(x + 1, y, maxX, maxY, dp);
			int  left = solve2(x, y + 1, maxX, maxY, dp);

            dp[x][y] = right + left;
            return dp[x][y];
        }
  
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Unique_Paths_Model GetTestData001(void)
        {
            /*
    0  1    2  3  4  5  6  n
----------------------------
0| 28  21  15 10  6  3  1
 |
1|  7  6    5  4  3  2  1
 |
2|  1  1    1  1  1  1  -1
m|
            */
            Unique_Paths_Model result;
            result.m = 3;
            result.n = 7;
            return result;//expected = 28
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Unique_Paths_Model GetTestData002(void)
        {

            Unique_Paths_Model result;
            result.m = 3;
            result.n = 2;
            return result;
        };

#pragma endregion TestData
    };
}