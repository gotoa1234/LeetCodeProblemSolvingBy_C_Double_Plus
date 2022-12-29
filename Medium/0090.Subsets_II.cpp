#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution90
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0090.Subsets.cpp"
    using namespace Solution90;

    int main()
    {
        Solution90::Subsets useClass;
        Solution90::Subsets::Subsets_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.subsetsWithDup(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.subsetsWithDup(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¤l¶° II
    /// </summary>
    class Subsets
    {
#pragma region Model
    public:
        class Subsets_Model
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
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Subsets_Model GetTestData001(void)
        {
            Subsets_Model result;
            result.nums = { 1,2,2 };
            return result;//expect:  [[],[1],[1,2],[1,2,2],[2],[2,2]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Subsets_Model GetTestData002(void)
        {
            Subsets_Model result;
            result.nums = { 0 };
            return result;//expect:[[], [0]]
        };

#pragma endregion TestData
    };
}