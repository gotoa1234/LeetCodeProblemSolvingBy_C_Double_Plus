#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution78
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0078.Subsets.cpp"
    using namespace Solution78;

    int main()
    {
        Solution78::Subsets useClass;
        Solution78::Subsets::Subsets_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.subsets(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.subsets(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 子集
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
        ///         思路 ：利用規則產出子集演算法，以[1,2,3]為例
        /// step 1: {1}               => 放入元素1 ，此時比較已產生的元素(但沒有因此跳過)
        /// step 2: {1},{2}           => 放入元素2 ，此時比較已產生的元素(有{1} 所以組成 {1,2})
        /// step 3: {1},{2},{1,2}    
        /// step 4: {1},{2},{1,2},{3} => 放入元素3 ，此時比較已產生的元素(有 {1},{2},{1,2} 所以組成 {1,3}, {2,3}, {1,2,3})
        /// ......最終 : {1},{2},{1,2},{3}, {1,3}, {2,3}, {1,2,3}
        ///      Runtime :    0 ms Beats 100 %
        /// Memory Usage :  7.2 MB Beats 70.72 %
        /// </summary>
        /// <returns></returns>
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result{};
            int currentLength = 0;
            int index = 0;
            for (auto& item : nums)
            {
                currentLength = result.size();
                result.push_back({ item });
                for (index = 0; index < currentLength; index++)
                {
                    vector<int> temp = result[index];
                    temp.push_back(item);
                    result.push_back(temp);
                }
            }            
            result.insert(result.begin(), vector<int>());
            return result;
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
            result.nums = { 1, 2, 3 };            
            return result;//expect:   [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Subsets_Model GetTestData002(void)
        {
            Subsets_Model result;
            result.nums = {0};            
            return result;//expect:[[], [0]]
        };

#pragma endregion TestData
    };
}