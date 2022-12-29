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
    /// �s��Z��
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
        ///         ��� :�Q��DP�A2���}�C��Y�b��word1(�ӷ�)�A�PX�b��word2(�ت�)�A�Y�ۦP���~�� [y-1][x-1] ����
        ///               �_�h�� [y-1][x-1],[y][x-1],[y-1][x]�̤p����+1 �@��[y][x]���ȡA
        ///      Runtime : 16 ms Beats 74.21 %
        /// Memory Usage :  9 MB Beats 60.70 %
        int minDistance(string word1, string word2) {
            
            int yAxisMax = word1.length();
            int xAxisMax = word2.length();
            int yAxis = 0, xAxis = 0;
            //1. ��l��DP���c
            vector<vector<int>> dp(yAxisMax + 1, vector<int>(xAxisMax + 1));
            for (yAxis = 0; yAxis <= yAxisMax; yAxis++)
                dp[yAxis][0] = yAxis;
            for (xAxis = 0; xAxis <= xAxisMax; xAxis++)
                dp[0][xAxis] = xAxis;

            //2. y�b���ӷ��r��, x�b���ؼЦr��
            for(yAxis = 1 ;yAxis <= yAxisMax; yAxis++)
            {                
                for (xAxis = 1; xAxis <= xAxisMax; xAxis++)
                {
                    //3-1. �r���ۦP�ɡA�Τ��eDp��X�̤p�����G
                    if (word1[yAxis - 1] == word2[xAxis - 1])                    
                        dp[yAxis][xAxis] = dp[yAxis - 1][xAxis - 1];
                    else//3-2. �r�����P�ɫh�q��dp[yAxis][xAxis]��m���W�B���W�B�����@�ӳ̤p����� + 1 ���������G 
                        dp[yAxis][xAxis] = 1 + min( dp[yAxis - 1][xAxis - 1] , min(dp[yAxis][xAxis - 1], dp[yAxis - 1][xAxis]));
                }
            }

            //4. �̫�Dp�̫�@�Ӱ}�C��m�Ҧs���Ȭ��һݳ̤p���ʦ���
            return dp[yAxisMax][xAxisMax];
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// ���ո��1
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
        /// ���ո��2
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