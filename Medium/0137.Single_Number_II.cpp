#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution137
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0137.Single_Number_II.cpp"
    using namespace Solution137;

    int main()
    {
        Solution137::Single_Number_II useClass;
        Solution137::Single_Number_II::Single_Number_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.singleNumber(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ³æ¸¹2
    /// </summary>
    class Single_Number_II
    {
#pragma region Model
    public:
        class Single_Number_II_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>        
        int singleNumber(vector<int>& nums) {
            return{};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Single_Number_II_Model GetTestData001(void)
        {
            Single_Number_II_Model result;
            result.nums = { 2,2,3,2 };
            return result;//expect:  3
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Single_Number_II_Model GetTestData002(void)
        {
            Single_Number_II_Model result;
            result.nums = { 0,1,0,1,0,1,99 };
            return result;//expect:  99
        };


#pragma endregion TestData
    };
}