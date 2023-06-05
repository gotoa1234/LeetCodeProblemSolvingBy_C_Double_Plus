#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

namespace Solution12
{
#pragma region Paste to execute 
	/*
	#include "Medium\0012.Integer_to_Roman.cpp"
	using namespace Solution12;
	using namespace std;

	int main()
	{
		Solution12::Integer_to_Roman useClass;
		Solution12::Integer_to_Roman::Integer_to_Roman_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.intToRoman(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.intToRoman(getTestModel.num);

		getTestModel = useClass.GetTestData003();
		result = useClass.intToRoman(getTestModel.num);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �Ʀr��ù���Ʀr
	/// </summary>
	class Integer_to_Roman
	{
#pragma region Model
	public:
		class Integer_to_Roman_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�إߤ@�ӥѤj�Ӥp��ù��������A�v�@�N��J���ƭȴ�h��0�ɧ�������ഫ
		///       Runtime:   4 ms Beats 87.49 %
		/// Memory Usage : 9.5 MB Beats 18.9 %
		/// </summary>
		string intToRoman(int num) {
			
			//1. ��Xù���Ʀr���i�ඵ�ءA�����Ѥj��p 
			const vector<pair<int, string>> valueSymbols {
				{1000, "M"} , {900, "CM"} , {500, "D"} , {400, "CD"} , {100, "C"} , {90, "XC"} ,
				{50, "L"} , {40, "XL"} , {10, "X"} , {9, "IX"} , {5, "V"} , {4, "IV"} , {1, "I"} 
			};
			string result;

			//2. �Nù���Ÿ��Ѥj�Ӥp�v�@�M��
			for (const auto& [value, symbol] : valueSymbols) 
			{
				//3. �M�����L�{num�|���_��h������ù���Ʀr���ȡA�Ȩ�num = 0 ;
				if (num == 0)
					break;
				while (num >= value) 
				{
					num -= value;
					result += symbol;
				}
			}
			//4. �����ഫ����
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Integer_to_Roman_Model GetTestData001(void)
		{
			Integer_to_Roman_Model result;
			result.num = 3;
			return result;//except: III
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Integer_to_Roman_Model GetTestData002(void)
		{
			Integer_to_Roman_Model result;
			result.num = 58;
			return result;//expect: LVIII
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Integer_to_Roman_Model GetTestData003(void)
		{
			Integer_to_Roman_Model result;
			result.num = 1994;
			return result;//expect: MCMXCIV

		};
#pragma endregion TestData

	};
}