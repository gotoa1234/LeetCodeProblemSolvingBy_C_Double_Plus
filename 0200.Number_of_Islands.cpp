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
        ///         思路 :
        ///      Runtime : 
        /// Memory Usage : 
        int numIslands(vector<vector<char>>& grid) {
            return 0;
        }
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