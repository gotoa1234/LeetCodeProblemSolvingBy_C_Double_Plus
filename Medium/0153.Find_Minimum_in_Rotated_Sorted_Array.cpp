#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution153
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0153.Find_Minimum_in_Rotated_Sorted_Array.cpp"
    using namespace Solution153;

    int main()
    {
        Solution153::Find_Minimum_in_Rotated_Sorted_Array useClass;
        Solution153::Find_Minimum_in_Rotated_Sorted_Array::Find_Minimum_in_Rotated_Sorted_Array_Model getTestModel = useClass.GetTestData001();
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
    /// �b����ƧǼƲդ����̤p��
    /// </summary>
    class Find_Minimum_in_Rotated_Sorted_Array
    {
#pragma region Model
    public:
        class Find_Minimum_in_Rotated_Sorted_Array_Model
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
        Find_Minimum_in_Rotated_Sorted_Array_Model GetTestData001(void)
        {
            Find_Minimum_in_Rotated_Sorted_Array_Model result;
            result.nums = { 3, 4, 5, 1, 2 };
            return result;//expect: 1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Find_Minimum_in_Rotated_Sorted_Array_Model GetTestData002(void)
        {
            Find_Minimum_in_Rotated_Sorted_Array_Model result;
            result.nums = { 4, 5, 6, 7, 0, 1, 2 };
            return result;//expect: 0
        };


        /// <summary>
        /// test 3
        /// </summary>   
        Find_Minimum_in_Rotated_Sorted_Array_Model GetTestData003(void)
        {
            Find_Minimum_in_Rotated_Sorted_Array_Model result;
            result.nums = { 11, 13, 15, 17 };
            return result;//expect: 11
        };
#pragma endregion TestData
    };
}