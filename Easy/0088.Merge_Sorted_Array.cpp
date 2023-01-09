#include <iostream>
#include <unordered_map>
#include <string>
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
        ///         思路 ：結果是以nums1做為存放，因此先複製出nums1[m] 以前的元素，然後進行合併到nums1中
        ///      Runtime : 0 ms Beats  100 %
        /// Memory Usage : 9 MB Beats 91.5 %
        /// </summary>
        /// <returns></returns>
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int nums1Index = 0;
            int nums2Index = 0;
            //1. clone nums1[m]以前的元素
            vector<int> clonenums1(m);
            for (int index = 0; index < m; index++)
                clonenums1[index] = nums1[index];

            //2. Merge to nums1
            while (nums1Index != m && nums2Index != n)
            {
                if (clonenums1[nums1Index] < nums2[nums2Index])
                {
                    nums1[nums1Index + nums2Index] = clonenums1[nums1Index];
                    nums1Index++;
                }
                else
                {
                    nums1[nums1Index + nums2Index] = nums2[nums2Index];
                    nums2Index++;
                }
            }

            //3. pedding nums1
            while (nums1Index != m)
            {
                nums1[nums1Index + nums2Index] = clonenums1[nums1Index];
                nums1Index++;
            }

            //4. pedding nums2
            while (nums2Index != n)
            {
                nums1[nums1Index + nums2Index] = nums2[nums2Index];
                nums2Index++;
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