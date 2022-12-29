#include <vector>
#include <string>
#include <sstream> 
using namespace std;

namespace Solution72
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0072.Edit_Distance.cpp"
    using namespace Solution72;

    int main()
    {
        Solution72::Edit_Distance useClass;
        Solution72::Edit_Distance::Edit_Distance_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.minDistance(getTestModel.word1, getTestModel.word2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minDistance(getTestModel.word1, getTestModel.word2);

        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 編輯距離
    /// </summary>
    class Edit_Distance
    {
#pragma region Model
    public:
        class Edit_Distance_Model
        {
        public:
            string word1;
            string word2;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 :利用DP，2維陣列裡Y軸為word1(來源)，與X軸為word2(目的)，若相同時繼承 [y-1][x-1] 的值
        ///               否則用 [y-1][x-1],[y][x-1],[y-1][x]最小的值+1 作為[y][x]的值，
        ///      Runtime : 16 ms Beats 74.21 %
        /// Memory Usage :  9 MB Beats 60.70 %
        int minDistance(string word1, string word2) {
            
            int yAxisMax = word1.length();
            int xAxisMax = word2.length();
            int yAxis = 0, xAxis = 0;
            //1. 初始化DP結構
            vector<vector<int>> dp(yAxisMax + 1, vector<int>(xAxisMax + 1));
            for (yAxis = 0; yAxis <= yAxisMax; yAxis++)
                dp[yAxis][0] = yAxis;
            for (xAxis = 0; xAxis <= xAxisMax; xAxis++)
                dp[0][xAxis] = xAxis;

            //2. y軸為來源字串, x軸為目標字串
            for(yAxis = 1 ;yAxis <= yAxisMax; yAxis++)
            {                
                for (xAxis = 1; xAxis <= xAxisMax; xAxis++)
                {
                    //3-1. 字元相同時，用之前Dp算出最小的結果
                    if (word1[yAxis - 1] == word2[xAxis - 1])                    
                        dp[yAxis][xAxis] = dp[yAxis - 1][xAxis - 1];
                    else//3-2. 字元不同時則從該dp[yAxis][xAxis]位置的上、左上、左取一個最小的資料 + 1 為本次結果 
                        dp[yAxis][xAxis] = 1 + min( dp[yAxis - 1][xAxis - 1] , min(dp[yAxis][xAxis - 1], dp[yAxis - 1][xAxis]));
                }
            }

            //4. 最後Dp最後一個陣列位置所存的值為所需最小異動次數
            return dp[yAxisMax][xAxisMax];
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Edit_Distance_Model GetTestData001(void)
        {
            Edit_Distance_Model result;
            result.word1 = "horse";
            result.word2 = "ros";
            return result;
            //Expect:3
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Edit_Distance_Model GetTestData002(void)
        {
            Edit_Distance_Model result;
            result.word1 = "intention";
            result.word2 = "execution";
            return result;
            //Expect:5
        };
#pragma endregion TestData
    };
}