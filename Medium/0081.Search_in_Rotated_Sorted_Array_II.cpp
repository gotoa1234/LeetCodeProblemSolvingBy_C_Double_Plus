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
        ///         思路 ：參考第33題相同的做法，但是本題有重複的數值在 nums 中，所以需要判斷 == 的狀況
        ///      Runtime :    7 ms Beats 85.24 %
        /// Memory Usage : 14.1 MB Beats 47.52 %
        /// </summary>
        /// <returns></returns>
        bool search(vector<int>& nums, int target) {
            int leftIndex = 0;
            int rightIndex = nums.size() - 1;
            int mid = 0;
            while (leftIndex <= rightIndex) 
            {
                int mid = (leftIndex + rightIndex) / 2;
                if (nums[mid] == target) 
                    return true;
                if (nums[leftIndex] < nums[mid])//1. 不可用 <= 判斷
                {
                    if (nums[leftIndex] <= target && 
                        target < nums[mid]
                        )
                        rightIndex = mid - 1;
                    else 
                        leftIndex = mid + 1;
                }
                else if (nums[mid] < nums[leftIndex])//使用else if判斷另一側
                {
                    if (nums[mid] < target &&
                        target <= nums[rightIndex]
                        )
                        leftIndex = mid + 1; 
                    else
                        rightIndex = mid - 1;
                }
                else //如果上面都不符合表示重複的值，用索引往右的方式繼續判斷
                    leftIndex++;
            }
            return false;
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
			result.nums = { 5, 1, 3 };
            result.target = 3;
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

        /// <summary>
        /// test 3
        /// </summary>   
        Search_in_Rotated_Sorted_Array_II_Model GetTestData003(void)
        {
            Search_in_Rotated_Sorted_Array_II_Model result;
            result.nums = { 1, 0, 1, 1, 1};
            result.target = 0;
            return result;//expect:false
        };

        
#pragma endregion TestData
    };
}