#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution47
{
#pragma region Paste to execute 
	/*
	#include "0047.Permutations_II.cpp"
	using namespace Solution47;
	using namespace std;

	int main()
	{

		Solution47::Permutations_II useClass;
		Solution47::Permutations_II::Permutations_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.permuteUnique(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.permuteUnique(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.permuteUnique(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 排列-2
	/// </summary>
	class Permutations_II
	{
#pragma region Model
	public:
		class Permutations_II_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking：先進行排序，若重複的項目則跳過
		///       Runtime： 15 ms Beats 62.39 %
		/// Memory Usage ：9.7 MB Beats 43.89 %
		/// </summary>	
		vector<vector<int>> _result;
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			FindCompose(0, nums);
			return _result;
		}

		void FindCompose(int moveIndex, vector<int> nums) {

			if (moveIndex >= nums.size())
			{
				_result.push_back(nums);
				return;
			}

			for(int index = moveIndex ; index < nums.size(); index++)
			{
				//增加判斷如果值相同時則跳過，避免重複
				if (index != moveIndex &&
					nums[index] == nums[moveIndex])
				{
					continue;
				}
				swap(nums[index], nums[moveIndex]);
				FindCompose(moveIndex + 1, nums);
			}
		}
#pragma region Solve Bad

		/// <summary>
		///     thinking： 從0046的排列組合方法中-增加使用HashTable 但此方法效能不佳
		///       Runtime：	190 ms Beats 14.69 %
		/// Memory Usage ：19.7 MB Beats 13.34 %
		/// </summary>	
		vector<vector<int>> _result_bad{};
		unordered_map<string, bool> _record_bad{};
		vector<vector<int>> permuteUnique_bad(vector<int>& nums) {
			FindCompose_bad(0, nums);
			return _result_bad;
		}

		void FindCompose_bad(int elementIndex, vector<int>& nums)
		{
			if (elementIndex >= nums.size())
			{
				string temp{ };
				for (int index = 0; index < nums.size(); index++)
				{
					temp.push_back(nums[index] + '0');
					temp.push_back('_');
				}
				if (_record_bad.find(temp) == _record_bad.end())
				{
					_record_bad[temp] = true;
					_result_bad.push_back(nums);
				}
				return;
			}

			for (int index = elementIndex; index < nums.size(); index++)
			{
				swap(nums[elementIndex], nums[index]);
				FindCompose_bad(elementIndex + 1, nums);
				swap(nums[elementIndex], nums[index]);
			}
		}

#pragma endregion


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Permutations_II_Model GetTestData001(void)
		{
			Permutations_II_Model result;
			result.nums = { 1,1,2 };
			return result;//except: [[1,1,2],[1, 2, 1] ,[2, 1, 1]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Permutations_II_Model GetTestData002(void)
		{
			Permutations_II_Model result;
			result.nums = { 1, 2, 3 };
			return result;//except: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
		};

		/// <summary>
		/// test data 1
		/// </summary>        
		Permutations_II_Model GetTestData003(void)
		{
			Permutations_II_Model result;
			result.nums = { 1,2,3 };
			return result;//except: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
		};
#pragma endregion TestData

	};
}
