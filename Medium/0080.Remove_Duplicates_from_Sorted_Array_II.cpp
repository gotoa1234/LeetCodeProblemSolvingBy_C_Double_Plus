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
    /// �l��
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
        ///         ��� �G�i��nums�M���A�åB�Q�Τ@���ܼƬ����ثe������
        ///                �M������e�Ȫ��j��e��Ӧ�m���ȡA��ܥi�H�N��e���ȩ�J
        ///                (�Y�w��F��ӴN���|�O�j��)
        ///      Runtime :  0 ms Beats   100 %
        /// Memory Usage : 11 MB Beats 43.15 %
        /// </summary>
        /// <returns></returns>
        int removeDuplicates(vector<int>& nums) {
            int findIndex = 0;
            //1. �M��
            for (int index = 0; index < nums.size(); index++)
            {
                //2. �C��[0],[1] ���i�H���}�C�� [0],[1]
                //   ���۴N�ӳW�h-> ��e�Ȫ��j��e��Ӧ�m���ȡA��ܥi�H�N��e���ȩ�J
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