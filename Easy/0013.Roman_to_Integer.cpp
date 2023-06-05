#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

namespace Solution13
{
#pragma region Paste to execute 
	/*
	#include "Easy\0013.Roman_to_Integer.cpp"
	using namespace Solution13;
	using namespace std;

	int main()
	{
		Solution13::Roman_to_Integer useClass;
		Solution13::Roman_to_Integer::Roman_to_Integer_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.romanToInt(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		result = useClass.romanToInt(getTestModel.num);

		getTestModel = useClass.GetTestData003();
		result = useClass.romanToInt(getTestModel.num);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary> 
	/// ù���Ʀr��Ʀr
	/// </summary>
	class Roman_to_Integer
	{
#pragma region Model
	public:
		class Roman_to_Integer_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�Q���D�ص���1 ~ 1000��ù���Ʀr���ഫ�A���e���Ȥp�󵥩�e�@�ӭȮɬ��[�k�B��A�_�h����k�B��
		///       Runtime:   4 ms Beats 90.46 %
		/// Memory Usage : 6.1 MB Beats 69.33 %
		/// </summary>
		int romanToInt(string s) {
			
			int result = returnValue(s[0]);
			int lastValue = result;
			int currentValue = 0;

			for (int index = 1; index < s.size(); index++)
			{
				currentValue = returnValue(s[index]);
				if (currentValue <= lastValue)
					result += currentValue;
				else
					result += currentValue - 2 * lastValue;
				lastValue = currentValue;
			}
			return result;
		}

		int returnValue(char item)
		{
			if (item == 'I')
				return 1;
			else if (item == 'V')
				return 5;
			else if (item == 'X')
				return 10;
			else if (item == 'L')
				return 50;
			else if (item == 'C')
				return 100;
			else if (item == 'D')
				return 500;
			else
				return 1000;
		};
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Roman_to_Integer_Model GetTestData001(void)
		{
			Roman_to_Integer_Model result;
			result.s = "III";
			return result;//except: 3
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Roman_to_Integer_Model GetTestData002(void)
		{
			Roman_to_Integer_Model result;
			result.s = "LVIII";
			return result;//expect: 58
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Roman_to_Integer_Model GetTestData003(void)
		{
			Roman_to_Integer_Model result;
			result.s = "MCMXCIV";
			return result;//expect: 1994

		};
#pragma endregion TestData

	};
}