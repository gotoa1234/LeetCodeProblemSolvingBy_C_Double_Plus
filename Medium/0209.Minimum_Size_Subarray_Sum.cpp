#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution209
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Medium\0209.Minimum_Size_Subarray_Sum.cpp"
    using namespace Solution209;

    int main()
    {
        Solution209::Minimum_Size_Subarray_Sum useClass;
        Solution209::Minimum_Size_Subarray_Sum::Minimum_Size_Subarray_Sum_Model getTestModel = useClass.GetTestData2();
        auto result = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.minSubArrayLen(getTestModel.target, getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̤p�ƶq���l�Ʋ��`�M
    /// </summary>
    class Minimum_Size_Subarray_Sum
    {
#pragma region Model
    public:
        class Minimum_Size_Subarray_Sum_Model
        {
        public:
            int target;
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         ��� : ���Ѫk��O(n) ���Ѫk�AsubArray�ݬ��s��ʡA�]���Ψ�ӯ��ޡA�Ĥ@�ӯ���(�k����)���_�e�i�A�����j�󵥩�ؼЮ�
        ///                �����ޫe�i�A�øѥh���ޭȡA�p��X��e���סC����M���쩳
        ///     �D�حn�D : ���XO(n) �P O(nlog) ���Ѫk
        ///      Runtime:     31ms Beats 97.74 %
        /// Memory Usage : 28.29mb Beats 23.78 %
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int leftIndex = 0;
            int rightIndex = 0;
            int total = 0;
            int result = INT_MAX;
            while (rightIndex < nums.size())
            {
                total += nums[rightIndex];
                while (total >= target)
                {
                    total -= nums[leftIndex];
                    result = min(rightIndex - leftIndex + 1, result);
                    leftIndex++;
                }
                rightIndex++;
            }
            return result == INT_MAX ? 0 : result;
        }


#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Size_Subarray_Sum_Model GetTestData001(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 213;
            result.nums = {12,28,83,4,25,26,25,2,25,25,25,12};
            return result;
            //Expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Size_Subarray_Sum_Model GetTestData002(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 4;
            result.nums = { 1, 4, 4 };
            return result;
            //Expect: 1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Minimum_Size_Subarray_Sum_Model GetTestData003(void)
        {
            Minimum_Size_Subarray_Sum_Model result;
            result.target = 11;
            result.nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
            return result;
            //Expect:0
        };
#pragma endregion TestData
    };
}