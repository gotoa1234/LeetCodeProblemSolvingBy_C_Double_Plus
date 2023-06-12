#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution162
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0162.Find_Peak_Element.cpp"
    using namespace Solution162;

    int main()
    {
        Solution162::Find_Peak_Element useClass;
        Solution162::Find_Peak_Element::Find_Peak_Element_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.findMin(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findMin(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 找出峰值元素
    /// </summary>
    class Find_Peak_Element
    {
#pragma region Model
    public:
        class Find_Peak_Element_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：找出峰值的索引，利用二分搜尋法只要任一元素大於左右兩側的值，即為峰值
        ///               且相同的值要視為連續峰。
        ///               ※峰值元素的值比左右都高就是
        ///         要求：O(logN) 
        ///      Runtime：  0 ms Beats   100 %
        /// Memory Usage：8.8 MB Beats 97.84 %
        /// </summary>
        /// <returns></returns>
    public:
        int findMin(vector<int>& nums) 
        {
            int left = 0;
            int right = nums.size() - 1;
            int mid = 0;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (nums[mid] < nums[mid + 1])
                    left = mid + 1;
                else 
                    right = mid;
            }
            return right;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Find_Peak_Element_Model GetTestData001(void)
        {
            Find_Peak_Element_Model result;
            result.nums = { 3,3,3,3,2,2,2,2,7,4,4,2};
            return result;//expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Find_Peak_Element_Model GetTestData002(void)
        {
            Find_Peak_Element_Model result;
            result.nums = { 1,2,1,3,5,6,4 };
            return result;//expect: 5   
        };

#pragma endregion TestData
    };
}