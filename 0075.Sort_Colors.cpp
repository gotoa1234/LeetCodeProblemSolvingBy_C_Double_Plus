#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution75
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0075.Sort_Colors.cpp"
    using namespace Solution75;

    int main()
    {
        Solution75::Sort_Colors useClass;
        Solution75::Sort_Colors::Sort_Colors_Model getTestModel = useClass.GetTestData001();
        useClass.sortColors(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        useClass.sortColors(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 排序顏色
    /// </summary>
    class Sort_Colors
    {
#pragma region Model
    public:
        class Sort_Colors_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用只有三個值的特性，0放在陣列最左邊，2放在最右邊，1不要動
        ///                左邊起始索引0 ，每當放一個值時遞增此值
        ///                右邊起始索引nums.size()-1 ，每當放一個值時遞減此值
        ///                當遍歷時遇到右邊索引表示到終點了(右邊索引是2，表示右邊接下來都是2可以跳過)
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 8.2 MB Beats 91.39 %
        /// </summary>
        /// <returns></returns>
        void sortColors(vector<int>& nums) 
        {
            int left = 0, right = (int)nums.size() - 1;
            //1.遍歷
            for (int index = 0; index <= right; index++) 
            {
                //2-1. 處理0的狀況
                if (nums[index] == 0) 
                {
                    swap(nums[index], nums[left]);
                    left++;//左邊使用+1
                }
                else if (nums[index] == 2) //2-2. 處理2的狀況
                {
                    swap(nums[index], nums[right]);
                    right--;//右邊使用-1
                    index--;//這個index-- => 因為與最右邊交換值，該位置的值還要再檢查一次
                }
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sort_Colors_Model GetTestData001(void)
        {
            Sort_Colors_Model result;
            result.nums = { 2, 0, 2, 1, 1, 0 };
            return result;//expect: [0, 0, 1, 1, 2, 2]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sort_Colors_Model GetTestData002(void)
        {
            Sort_Colors_Model result;
            result.nums = {1, 2, 0 };
            return result;//expect: [0, 1, 2]
        };
#pragma endregion TestData
    };
}