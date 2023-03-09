#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution137
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0137.Single_Number_II.cpp"
    using namespace Solution137;

    int main()
    {
        Solution137::Single_Number_II useClass;
        Solution137::Single_Number_II::Single_Number_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.singleNumber(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �渹2
    /// </summary>
    class Single_Number_II
    {
#pragma region Model
    public:
        class Single_Number_II_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G���ƧǡA3��1�աA�Y�o�Ͳ�0�P��2�����P�ɴN��X�W��
        ///             EX:Array�ȡG 1 1 1 2 2 2 3 4 4 4
        ///                 ���ޭȡG 0 1 2 3 4 5 6 7 8 9
        ///                          - - - 
        ///                          O O O - - - 
        ///                                O O O - - -
        ///                                      X O O  ���ɧY��X3���W�ߪ�
        ///      Runtime :   0 ms Beats 100 %
        /// Memory Usage : 9.5 MB Beats 68.23 %
        /// </summary>
        /// <returns></returns>        
        int singleNumber(vector<int>& nums) {
            //1. 1�����w�����^��
            if (nums.size() == 1)
                return nums[0];
            //2. �Ƨ�
            sort(nums.begin(), nums.end());
            //3. �̭����������w��3�Ӥ@�աA�]���Y��[0]�P[2]�o�ͤ��ۦP�ɡA[0]�w���W�ߪ�
			for (int index = 0; index < nums.size() - 1; index += 3)
            {
				if (nums[index] != nums[index + 2])                
                    return nums[index];                
            }
            //4. �p�G�T�Ӥ@�ճ��i�]���A���ɳ̫�@�����M�O�W�ߪ�
			return nums[nums.size() - 1];
        }

        //�Q���޿�h�Ӹ�
        int singleNumber_solve2(vector<int>& nums) {
            int ones = 0, twos = 0;
            for (int num : nums) {
                ones = (ones ^ num) & ~twos;
                twos = (twos ^ num) & ~ones;
            }
            return ones;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Single_Number_II_Model GetTestData001(void)
        {
            Single_Number_II_Model result;
            result.nums = { 2,2,3,2 };
            return result;//expect:  3
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Single_Number_II_Model GetTestData002(void)
        {
            Single_Number_II_Model result;
            result.nums = { 0,1,0,1,0,1,99 };
            return result;//expect:  99
        };


#pragma endregion TestData
    };
}