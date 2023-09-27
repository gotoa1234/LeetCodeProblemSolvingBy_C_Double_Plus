#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution504
{
#pragma region Paste to execute 
	/*
	#include "Easy\0504.Base_7.cpp"
	using namespace Solution504;

	int main()
	{
		Solution504::Base_7 useClass;
		Solution504::Base_7::Base_7_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.convertToBase7(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.convertToBase7(getTestModel.num);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 基於7
	/// </summary>
	class Base_7
	{
#pragma region Model
	public:
		class Base_7_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 處理負數，不斷 %7 、 /7 最後在反轉字串即為答案
		///       Runtime :   0 ms Beats 100.0 %
		///  Memory Usage :	6.2 MB Beats 17.55 %
		/// </summary>
	    string convertToBase7(int num) {
			string result{};

			//1. 處理負數
			bool isNeative = false;
			if (num < 0)
			{
				isNeative = true;
				num *= -1;
			}

			//2. 不斷取餘數，並且除以7(為0時表示除盡可以跳出)
			while (true)
			{				
				auto bit = num % 7;
				num = num / 7;
			    result.push_back(bit + 48);				
				if (num == 0)
					break;
			}

			//3. 補回負數符號
			if (isNeative)
			{
				result.push_back('-');
			}
			//4. 反轉字串，因為過程都為 push_back()
			reverse(result.begin(), result.end());
			return result;
        }
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Base_7_Model GetTestData001(void)
		{
			Base_7_Model result;
			result.num = 100;
			return result;//expect : 202
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Base_7_Model GetTestData002(void)
		{
			Base_7_Model result;
			result.num = -7;
			return result;//expect : -10
		};
#pragma endregion TestData
	};
}