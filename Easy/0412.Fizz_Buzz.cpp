#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution412
{
#pragma region Paste to execute 
	/*
	#include "Easy\0412.Fizz_Buzz.cpp"
	using namespace Solution412;

	int main()
	{

		Solution412::Fizz_Buzz useClass;
		Solution412::Fizz_Buzz::Fizz_Buzz_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);

		getTestModel = useClass.GetTestData002();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);

		getTestModel = useClass.GetTestData003();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// FizzBuzz
	/// </summary>
	class Fizz_Buzz
	{
#pragma region Model
	public:
		class Fizz_Buzz_Model
		{
		public:
			int n;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 網路上解答普遍用運算元% 取餘判斷，此解法解省了 2 * O(n)的運算式，只需O(n)判斷是否存在值
		///       Runtime :   0 ms Beats   100 %
		///  Memory Usage : 7.1 MB Beats 98.26 %
		/// </summary>
		vector<string> fizzBuzz(int n) {
			vector<string> result(n, "");
			//1. 處理Fizz 每次跳3
			for (int index = 2; index < n; index += 3)
			{
				result[index] = "Fizz";
			}
			//2. 處理 Buzz 每次跳5
			for (int index = 4; index < n; index += 5)
			{
				result[index] += "Buzz";
			}
			//3. 剩下的空字串填上對應的數值
			for (int index = 0; index < n; index ++)
			{
				if (result[index].size() == 0)
					result[index] = to_string(index + 1);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Fizz_Buzz_Model GetTestData001(void)
		{
			Fizz_Buzz_Model result;
			result.n = 3;
			return result;//expect : ["1","2","Fizz"]
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Fizz_Buzz_Model GetTestData002(void)
		{
			Fizz_Buzz_Model result;
			result.n = 5;
			return result;//expect : ["1","2","Fizz","4","Buzz"]
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Fizz_Buzz_Model GetTestData003(void)
		{
			Fizz_Buzz_Model result;
			result.n = 15;
			return result;//expect : ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
		};
#pragma endregion TestData
	};
}