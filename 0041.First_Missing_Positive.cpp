#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution41
{
#pragma region Paste to execute 
	/*
	#include "0041.First_Missing_Positive.cpp"
	using namespace Solution41;
	using namespace std;

	int main()
	{
		int result = 0;
		Solution41::First_Missing_Positive useClass;
		Solution41::First_Missing_Positive::First_Missing_Positive_Model getTestModel = useClass.GetTestData001();
		result = useClass.firstMissingPositive(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		result = useClass.firstMissingPositive(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		result = useClass.firstMissingPositive(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 求第一個缺少的正數 
	/// ※正數：大於0的正整數
	/// </summary>
	class First_Missing_Positive
	{
#pragma region Model
	public:
		class First_Missing_Positive_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 面試專用題目，可以從討論過程中演化出最佳演算法
		///      (不及格)  1.              泡沫搜尋 - Time:O(n^2)   Space:O(1)
		///      (不及格)  2.              排序搜尋 - Time:O(nlogn) Space:O(1)
		///                3.            HashTable - Time:O(n)     Space:O(n)
		///                4. 散列(不使用HashTable) - Time:O(n)     Space:O(1)
		///      (最優)    5.        散列 + 切割區分 - Time:O(n)     Space:O(1)
		///       Runtime：
		/// Memory Usage ：
		/// </summary>
		
		/// <summary>
		///      thinking：HashTable
		///       Runtime：	 146 ms Beats 27.59 %
		/// Memory Usage ： 46.7 MB Beats 16.40 %
		/// </summary>
		int firstMissingPositive(vector<int>& nums) {
			unordered_map<int, bool> hashMap;
			int maxValue = 0;
			for (int index = 0; index < nums.size(); index++)
			{
				maxValue = max(maxValue, nums[index]);
				hashMap[nums[index]] = true;
			}

			for (int index = 1; index < nums.size(); index++)
			{
				if (hashMap.find(index) == hashMap.end())
				{
					return index;
				}
			}
			return maxValue == nums.size() ? nums.size() + 1 : nums.size();
		}

		/// <summary>
		///      thinking：散列(不使用HashTable)
	    ///       Runtime：   78 ms Beats 74.39 %
		/// Memory Usage ： 31.2 MB Beats 98.80 %
		/// </summary>
		/// <returns></returns>
		int firstMissingPositive_in_place_hashing(vector<int>& nums) {
			int maxLength = nums.size();
			//1. 先遍歷O(n) 交換每個數值到對應的index上
			for (int index = 0; index < maxLength; index++) 
			{
				while (nums[index] >= 0 && //排除負數
					   nums[index] < maxLength && //排除大於等於陣列長度的整數
					   nums[index] != index && //排除自己與當前索引數字值相同的
					   nums[index] != nums[nums[index]])//要交換的對象不可與當前數字相同
				{
					swap(nums[index], nums[nums[index]]);
				}
			}
			/*
			{ 3,4,-1,1 };
			當 i = 0 那麼 nums[0] 與 nums[ nums[0] ] 第一次交換成
			{ 1,4,-1,3};
			當 i = 0 那麼 nums[0] 與 nums[ nums[0] ] 第二次交換成
			{ 4,1,-1,3};
			當 i = 0 那麼 nums[0] 與 nums[ nums[0] ] 第三次不可交換
			因為nums[0] 已經是4了大於等於長度，所以不交換

			當 i = 1 那麼 nums[1] 與 nums[ nums[1] ] 值相同不可交換
			當 i = 2 那麼 nums[2] 沒有大於等於0 為負數故跳過
			當 i = 3 那麼 nums[3] 與 nums[ nums[3] ] 值相同不可交換
			*/

			//2. Nums已交換完畢，每個值應都在index = value 上，若無表示該值為缺少的正數
			for (int index = 0; index < maxLength; index++) 
			{
				if (nums[index] != index && index != 0) 
					return index;
			}
			//3. 排除全填滿的狀況
			if (nums[0] == maxLength)//EX: [1] Expect: 2
			{
				return maxLength + 1;
			}
			return maxLength;//EX: [0,1,2] Expect: 3
		}

		/// <summary>
		///      thinking：  散列 + 切割區分 (速度通常比純散列更快)
		///       Runtime：  62 ms Beats 82.1 %
		/// Memory Usage ：31.2 MB Beats 94.92 %
		/// </summary>
		/// <returns></returns>
		int firstMissingPositive_in_place_hashing_AND_Partition(vector<int>& nums) {
			int maxLength = nums.size();
			for (int index = 0; index < maxLength; index++) {
				if (nums[index] <= 0) {
					nums[index] = maxLength + 1;
				}
			}
			for (int index = 0; index < maxLength; index++) {
				if (abs(nums[index]) <= maxLength) {
					nums[abs(nums[index]) - 1] = -abs(nums[abs(nums[index]) - 1]);
				}
			}
			for (int index = 0; index < maxLength; index++) {
				if (nums[index] > 0) {
					return index + 1;
				}
			}
			return maxLength + 1;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		First_Missing_Positive_Model GetTestData001(void)
		{
			First_Missing_Positive_Model result;	


			result.nums = { 1,2,0};
			return result;//except: 3
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		First_Missing_Positive_Model GetTestData002(void)
		{
			First_Missing_Positive_Model result;
			result.nums = { 3,4,-1,1 };
			
			return result;//except: 2
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		First_Missing_Positive_Model GetTestData003(void)
		{
			First_Missing_Positive_Model result;
			result.nums = { 7,8,9,11,12 };
			return result;//except: 1
		};
#pragma endregion TestData

	};
}