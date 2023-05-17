#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution190
{
#pragma region Paste to execute 
	/*
#include "Easy/0190.Reverse_Bits.cpp"
using namespace Solution190;
using namespace std;

int main()
{
		Solution190::Reverse_Bits useClass;
		Solution190::Reverse_Bits::Reverse_Bits_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.hammingWeight(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.hammingWeight(getTestModel.n);
		return 0;
}
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// 反轉 Bits
	/// </summary>
	class Reverse_Bits
	{
#pragma region Model
	public:
		class Reverse_Bits_Model
		{
		public:
			uint32_t n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路 ：反轉Bits表示4個位元組一共32個位元，因此將輸入的值做邏輯閘AND計算，若有數值在與位移後做OR即可，重複32次
		///      Runtime : 0 ms Beats   100 %
		/// Memory Usage : 6 MB Beats 74.54 %
		/// </summary>
		/// <returns></returns>        
		uint32_t reverseBits(uint32_t n)
		{
			auto result = 0;
			//4Bytes = 32bit
			for (int index = 0; index < 32; index++)
			{
				//每次位移後，n若是二進制下該位元有1 表示反轉的Result該位元為1
				result = ((result << 1) | (n & 1));
				n = n >> 1;
			}
			return result;
		}
	public:
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Reverse_Bits_Model GetTestData001(void)
		{
			Reverse_Bits_Model result;
			result.n = 0b00000010100101000001111010011100;
			return result;//expect: 964176192 
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Reverse_Bits_Model GetTestData002(void)
		{
			Reverse_Bits_Model result;
			result.n = 0b11111111111111111111111111111101;
			return result;//expect:  3221225471 
		};

#pragma endregion TestData
	};
}