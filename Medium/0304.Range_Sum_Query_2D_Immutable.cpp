#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace Solution304
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0304.Range_Sum_Query_2D_Immutable.cpp"
    using namespace Solution304;

    int main()
    {
        Solution304::Range_Sum_Query_2D_Immutable useClass;
        Solution304::Range_Sum_Query_2D_Immutable::Range_Sum_Query_2D_Immutable_Model getTestModel = useClass.GetTestData001();
        string result = useClass.getHint(getTestModel.secret, getTestModel.guess);

        getTestModel = useClass.GetTestData002();
        result = useClass.getHint(getTestModel.secret, getTestModel.guess);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 查找字符串中的所有字謎
    /// </summary>
    class Range_Sum_Query_2D_Immutable
    {
#pragma region Model
    public:
        class Range_Sum_Query_2D_Immutable_Model
        {
        public:
            string secret;
            string guess;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///           Think：        
        ///         Runtime: 
        ///   Memory Usage : 
        ///Time complexity :
        /// <returns></returns>
        //NumMatrix(vector<vector<int>>& matrix) {
        //    
        //}

        int sumRegion(int row1, int col1, int row2, int col2) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Range_Sum_Query_2D_Immutable_Model GetTestData001(void)
        {
            Range_Sum_Query_2D_Immutable_Model result;
            return result;
        };
/*
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

*/

#pragma endregion TestData
    };
}