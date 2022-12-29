#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution81
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0081.Search_in_Rotated_Sorted_Array_II.cpp"
    using namespace Solution81;
    
    int main()
    {
        Solution81::Search_in_Rotated_Sorted_Array_II useClass;
        Solution81::Search_in_Rotated_Sorted_Array_II::Search_in_Rotated_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.search(getTestModel.nums, getTestModel.target);
    
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.search(getTestModel.nums, getTestModel.target);
    
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 在旋轉排序數組中搜索 II
    /// </summary>
    class Search_in_Rotated_Sorted_Array_II
    {
#pragma region Model
    public:
        class Search_in_Rotated_Sorted_Array_II_Model
        {
        public:
            vector<int> nums;
            int target;
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
        bool search(vector<int>& nums, int target) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Search_in_Rotated_Sorted_Array_II_Model GetTestData001(void)
        {
            Search_in_Rotated_Sorted_Array_II_Model result;
			result.nums = { 2,5,6,0,0,1,2 };
            result.target = 0;
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Search_in_Rotated_Sorted_Array_II_Model GetTestData002(void)
        {
            Search_in_Rotated_Sorted_Array_II_Model result;
            result.nums = { 2,5,6,0,0,1,2 };
            result.target = 3;
            return result;//expect:false
        };
#pragma endregion TestData
    };
}