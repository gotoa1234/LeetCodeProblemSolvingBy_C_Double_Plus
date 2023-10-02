#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution507
{
#pragma region Paste to execute 
	/*
	#include "Easy\0507.Perfect_Number.cpp"
	using namespace Solution507;

	int main()
	{
		Solution507::Perfect_Number useClass;
		Solution507::Perfect_Number::Perfect_Number_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.checkPerfectNumber(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.checkPerfectNumber(getTestModel.num);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 完美的數字
	/// </summary>
	class Perfect_Number
	{
#pragma region Model
	public:
		class Perfect_Number_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 利用完整數的特性，除以偶數 & 加總因子，最後比較是否與原值一致
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage :	6.3 MB Beats 18.20 %
		/// </summary>
		bool checkPerfectNumber(int num) 
		{
			//1. 排除1
			if (num == 1) 
				return false;
			int sum = 1;

			//2-1. 完整數需要可以被整除
			for (int index = 2; index < sqrt(num); index *= 2)
			{
				//2-2. 整除規則 
				if (num % index == 0) 
					sum += index + (num / index);
			}
			//3. 若加總因子的結果等於原值表示是完整數
			return sum == num;
		}


		/// <summary>
		///          思路 : 題目給定10^8為num的範圍，可以知道完整數只有以下6種，建立好HashTable然後返回即完成
		///                 此解法在應用上常在資料庫中建表查詢使用到。 
		///       Runtime :   0 ms Beats  100 %
		///  Memory Usage :	6.4 MB Beats 8.95 %
		/// <returns></returns>
		bool checkPerfectNumber_Solve2(int num)
		{
			unordered_map<int, bool> _hashTable = { {6, true }, {28, true}, {496, true}, {8128, true}, {33550336, true}, {8589869056, true} };
			return _hashTable.find(num) != _hashTable.end() ? true
				: false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Perfect_Number_Model GetTestData001(void)
		{
			Perfect_Number_Model result;
			result.num = 28;
			return result;//expect : true
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Perfect_Number_Model GetTestData002(void)
		{
			Perfect_Number_Model result;
			result.num = 7;
			return result;//expect : false
		};
#pragma endregion TestData
	};
}

//Example 1:
//
//Input: num = 28
//Output : true
//Explanation : 28 = 1 + 2 + 4 + 7 + 14
//1, 2, 4, 7, and 14 are all divisors of 28.
//Example 2 :
//
//	Input : num = 7
//	Output : false