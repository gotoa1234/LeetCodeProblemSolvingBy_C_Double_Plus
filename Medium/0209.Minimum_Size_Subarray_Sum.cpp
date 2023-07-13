#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution209
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0209.Minimum_Size_Subarray_Sum.cpp"
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
        ///         思路 :         
        ///      Runtime:  
        /// Memory Usage : 
        int minSubArrayLen(int target, vector<int>& nums) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Size_Subarray_Sum_Model GetTestData001(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 7;
            result.nums = {2, 3, 1, 2, 4, 3};
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