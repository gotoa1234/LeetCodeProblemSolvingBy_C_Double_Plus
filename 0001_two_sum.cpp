#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution1
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0001_two_sum.cpp"
    using namespace Solution1;
    int main()
    {
        Solution1::Two_Sum useClass;
        Solution1::Two_Sum::Two_Sum_Model getTestModel = useClass.GetTestData001();
        vector<int> result = useClass.twoSum(getTestModel.nums, getTestModel.target);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �}�C��Ƭۥ[�A�D�}�C��2�ӼƭȬۥ[���ؼЭȱo��2�ӼƭȪ�����
    /// <para>����G��hashTable �����A�C���첾�ɤ��hash Table���O�_���۲ŦX����</para>
    /// </summary>
    class Two_Sum
    {
#pragma region Model
    public:
        class Two_Sum_Model
        {
        public:
            vector<int> nums;
            int target = 0;
        };
#pragma endregion Model

#pragma region Main
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> result;
            unordered_map<int, int> hashMap;
            for (int index = 0; index < nums.size(); index++)
            {
                if (hashMap.find(target - nums[index]) != hashMap.end())
                {
                    result.push_back(hashMap[target - nums[index]]);
                    result.push_back(index);
                    return result;
                }
                hashMap[nums[index]] = index;
            }
        };
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Two_Sum_Model GetTestData001(void)
        {
            Two_Sum_Model result;
            result.nums.push_back(2);
            result.nums.push_back(7);
            result.nums.push_back(11);
            result.nums.push_back(15);

            result.target = 9;
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Two_Sum_Model GetTestData002(void)
        {
            Two_Sum_Model result;
            result.nums.push_back(3);
            result.nums.push_back(2);
            result.nums.push_back(4);

            result.target = 6;
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary> 
        Two_Sum_Model GetTestData003(void)
        {
            Two_Sum_Model result;
            result.nums.push_back(3);
            result.nums.push_back(3);

            result.target = 6;
            return result;
        };
#pragma endregion TestData
    };
}