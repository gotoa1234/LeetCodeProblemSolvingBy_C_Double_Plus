#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution88
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy\0088.Merge_Sorted_Array.cpp"
    using namespace Solution88;
    
    int main()
    {
        Solution88::Merge_Sorted_Array useClass;
        Solution88::Merge_Sorted_Array::Merge_Sorted_Array_Model getTestModel = useClass.GetTestData001();
        useClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);
    
        getTestModel = useClass.GetTestData002();
        useClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);
    
        getTestModel = useClass.GetTestData003();
        seClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 合併排序數組
    /// </summary>
    class Merge_Sorted_Array
    {
#pragma region Model
    public:
        class Merge_Sorted_Array_Model
        {
        public:
            vector<int> nums1;
            int m;
            vector<int> nums2;
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：題目要求 時間複雜度 m + n，已知 nums1 是所有Merge後的長度，因此可以從nums1[m-1] 與 nums[n-1] 開始找出由大而小的
        ///                值一一放進去
        ///      Runtime : 0 ms Beats  100 %
        /// Memory Usage : 9 MB Beats 91.5 %
        /// </summary>
        /// <returns></returns>
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int index1 = m - 1;
            int index2 = n - 1;
            int totalIndex = m + n - 1;
            while (totalIndex >= 0)
            {
                if (index1 < 0)
                {
                    nums1[totalIndex] = nums2[index2];
                    index2--;
                }
                else if (index2 < 0)
                {
                    nums1[totalIndex] = nums1[index1];
                    index1--;
                }
                else {
                    if (nums1[index1] < nums2[index2])
                    {
                        nums1[totalIndex] = nums2[index2];
                        index2--;
                    }
                    else
                    {
                        nums1[totalIndex] = nums1[index1];
                        index1--;
                    }
                }
                totalIndex--;
            }

        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Merge_Sorted_Array_Model GetTestData001(void)
        {
            Merge_Sorted_Array_Model result;
            result.nums1 = { 1,2,3,0,0,0 };
            result.m = 3;
            result.nums2 = { 2,5,6 };
            result.n = 3;
            return result;//expect: [1,2,2,3,5,6]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Merge_Sorted_Array_Model GetTestData002(void)
        {
            Merge_Sorted_Array_Model result;
            result.nums1 = { 1};
            result.m = 1;
            result.nums2 = {  };
            result.n = 0;
            return result;//expect: [1]
        };

        /// <summary>
        /// test 3
        /// </summary>
        Merge_Sorted_Array_Model GetTestData003(void)
        {
            Merge_Sorted_Array_Model result;
            result.nums1 = { 0 };
            result.m = 0;
            result.nums2 = { 1 };
            result.n = 1;
            return result;//expect: [1]
        };
#pragma endregion TestData
    };
}