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
        auto result1 = useClass.Subsets_IIWithDup(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.Subsets_IIWithDup(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¤l¶° II
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        vector<vector<int>> Subsets_IIWithDup(vector<int>& nums) {
            vector<vector<int>> result{};
            vector<int> compose{};
            int currentLength = 0;
            sort(nums.begin(), nums.end());
            for (int index = 0; index < nums.size(); index++)
            {
                if (!compose.empty() && compose[0] == nums[index])
                {
                    compose.push_back(nums[index]);
                }
                else
                {
                    compose.clear();
                    compose.push_back(nums[index]);
                }
                currentLength = result.size();
                result.push_back(compose);

                for (int innerIndex = 0; innerIndex < currentLength; innerIndex++)
                {
                    vector<int> container = result[innerIndex];
                    container.push_back(nums[index]);
                    result.push_back(container);
                }
            }
            result.insert(result.begin(), vector<int>());
            return result;
        }

        //void findSubsets(int ind, vector < int >& nums, vector < int >& ds, vector < vector < int >>& ans) {
        //    ans.push_back(ds);
        //    for (int i = ind; i < nums.size(); i++) {
        //        if (i != ind && nums[i] == nums[i - 1]) continue;
        //        ds.push_back(nums[i]);
        //        findSubsets(i + 1, nums, ds, ans);
        //        ds.pop_back();
        //    }
        //}
        //vector < vector < int >> subsetsWithDup(vector < int >& nums) {
        //    vector < vector < int >> ans;
        //    vector < int > ds;
        //    sort(nums.begin(), nums.end());
        //    findSubsets(0, nums, ds, ans);
        //    return ans;
        //}
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

#pragma endregion TestData
    };
}