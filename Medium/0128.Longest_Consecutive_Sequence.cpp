#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution128
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0128.Longest_Consecutive_Sequence.cpp"
    using namespace Solution128;

    int main()
    {
        Solution128::Longest_Consecutive_Sequence useClass;
        Solution128::Longest_Consecutive_Sequence::Longest_Consecutive_Sequence_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.longestConsecutive(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.longestConsecutive(getTestModel.n);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.longestConsecutive(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最長連續序列
    /// </summary>
    class Longest_Consecutive_Sequence
    {
#pragma region Model
    public:
        class Longest_Consecutive_Sequence_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        int longestConsecutive(vector<int>& nums) {
            return {};
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Longest_Consecutive_Sequence_Model GetTestData001(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 100, 4, 200, 1, 3, 2 };
            return result;//expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Longest_Consecutive_Sequence_Model GetTestData002(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 0,3,7,2,5,8,4,6,0,1 };
            return result;//expect: 9
        };

#pragma endregion TestData
    };
}