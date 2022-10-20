#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution39
{
#pragma region Paste to execute 
	/*
	#include "0039.Combination_Sum.cpp"
	using namespace Solution39;
	using namespace std;

	int main()
	{
		vector<vector<int>> result = {};
		Solution39::Combination_Sum useClass;
		Solution39::Combination_Sum::Combination_Sum_Model getTestModel = useClass.GetTestData001();
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData002();
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

		getTestModel = useClass.GetTestData003();
		result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �զX�`�M
	/// </summary>
	class Combination_Sum
	{
#pragma region Model
	public:
		class Combination_Sum_Model
		{
		public:
			vector<int> candidates;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G �Q�λ��jDFS�A���ƧǥѤp��j�A�M��Ѳ�Vector<int>��0�Ӷ}�l�a�|�k��̫�A�զ��Ҧ���
		///       Runtime�G
		/// Memory Usage �G
		/// </summary>
		vector<vector<int>> _result = {};
		vector<int> _combinations = {};
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

			//1. �ƧǸ�ƥѤp��j
			sort(candidates.begin(), candidates.end());
			//2. �i�滼�j
			Sum(candidates, target, 0);

			return _result;
		}

		void Sum(vector<int>& candidates, int target, int moveIndex)
		{
			//3. �C�����j target ���|�Q��h�@�ӭȡA��target��0�ɡA��ܲզ��� _combinations�N�O����
			if (target == 0)
			{
				_result.push_back(_combinations);
				return;
			}

			//4. index ��0��̫�A�C����ַ�e�ȡA�Y���t�ƪ�ܷ�e�Ȥ��X�A�ݭn
			while (moveIndex < candidates.size() && 
				   target - candidates[moveIndex] >= 0
				)
			{
				//5. �C���N�@�ӭȩ�J
				_combinations.push_back(candidates[moveIndex]);
				Sum(candidates, target - candidates[moveIndex], moveIndex);
				//6. ����Ϊ̨S���ɳ��|���U�ӭȫe�i(�ǳƷ�U�ӻ��j����e��)
				moveIndex++;
				_combinations.pop_back();
			}
			return;
		}


	

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Combination_Sum_Model GetTestData001(void)
		{
			Combination_Sum_Model result;
			result.candidates = { 2, 3, 6, 7 };
			result.target = 7;
			return result;//except: [[2,2,3],[7]]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Combination_Sum_Model GetTestData002(void)
		{
			Combination_Sum_Model result;
			result.candidates = {2,3,5};
			result.target = 8;
			return result;//except: [[2,2,2,2],[2,3,3],[3,5]]
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Combination_Sum_Model GetTestData003(void)
		{
			Combination_Sum_Model result;
			result.candidates = { 2 };
			result.target = 1;
			return result;//except: []
		};
#pragma endregion TestData

	};
}