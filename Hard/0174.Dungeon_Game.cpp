#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution174
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0174.Dungeon_Game.cpp"
    using namespace Solution174;

    int main()
    {
        Solution174::Dungeon_Game useClass;
        Solution174::Dungeon_Game::Dungeon_Game_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.calculateMinimumHP(getTestModel.dungeon);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.calculateMinimumHP(getTestModel.dungeon);
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �a���C��   
    /// </summary>
    class Dungeon_Game
    {
#pragma region Model
    public:
        class Dungeon_Game_Model
        {
        public:
            vector<vector<int>> dungeon;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�u�ƪ����A���N�P��@��p��X�ӡA�M����X�j��0���̤p��
        ///      Runtime :   4 ms Beats 91.33 %
        /// Memory Usage : 8.8 MB Beats 87.29 %
        /// </summary>
        /// <returns></returns>        
        int calculateMinimumHP(vector<vector<int>>& dungeon) 
        {
            int rowMax = dungeon.size(), colMax = dungeon[0].size();
            vector<vector<int>> dp(rowMax, vector<int>(colMax , 0));                        
            dp[rowMax - 1][colMax - 1] = min(0, dungeon[rowMax - 1][colMax - 1]);

            //1. ��Xrow���䪺��
            for (int row = rowMax - 2; row >= 0; row--) {
                dp[row][colMax - 1] = min(dungeon[row][colMax - 1] + dp[row + 1][colMax - 1], 0);
            }

            //2. ��Xcol���䪺��
            for (int col = colMax - 2; col >= 0; col--) {
                dp[rowMax - 1][col] = min(dungeon[rowMax - 1][col] + dp[rowMax - 1][col + 1], 0);
            }
          
            //3. ���X�j��0���̤p��
            for (int row = rowMax - 2; row >= 0; row--) {
                for (int cow = colMax - 2; cow >= 0; cow--) {
                    dp[row][cow] = min(dungeon[row][cow] + max(dp[row + 1][cow], dp[row][cow + 1]), 0);                                   
                }
            }
            //4. �̫������� +1 = �Z���̤p�ͩR���һ��I��
            return 1 + abs(dp[0][0]);
        }


        /// <summary>
        /// ���D�򥻪��Ѫk�A�Q�ΰʺA�W���A�Ѱg�c���̫�˱��^�_�I
        /// </summary>
        ///     (�d��1)�t�i��  : �̫᪺���צb[0][0] �o��7 
        ///               * * *    * *  *    * *  *    * *  *    *  *  *    *  *  *     * * 2      *  5  2    7  5  2
        ///               * * * -> * *  * -> * *  * -> * *  5 -> * 11  5 -> 6 11  5 ->  6 11  5 -> 6 11  5 -> 6 11  5
        ///               * * -5   * 1 -5    1 1 -5    1 1 -5    1  1 -5    1  1 -5     1  1 -5    1  1 -5    1  1 -5
        ///               
        ///      Runtime :   8 ms Beats 64.88 %
        /// Memory Usage : 8.8 MB Beats 72.47 %
        /// <returns></returns>
        int calculateMinimunHP_BaseSolution(vector<vector<int>>& dungeon)
		{
			int rowMax = dungeon.size();
			int colMax = dungeon[0].size();
			vector<vector<int>> martix(rowMax + 1, vector<int>(colMax + 1, INT_MAX));
			martix[rowMax][colMax - 1] = 1;
			martix[rowMax - 1][colMax] = 1;

			for (int row = rowMax - 1; row >= 0; row--)
			{
				for (int col = colMax - 1; col >= 0; col--)
				{
					martix[row][col] = max(1, min(martix[row + 1][col], martix[row][col + 1]) - dungeon[row][col]);
				}
			}
			return martix[0][0];
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Dungeon_Game_Model GetTestData001(void)
        {
			Dungeon_Game_Model result;
			result.dungeon = { {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5} };
			return result;//expect: 7
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Dungeon_Game_Model GetTestData002(void)
        {
            Dungeon_Game_Model result;
            result.dungeon = { {0} };
            return result;//expect:1
        };

#pragma endregion TestData
    };
}