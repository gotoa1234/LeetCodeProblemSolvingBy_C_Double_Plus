#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

namespace Solution258
{
#pragma region Paste to execute 
	/*
	#include "Easy\0258.Add_Digits.cpp"
	using namespace Solution258;
	using namespace std;
	int main()
	{
		Solution258::Add_Digits useClass;
		Solution258::Add_Digits::Add_Digits_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.addDigits(getTestModel.num);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 
	/// </summary>
	class Add_Digits
	{
#pragma region Model
	public:
		class Add_Digits_Model
		{
		public:
			int num;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :利用一個變數紀錄當前加總額，如果大於10表示還需要對每個位數做加總
		///       Runtime : 0 ms Beats   100 %
		///  Memory Usage : 6 MB Beats 56.13 %
		/// </summary>
		int addDigits(int num) {
			int result = num;
			while ((result / 10) > 0)
			{
				num = result;
				result = 0;
				while (num > 0)
				{
					if (num / 10 > 0)
					{
						result += num / 10;
						num = num % 10;
					}
					else
					{
						result += num;
						num = 0;
					}
				}
			}
			return result;
		}

		/// <summary>
		/// 數學解最完美的解答，無論怎麼計算，最後就是9的餘數
		/// </summary>
		/// <param name="num"></param>
		/// <returns></returns>
		int addDigits_Fast(int num)
		{
			if (num == 0) return 0;
			if (num % 9 == 0) return 9;
			return num % 9;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Add_Digits_Model GetTestData001(void)
		{
			Add_Digits_Model result;// 3 + 8 =11  1+1 =2
			result.num = 38;
			return result;//expect : 2
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Add_Digits_Model GetTestData002(void)
		{
			Add_Digits_Model result;
			result.num = 0;			
			return result;//expect: 0
		};

#pragma endregion TestData
	};
}