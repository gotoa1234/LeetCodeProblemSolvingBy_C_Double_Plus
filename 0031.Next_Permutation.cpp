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
		/// <summary>
		///          思路：
		///                
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		void nextPermutation(vector<int>& nums) {
			int numsCount = nums.size(), k, l;
			//找出是否遞增 or 遞減
			for (k = numsCount - 2; k >= 0; k--) 
			{
				if (nums[k] < nums[k + 1]) {
					break;
				}
			}

			//
			if (k < 0) 
			{
				reverse(nums.begin(), nums.end());
			}
			else 
			{
				for (l = numsCount - 1; l > k; l--) 
				{
					if (nums[l] > nums[k]) {
						break;
					}
				}
				swap(nums[k], nums[l]);
				reverse(nums.begin() + k + 1, nums.end());
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
			result.nums = { 1,2,3 };
			return result;//except: {1,3,2}
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Next_Permutation_Model GetTestData002(void)
		{
			Next_Permutation_Model result;
			result.nums = { 3,2,1 };
			return result;//except: {1,2,3}
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Next_Permutation_Model GetTestData003(void)
		{
			Next_Permutation_Model result;
			result.nums = { 1,1,5 };
			return result;//except: {1,5,1}
		};
#pragma endregion TestData
	};
}