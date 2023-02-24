#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

namespace Solution128
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0128.Longest_Consecutive_Sequence.cpp"
    using namespace Solution128;

    int main()
    {
        Solution128::Longest_Consecutive_Sequence useClass;
        Solution128::Longest_Consecutive_Sequence::Longest_Consecutive_Sequence_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.longestConsecutive(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.longestConsecutive(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �̪��s��ǦC
    /// </summary>
    class Longest_Consecutive_Sequence
    {
#pragma region Model
    public:
        class Longest_Consecutive_Sequence_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q������������J�}�C�A�M��M����������A�P�_�����Ӥ����O�_���s��ȡA�Y�O�h�֭p
        ///                ��X�̤j�֭p��
        ///      Runtime :  129 ms Beats 80.9 %
        /// Memory Usage : 45.7 MB Beats 77.80 %
        /// </summary>
        /// <returns></returns>
        int longestConsecutive(vector<int>& nums) {
            //1. �ӶOO(n)�A�Nnums��iHashSet�� (�s��ɤ����Ƥ���)�A�s�񶶧ǬO���T�w��(����Hash�ȨM�w)
            unordered_set<int> hashSetMap(nums.begin(), nums.end());
            int result = 0;
            int currentValue = 0;
            int currentLength = 0;
            //2. �M��unordered_set��
            for (int item : hashSetMap) 
            {
                //3.�C��hashSetMap.Count() �ӶOO(1)
                if (hashSetMap.count(item - 1) == 0) 
                {
                    currentValue = item;
                    currentLength = 1;
                    while (hashSetMap.count(currentValue + 1) != 0)
                    {
                        currentValue++;
                        currentLength++;
                    }
                    //4. �o�{������s��ʤ����h��s
                    result = max(result, currentLength);
                }
            }
            return result;
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Longest_Consecutive_Sequence_Model GetTestData001(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 100, 200, 300, 400, 1,2,3,4, 50 };//{ 100, 4, 200, 1, 3, 2 };
            return result;//expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Longest_Consecutive_Sequence_Model GetTestData002(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 0,3,7,2,5,8,4,6,0,1 };
            return result;//expect: 9
        };

#pragma endregion TestData
    };
}