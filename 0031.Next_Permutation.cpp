#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution31
{
#pragma region Paste to execute 
	/*
	#include "0031.Next_Permutation.cpp"
	using namespace Solution31;
	using namespace std;

	int main()
	{
		Solution31::Next_Permutation useClass;
		Solution31::Next_Permutation::Next_Permutation_Model getTestModel = useClass.GetTestData001();
	    useClass.nextPermutation(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		useClass.nextPermutation(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		useClass.nextPermutation(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 下一個預期的排列組合
	/// </summary>
	class Next_Permutation
	{
#pragma region Model
	public:
		class Next_Permutation_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:


		/* 可利用for迴圈 + next_permutation(nums.begin(), nums.end()); 找出以下順序的排列組合
            1 , 2 , 3 , 4
            1 , 2 , 4 , 3
            1 , 3 , 2 , 4
            1 , 3 , 4 , 2
            1 , 4 , 2 , 3
            1 , 4 , 3 , 2
            2 , 1 , 3 , 4
            2 , 1 , 4 , 3
            2 , 3 , 1 , 4
            2 , 3 , 4 , 1
            2 , 4 , 1 , 3
            2 , 4 , 3 , 1
            3 , 1 , 2 , 4
            3 , 1 , 4 , 2
            3 , 2 , 1 , 4
            3 , 2 , 4 , 1
            3 , 4 , 1 , 2
            3 , 4 , 2 , 1
            4 , 1 , 2 , 3
            4 , 1 , 3 , 2
            4 , 2 , 1 , 3
            4 , 2 , 3 , 1
            4 , 3 , 1 , 2
            4 , 3 , 2 , 1
        */
		/// <summary>
		///          思路：題意為排列組合，找出下一個組合的項目，以上面的1,2,3,4 為輸入，輸出就要1,2,4,3
		///                可以利用該排列的邏輯
		///                Condition 1： 5, 4, 3, 2, 1 必定 1, 2, 3, 4, 5
		///                              從後往前推 - 找出小於後一個數值的索引
		///                              從後往前推 - 找出大於nums[anchorIndex] 數值的索引
		///                Condition 2： 永遠將 anchorIndex 與 replaceIndex 的數值對換
		///                Condition 3： 永遠將 anchorIndex 之後的數值做倒序排序
		///      Runtime :    0 ms Beats   100 %
		/// Memory Usage :   12 MB Beats 74.75 % 
		/// </summary>
		void nextPermutation(vector<int>& nums) {
			int numsCount = nums.size();
			int anchorIndex;//從後往前推 - 找出小於後一個數值的索引
			int replaceIndex;//從後往前推 - 找出大於nums[anchorIndex] 數值的索引
			//找出是否遞增 or 遞減
			for (anchorIndex = numsCount - 2; anchorIndex >= 0; anchorIndex--)
			{
				if (nums[anchorIndex] < nums[anchorIndex + 1]) {
					break;
				}
			}

			//1. 特殊條件 EX: 5, 4, 3, 2, 1 必定 1, 2, 3, 4, 5
			if (anchorIndex < 0)
				reverse(nums.begin(), nums.end());
			else
			{
				//2-1 找出大於nums[anchorIndex] 數值的索引
				for (replaceIndex = numsCount - 1; replaceIndex > anchorIndex; replaceIndex--)
				{
					if (nums[replaceIndex] > nums[anchorIndex])
						break;
				}
				//2-2 永遠將 anchorIndex 與 replaceIndex 的數值對換
				swap(nums[anchorIndex], nums[replaceIndex]);
				//2-3 永遠將 anchorIndex 之後的數值做倒序排序
				reverse(nums.begin() + anchorIndex + 1, nums.end());
			}
		}

		/// <summary>
		/// ※其實就是實現以下的語法
		/// </summary>
		/// <param name="nums"></param>
		void nextPermutation_cPlusPlusFunction(vector<int>& nums) {
			next_permutation(nums.begin(), nums.end());
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Next_Permutation_Model GetTestData001(void)
		{
			Next_Permutation_Model result;
			result.nums = { 3 , 4 , 1 , 2 };
			return result;//except: {3 , 4 , 2 , 1}
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Next_Permutation_Model GetTestData002(void)
		{
			Next_Permutation_Model result;
			result.nums = { 3 , 4 , 2 , 1 };
			return result;//except: {4 , 1 , 2 , 3}
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Next_Permutation_Model GetTestData003(void)
		{
			Next_Permutation_Model result;
			result.nums = { 4 , 3 , 2 , 1 };
			return result;//except: {1 , 2 , 3 , 4}
		};
#pragma endregion TestData
	};
}