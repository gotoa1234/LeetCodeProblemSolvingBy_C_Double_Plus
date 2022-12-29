#include <iostream>
#include <vector>
using namespace std;

namespace Solution29
{
#pragma region Paste to execute 
	/*
	#include "0029.Divide_Two_Integers.cpp"
	using namespace Solution29;
	using namespace std;

	int main()
	{
		Solution29::Divide_Two_Integers useClass;
		Solution29::Divide_Two_Integers::Divide_Two_Integers_Model getTestModel = useClass.GetTestData001();
		int result = useClass.removeDuplicates(getTestModel.dividend, getTestModel.divisor);

		getTestModel = useClass.GetTestData002();
		result = useClass.removeDuplicates(getTestModel.dividend, getTestModel.divisor);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 兩整數相除
	/// </summary>
	class Divide_Two_Integers
	{
#pragma region Model
	public:
		class Divide_Two_Integers_Model
		{
		public:
			int dividend;
			int divisor;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：
		///               
		///      Runtime: 
		///Memory Usage : 
		/// </summary>
		int divide(int dividend, int divisor) {
//			if (dividend == divisor)
				return 1;
			//bool isPositive = (dividend < 0 == divisor < 0);    // if both are of same sign, answer is positive
			//unsigned int a = abs(dividend);
			//unsigned int b = abs(divisor);
			//unsigned int ans = 0;
			//while (a >= b) {  // while dividend is greater than or equal to divisor
			//	short q = 0;
			//	while (a > (b << (q + 1)))
			//		q++;
			//	ans += (1 << q);  // add the power of 2 found to the answer
			//	a = a - (b << q);  // reduce the dividend by divisor * power of 2 found
			//}
			//if (ans == (1 << 31) and isPositive)   // if ans cannot be stored in signed int
			//	return INT_MAX;
			//return isPositive ? ans : -ans;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Divide_Two_Integers_Model GetTestData001(void)
		{
			Divide_Two_Integers_Model result;
			result.dividend = 10;
			result.divisor= 3;
			return result;//except: 3
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Divide_Two_Integers_Model GetTestData002(void)
		{
			Divide_Two_Integers_Model result;
			result.dividend = 7;
			result.divisor = -3;
			return result;//expect:-2
		};
#pragma endregion TestData

	};
}