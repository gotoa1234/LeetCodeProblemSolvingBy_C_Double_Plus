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
    /// 單號2
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
        ///         思路 ：先排序，3個1組，若發生第0與第2筆不同時就找出獨立
        ///             EX:Array值： 1 1 1 2 2 2 3 4 4 4
        ///                 索引值： 0 1 2 3 4 5 6 7 8 9
        ///                          - - - 
        ///                          O O O - - - 
        ///                                O O O - - -
        ///                                      X O O  此時即找出3為獨立的
        ///      Runtime :   0 ms Beats 100 %
        /// Memory Usage : 9.5 MB Beats 68.23 %
        /// </summary>
        /// <returns></returns>        
        int singleNumber(vector<int>& nums) {
            //1. 1筆必定直接回傳
            if (nums.size() == 1)
                return nums[0];
            //2. 排序
            sort(nums.begin(), nums.end());
            //3. 裡面的元素必定為3個一組，因此若第[0]與[2]發生不相同時，[0]定為獨立的
			for (int index = 0; index < nums.size() - 1; index += 3)
            {
				if (nums[index] != nums[index + 2])                
                    return nums[index];                
            }
            //4. 如果三個一組都可跑完，此時最後一筆必然是獨立的
			return nums[nums.size() - 1];
        }

        //利用邏輯閘來解
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