#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution80
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0080.Remove_Duplicates_from_Sorted_Array_II.cpp"
    using namespace Solution80;

    int main()
    {
        Solution80::Remove_Duplicates_from_Sorted_Array_II useClass;
        Solution80::Remove_Duplicates_from_Sorted_Array_II::Remove_Duplicates_from_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.removeDuplicates(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.removeDuplicates(getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.removeDuplicates(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 子集
    /// </summary>
    class Remove_Duplicates_from_Sorted_Array_II
    {
#pragma region Model
    public:
        class Remove_Duplicates_from_Sorted_Array_II_Model
        {
        public:
            vector<int> nums;            
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：進行nums遍歷，並且利用一個變數紀錄目前的長度
        ///                遍歷的當前值的大於前兩個位置的值，表示可以將當前的值放入
        ///                (若已放了兩個就不會是大於)
        ///      Runtime :  0 ms Beats   100 %
        /// Memory Usage : 11 MB Beats 43.15 %
        /// </summary>
        /// <returns></returns>
        int removeDuplicates(vector<int>& nums) {
            int findIndex = 0;
            //1. 遍歷
            for (int index = 0; index < nums.size(); index++)
            {
                //2. 每次[0],[1] 都可以放原陣列的 [0],[1]
                //   接著就照規則-> 當前值的大於前兩個位置的值，表示可以將當前的值放入
                if (findIndex < 2 || 
                    nums[index] > nums[findIndex - 2]
                    )
                {
                    nums[findIndex] = nums[index];
                    findIndex++;
                }
            }
            return findIndex;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Remove_Duplicates_from_Sorted_Array_II_Model GetTestData001(void)
        {
            Remove_Duplicates_from_Sorted_Array_II_Model result;
            result.nums = { 1, 1, 1, 2, 2, 3 };            
            return result;//expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Remove_Duplicates_from_Sorted_Array_II_Model GetTestData002(void)
        {
            Remove_Duplicates_from_Sorted_Array_II_Model result;
            result.nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
            return result;//expect:7
        };
#pragma endregion TestData
    };
}