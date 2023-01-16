#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution90
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium\0090.Subsets_II.cpp"
    using namespace Solution90;

    int main()
    {
        Solution90::Subsets_II useClass;
        Solution90::Subsets_II::Subsets_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.subsetsWithDup(getTestModel.nums);
      
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.subsetsWithDup(getTestModel.nums);
      
        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.subsetsWithDup(getTestModel.nums);
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 子集 II
    /// </summary>
    class Subsets_II
    {
#pragma region Model
    public:
        class Subsets_II_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：參考0078的子集產出，不同的是需先排序(便於判斷重複)若當前元素與上一元素相同時跳過不進行添加
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 7.7 MB Beats 49.94 %
        /// </summary>
        /// <returns></returns>
        vector<vector<int>> _result;
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<int> compose{};
            sort(nums.begin(), nums.end());
            findSubsetII(0, compose, nums);
            return _result;
        }
        
        void findSubsetII(int currentIndex, vector<int>& compose, vector<int>& nums)
        {
            _result.push_back(compose);
            for (int index = currentIndex; index < nums.size(); index++)
            {
                if (currentIndex != index &&
                    nums[index] == nums[index - 1])
                    continue;
                compose.push_back(nums[index]);
                findSubsetII(index + 1, compose, nums);
                compose.pop_back();
            }
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Subsets_II_Model GetTestData001(void)
        {
            Subsets_II_Model result;
            result.nums = { 1,2,2 };
            return result;//expect:  [[],[1],[1,2],[1,2,2],[2],[2,2]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Subsets_II_Model GetTestData002(void)
        {
            Subsets_II_Model result;
            result.nums = { 0 };
            return result;//expect:[[], [0]]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Subsets_II_Model GetTestData003(void)
        {
            Subsets_II_Model result;
            result.nums = { 1,4,4,4,4 };
            return result;//expect:[[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
        };

#pragma endregion TestData
    };
}