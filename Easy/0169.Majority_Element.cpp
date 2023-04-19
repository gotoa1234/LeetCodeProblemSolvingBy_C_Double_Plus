#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution169
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy/0169.Majority_Element.cpp"
    using namespace Solution169;

    int main()
    {
        Solution169::Majority_Element useClass;
        Solution169::Majority_Element::Majority_Element_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.majorityElement(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.majorityElement(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �̦h������
    /// </summary>
    class Majority_Element
    {
#pragma region Model
    public:
        class Majority_Element_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G���D�إu�|����ӭȡA�G�i�H��1���ܼ�count��+ - �p��A�_�l��+ �������ȡA�J��t�@�Ӥ����|�i��-
        ///      Runtime :   18 ms Beats 77.22 %
        /// Memory Usage : 19.5 MB Beats 80.70 %
        /// </summary>
        /// <returns></returns>        
        int majorityElement(vector<int>& nums) {
            int count = 1;
            int candidate = nums[0];

            for (int index = 0; index < nums.size(); index++)
            {
                if (count == 0)
                    candidate = nums[index];
                
                if (nums[index] == candidate)
                    count++;
                else
                    count--;
            }
            return candidate;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Majority_Element_Model GetTestData001(void)
        {
            Majority_Element_Model result;
            result.nums = { 3, 2, 3 };
            return result;//expect:  3
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Majority_Element_Model GetTestData002(void)
        {
            Majority_Element_Model result;
            result.nums = { 2,2,1,1,1,2,2 };
            return result;//expect:  2         
        };


#pragma endregion TestData
    };
}