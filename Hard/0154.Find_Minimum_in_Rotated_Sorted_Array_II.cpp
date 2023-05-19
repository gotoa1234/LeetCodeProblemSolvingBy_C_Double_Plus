#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution154
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0154.Find_Minimum_in_Rotated_Sorted_Array_II.cpp"
    using namespace Solution154;

    int main()
    {
        Solution154::Find_Minimum_in_Rotated_Sorted_Array_II useClass;
        Solution154::Find_Minimum_in_Rotated_Sorted_Array_II::Find_Minimum_in_Rotated_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.findMin(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findMin(getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.findMin(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �b����ƧǼƲդ����̤p��2
    /// </summary>
    class Find_Minimum_in_Rotated_Sorted_Array_II
    {
#pragma region Model
    public:
        class Find_Minimum_in_Rotated_Sorted_Array_II_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ����G 
        ///      Runtime�G 
        /// Memory Usage�G 
        /// </summary>
        /// <returns></returns>
    public:
        int findMin(vector<int>& nums) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Find_Minimum_in_Rotated_Sorted_Array_II_Model GetTestData001(void)
        {
            Find_Minimum_in_Rotated_Sorted_Array_II_Model result;
            result.nums = { 1, 3, 5 };
            return result;//expect: 1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Find_Minimum_in_Rotated_Sorted_Array_II_Model GetTestData002(void)
        {
            Find_Minimum_in_Rotated_Sorted_Array_II_Model result;
            result.nums = { 2, 2, 2, 0, 1 };
            return result;//expect: 0
        };
#pragma endregion TestData
    };
}