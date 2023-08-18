#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

namespace Solution342
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0342.Power_of_Four.cpp"
	using namespace Solution342;

	int main()
	{
		Solution342::Power_of_Four useClass;
		Solution342::Power_of_Four::Power_of_Four_Model getTestModel = useClass.GetTestData001();
		int result = useClass.reverseVowels(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.reverseVowels(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 四的平方
	/// </summary>
	class Power_of_Four
	{
#pragma region Model
	public:
		class Power_of_Four_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///           Think：如果不用loop 就是先將4的次方全放進陣列，在2^31 中(int 型別) 也就20個數值	
		///         Require: Follow up: Could you solve it without loops/recursion?
		///        Runtime : 0 ms Beats 100 %
		///   Memory Usage : 6 MB Beats 42.67 %
		/// <returns></returns>
		bool isPowerOfFour(int n) {
			vector<int> powerOfFours = { 1,4,16,64,256,1024,4096,16384 ,65536,262144,1048576, 4194304, 16777216,67108864, 268435456, 1073741824 };
			for (int index = 0; index < powerOfFours.size(); index++)
				if (powerOfFours[index] == n)
					return true;
			return false;
		}

		/// <summary>
		///         非題目要求，但通常找出任意N 會用Loop解
		///        Runtime :   0 ms Beats  100 %
	    ///   Memory Usage : 5.9 MB Beats 80.9 %
		/// </summary>		
		bool isPowerOfFour_loopSolve(int n) {
			if (n == 0)
				return false;
			if (n == 1)
				return true;
			while (n % 4 == 0)
				n = n / 4;
			return n == 1 ? true : false;
		}



#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Power_of_Four_Model GetTestData001(void)
		{
			Power_of_Four_Model result;
			result.n = 16;
			return result;//expect:true
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Power_of_Four_Model GetTestData002(void)
		{
			Power_of_Four_Model result;
			result.n = 5;
			return result;//expect:false
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Power_of_Four_Model GetTestData003(void)
		{
			Power_of_Four_Model result;
			result.n = 1;
			return result;//expect:true
		};

#pragma endregion TestData
	};
}