#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution201
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0201.Bitwise_AND_of_Numbers_Range.cpp"
    using namespace Solution201;
    
    int main()
    {
        Solution201::Bitwise_AND_of_Numbers_Range useClass;
        Solution201::Bitwise_AND_of_Numbers_Range::Bitwise_AND_of_Numbers_Range_Model getTestModel = useClass.GetTestData2();
        int result = useClass.numIslands(getTestModel.grid);
    
        getTestModel = useClass.GetTestData002();
        result = useClass.numIslands(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 按位元，AND邏輯閘數字範圍
    /// </summary>
    class Bitwise_AND_of_Numbers_Range
    {
#pragma region Model
    public:
        class Bitwise_AND_of_Numbers_Range_Model
        {
        public:
            int left;
            int right;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 將left 與right 找出向右位移的次數(不同則向右)，直到跳出後，依照次數做2bit 進制位移
        ///         題意 : 給定left 與 right 然後找出之間所有的2進制做AND 最後的值為多少
        ///          EX  : [5, 7]  101
        ///                        110
        ///                        111
        ///                  結果為100 就是4
        ///      Runtime: 
        /// Memory Usage :
        int rangeBitwiseAnd(int left, int right) {
            int count = 0;
            while (left != right) {
                left = left >> 1;
                right = right >> 1;
                count++;
            }
            return (left << count);
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Bitwise_AND_of_Numbers_Range_Model GetTestData001(void)
        {
            Bitwise_AND_of_Numbers_Range_Model result;
            result.left = 5;
            result.right = 7;            
            return result;
            //Expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Bitwise_AND_of_Numbers_Range_Model GetTestData002(void)
		{
			Bitwise_AND_of_Numbers_Range_Model result;
            result.left = 0;
            result.right = 0;
			return result;
            //Expect:0
		};
#pragma endregion TestData
    };
}