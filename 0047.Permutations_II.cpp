#include <iostream>
#include <unordered_map>
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
	/// ±Æ¦C-2
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
		///     thinking¡G 
		///                
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>	
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			return {};
		}

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
#pragma endregion TestData

	};
}
