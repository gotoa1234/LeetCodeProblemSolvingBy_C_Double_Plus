#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution303
{
#pragma region Paste to execute 
	/*
	vector<int> teemp = { -2, 0, 3, -5, 2, -1};
	Solution303::NumArray useClass(teemp);
	auto get = useClass.sumRange(2, 5);
	return 0;
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// nim �C��
	/// </summary>
	class NumArray
	{
#pragma region Model
	public:
#pragma endregion Model

#pragma region Main
	public:
		vector<int> _accumulation{};
		/// <summary>
		///          ��� : �Q�μƾǯS�ʡA����C�@�إi��֥[�_��
		///                  {-2, 0, 3, -5, 2, -1 }  ��Ʀ� => { -2, -2, 1, -4, -2, -3} (��e = ��e + �e��)
		///                  ��D (2,5) �� �i�H���o��ӭȱo�X���G(-3) - (-2) = -1 ����left ���e�@�ӡA�p�Gleft�e�@�ӨS���N�O0�u��right
		///       Runtime : 19 ms Beats 96.33 %
		///  Memory Usage : 17 MB Beats 82.47 %
		/// </summary>
		NumArray(vector<int>& nums) {
			int total = 0;
			for (auto num : nums) {
				total += num;
				_accumulation.push_back(total);
			}		
		}

		int sumRange(int left, int right) {
			if (left == 0)
				return _accumulation[right];
			return _accumulation[right] - _accumulation[left - 1];
		}
#pragma endregion Main

#pragma region TestData
	public:
		///// <summary>
		///// ���ո��1
		///// </summary>        
		//Range_Sum_Query_Immutable GetTestData001(void)
		//{
		//	Range_Sum_Query_Immutable result;
		//	result.n = 4;
		//	return result;//expect : false
		//};

		///// <summary>
		///// ���ո��2
		///// </summary>   
		//Range_Sum_Query_Immutable GetTestData002(void)
		//{
		//	Range_Sum_Query_Immutable result;
		//	result.n = 1;
		//	return result;//expect: true
		//};
#pragma endregion TestData
	};
}