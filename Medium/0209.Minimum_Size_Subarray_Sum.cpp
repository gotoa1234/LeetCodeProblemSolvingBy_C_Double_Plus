#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution209
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Medium\0209.Minimum_Size_Subarray_Sum.cpp"
    using namespace Solution209;

    int main()
    {
        Solution209::Minimum_Size_Subarray_Sum useClass;
        Solution209::Minimum_Size_Subarray_Sum::Minimum_Size_Subarray_Sum_Model getTestModel = useClass.GetTestData2();
        auto result = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 最小數量的子數組總和
    /// </summary>
    class Minimum_Size_Subarray_Sum
    {
#pragma region Model
    public:
        class Minimum_Size_Subarray_Sum_Model
        {
        public:
            int target;
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 此解法為O(n) 的解法，subArray需為連續性，因此用兩個索引，第一個索引(右索引)不斷前進，直到當大於等於目標時
        ///                左索引前進，並解去索引值，計算出當前長度。直到遍歷到底
        ///     題目要求 : 給出O(n) 與 O(nlog) 的解法
        ///      Runtime:     31ms Beats 97.74 %
        /// Memory Usage : 28.29mb Beats 23.78 %
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int leftIndex = 0;
            int rightIndex = 0;
            int total = 0;
            int result = INT_MAX;
            while (rightIndex < nums.size())
            {
                total += nums[rightIndex];
                while (total >= target)
                {
                    total -= nums[leftIndex];
                    result = min(rightIndex - leftIndex + 1, result);
                    leftIndex++;
                }
                rightIndex++;
            }
            return result == INT_MAX ? 0 : result;
        }


#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Size_Subarray_Sum_Model GetTestData001(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 213;
            result.nums = {12,28,83,4,25,26,25,2,25,25,25,12};
            return result;
            //Expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Size_Subarray_Sum_Model GetTestData002(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 4;
            result.nums = { 1, 4, 4 };
            return result;
            //Expect: 1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Minimum_Size_Subarray_Sum_Model GetTestData003(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 11;
            result.nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
            return result;
            //Expect:0
        };
#pragma endregion TestData
    };
}