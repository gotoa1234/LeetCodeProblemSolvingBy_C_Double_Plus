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
    /// ¤l¶°
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        int removeDuplicates(vector<int>& nums) {
            
            int accumulator = 0;
            int currentValue = 0;
            int finalIndex = 0;
            int index = 0;
			for (int index = 0; index < nums.size(); accumulator = 0)
            {
                currentValue = nums[index];
                while (index < nums.size() &&
                    nums[index] == currentValue)
                {
                    nums[finalIndex] = nums[index];
                    finalIndex++;
                    accumulator++;
                    index++;
                    if (accumulator >= 2)
                    {
                        while (index < nums.size() && nums[index] == currentValue)
                        {
                            index++;
                        }
                    }
                }
            }
            return finalIndex;
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