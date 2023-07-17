#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution219
{
#pragma region Paste to execute 
	/*
	#include "0219.Contains_Duplicate_II.cpp"
	using namespace Solution219;
	using namespace std;

	Solution219::Contains_Duplicate_II useClass;
	Solution219::Contains_Duplicate_II::Contains_Duplicate_II_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.containsNearbyDuplicate(getTestModel.nums, getTestModel.k);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 包含重複項 2
	/// </summary>
	class Contains_Duplicate_II
	{
#pragma region Model
	public:
		class Contains_Duplicate_II_Model
		{
		public:
			vector<int> nums;
			int k;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :利用Hashtable紀錄該數值最後的索引位置，如果有就判斷是否符合題目需求的條件
		///          題目 :nums[i] == nums[j] and abs(i - j) <= k.  時回傳True
		///       Runtime : 179 ms Beats 93.00 %
		///  Memory Usage :77.3 MB Beats 52.51 %
		/// </summary>
		bool containsNearbyDuplicate(vector<int>& nums, int k) {						
			unordered_map<int, int> _hashTable{};
			for (int index = 0; index < nums.size(); index++)
			{
				if (_hashTable.find(nums[index]) != _hashTable.end())
				{
					if (index - _hashTable[nums[index]] <= k)
						return true;
				}
				_hashTable[nums[index]] = index;
			}
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Contains_Duplicate_II_Model GetTestData001(void)
		{
			Contains_Duplicate_II_Model result;
			result.nums = { 1,2,3,1 };
			result.k = 3;
			return result;// expect : true
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Contains_Duplicate_II_Model GetTestData002(void)
		{
			Contains_Duplicate_II_Model result;
			result.nums = { 1,0,1,1 };
			result.k = 1;
			return result;// expect : true
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Contains_Duplicate_II_Model GetTestData003(void)
		{
			Contains_Duplicate_II_Model result;
			result.nums = { 1,2,3,1,2,3 };
			result.k = 2;
			return result;// expect : false
		};
#pragma endregion TestData
	};
}