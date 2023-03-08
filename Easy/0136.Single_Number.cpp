#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution136
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy/0136.Single_Number.cpp"
    using namespace Solution136;

    int main()
    {
        Solution136::Single_Number useClass;
        Solution136::Single_Number::Single_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.singleNumber(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 單號
    /// </summary>
    class Single_Number
    {
#pragma region Model
    public:
        class Single_Number_Model
        {
        public:            
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用互斥或邏輯閘的特性，兩個相同為0，最後剩下的結果就是唯一值
        ///      Runtime :   15 ms Beats 91.55 %
        /// Memory Usage : 16.9 MB Beats 88.33 %
        /// </summary>
        /// <returns></returns>        
        int singleNumber(vector<int>& nums) 
        {
            int result = 0;
            for (auto& value : nums)             
                result = result ^ value;            
            return result;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Single_Number_Model GetTestData001(void)
        {
            Single_Number_Model result;
			result.nums = { 2,2,1 };
            return result;//expect:  1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Single_Number_Model GetTestData002(void)
        {
            Single_Number_Model result;
            result.nums = { 4,1,2,1,2 };
            return result;//expect:  4            
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Single_Number_Model GetTestData003(void)
        {
            Single_Number_Model result;
            result.nums = {1 };
            return result;//expect:  1
        };

#pragma endregion TestData
    };
}