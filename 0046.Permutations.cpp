#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution46
{
#pragma region Paste to execute 
	/*
	#include "0046.Permutations.cpp"
	using namespace Solution46;
	using namespace std;

	int main()
	{
		
		Solution46::Permutations useClass;
		Solution46::Permutations::Permutations_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.permute(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.permute(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.permute(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �ƦC
	/// </summary>
	class Permutations
	{
#pragma region Model
	public:
		class Permutations_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G �M�������A�N�C�ӭȩ�i�h�A�z�L���j�ϥΥ洫��}�C���覡�D�զX
		///       Runtime�G	0 ms Beats   100 %
		/// Memory Usage �G 8 MB Beats 39.55 %
		/// </summary>	
		vector<vector<int>> _result{ };
		vector<vector<int>> permute(vector<int>& nums) {
			permute_solve1_FindAllCompose(0, nums);
			return _result;
		}

		void permute_solve1_FindAllCompose(int moveIndex, vector<int>& nums)
		{
			if (moveIndex >= nums.size())
			{
				_result.push_back(nums);
			}

			for (int index = moveIndex; index < nums.size(); index += 1)
			{
				swap(nums[moveIndex], nums[index]);
				permute_solve1_FindAllCompose(moveIndex + 1, nums);
				swap(nums[moveIndex], nums[index]);
			}

		}

#pragma region �H�U���ĤG�ӸѪk - �K��z��
		vector<vector<int>> _result2{};
		vector<int> _compose2{};
		/// <summary>
		///     thinking�G �M�������A�N�C�ӭȩ�i�h�A�åB�z�L���j�A�Y�ۦP���ȫh���L
		///       Runtime�G3 ms Beats 86.27 %
		/// Memory Usage �G8 MB Beats 29.34 %
		/// </summary>	
		vector<vector<int>> permute_Solve2(vector<int>& nums) {

			sort(nums.begin(), nums.end());
			for (int index = 0; index < nums.size(); index++)
			{
				_compose2.push_back(nums[index]);
				permute_Solve2_FindAllCompose(index, nums);
				_compose2.pop_back();
			}
			return _result2;
		}

		void permute_Solve2_FindAllCompose(int element, vector<int>& nums)
		{
			if (_compose2.size() == nums.size())
			{
				_result2.push_back(_compose2);
				return;
			}

			for (int index = 0; index < nums.size(); index++)
			{
				if (index == element)
					continue;
				if (find(_compose2.begin(), _compose2.end(), nums[index]) != _compose2.end())
					continue;
				_compose2.push_back(nums[index]);
				permute_Solve2_FindAllCompose(index, nums);
				_compose2.pop_back();
			}
		}

#pragma endregion


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Permutations_Model GetTestData001(void)
		{
			Permutations_Model result;
			result.nums = { 1,2,3 };
			return result;//except: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Permutations_Model GetTestData002(void)
		{
			Permutations_Model result;
			result.nums = { 0,1 };
			return result;//except: [[0,1],[1,0]]
		};

		Permutations_Model GetTestData003(void)
		{
			Permutations_Model result;
			result.nums = { 1 };
			return result;//except: [[1]]		
		};
#pragma endregion TestData

	};
}
