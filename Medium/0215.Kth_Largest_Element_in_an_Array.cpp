#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution215
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0215.Kth_Largest_Element_in_an_Array.cpp"
    using namespace Solution215;

    int main()
    {
        Solution215::Kth_Largest_Element_in_an_Array useClass;
        Solution215::Kth_Largest_Element_in_an_Array::Kth_Largest_Element_in_an_Array_Model getTestModel = useClass.GetTestData2();
        auto result1 = useClass.findKthLargest(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findKthLargest(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 數組中的第 K 大元素
    /// </summary>
    class Kth_Largest_Element_in_an_Array
    {
#pragma region Model
    public:
        class Kth_Largest_Element_in_an_Array_Model
        {
        public:
            vector<int> nums;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 
        ///      Runtime : 
        /// Memory Usage : 
        int findKthLargest(vector<int>& nums, int k) {
            return {};
        }

    private:
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Kth_Largest_Element_in_an_Array_Model GetTestData001(void)
        {
            Kth_Largest_Element_in_an_Array_Model result;
            result.nums = { 1,2,3,1 };
            result.k = 3;
            return result;//Expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Kth_Largest_Element_in_an_Array_Model GetTestData002(void)
        {
            Kth_Largest_Element_in_an_Array_Model result;
            result.nums = { 2, 3, 2 };
            result.k = 3;
            return result;
            //Expect:3
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Kth_Largest_Element_in_an_Array_Model GetTestData003(void)
        {
            Kth_Largest_Element_in_an_Array_Model result;
            result.nums = { 1, 2, 3 };
            result.k = 3;
            return result;
            //Expect:3
        };
#pragma endregion TestData
    };
}