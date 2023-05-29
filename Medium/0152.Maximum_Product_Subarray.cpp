#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution152
{
#pragma region Paste to execute 
    /*    #include <unordered_map>
    #include "Medium/0152.Maximum_Product_Subarray.cpp"
    using namespace Solution152;

    int main()
    {
        Solution152::Maximum_Product_Subarray useClass;
        Solution152::Maximum_Product_Subarray::Maximum_Product_Subarray_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.maxProduct(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.maxProduct(getTestModel.nums);
        return 0;
    }

    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最大積子陣列模型
    /// </summary>
    class Maximum_Product_Subarray
    {
#pragma region Model
    public:
        class Maximum_Product_Subarray_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路： 子陣列乘積具有連續性，因此可以用兩次For回圈，由前往後與由後往前
        ///                找出連續乘積最大值即為結果。
        ///      Runtime：    0 ms Beats 100 %
        /// Memory Usage： 13.9 MB Beats 35.6 %
        /// </summary>
        /// <returns></returns>
    public:
        int maxProduct(vector<int>& nums) {
            int result = nums[0];
            int caculation = 1;
            //1. 正向搜尋
            for (int index = 0; index < nums.size(); index++)
            {
                caculation *= nums[index];
                result = max(result, caculation);
                //遇到0時需要重置為1
                if (nums[index] == 0)
                    caculation = 1;
            }
            //2. 反向搜尋
            caculation = 1;
			for (int index = nums.size() - 1; index >= 0; index--)
            {
                caculation *= nums[index];
                result = max(result, caculation);
                if (nums[index] == 0)
                    caculation = 1;
            }
            return result;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Maximum_Product_Subarray_Model GetTestData001(void)
        {
            Maximum_Product_Subarray_Model result;
            result.nums = {2, 3, -2, 4};
            return result;//expect: 6
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Maximum_Product_Subarray_Model GetTestData002(void)
        {
            Maximum_Product_Subarray_Model result;
            result.nums = { -2, 0, -1 };
            return result;//expect: 0
        };
#pragma endregion TestData
    };
}