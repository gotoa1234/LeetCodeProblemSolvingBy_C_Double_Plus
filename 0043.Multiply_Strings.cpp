#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution43
{
#pragma region Paste to execute 
	/*
	#include "0043.Multiply_Strings.cpp"
	using namespace Solution43;
	using namespace std;

	int main()
	{
		string result = 0;
		Solution43::Multiply_Strings useClass;
		Solution43::Multiply_Strings::Multiply_Strings_Model getTestModel = useClass.GetTestData001();
		result = useClass.multiply(getTestModel.num1, getTestModel.num2);

		getTestModel = useClass.GetTestData002();
		result = useClass.multiply(getTestModel.num1, getTestModel.num2);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 字串相乘
	/// </summary>
	class Multiply_Strings
	{
#pragma region Model
	public:
		class Multiply_Strings_Model
		{
		public:
			string num1;
			string num2;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 需要遵守不用BigIntenger的.dll，需要利用以下特性，每次對單一個字元從 ASCII 轉成INT數值 相乘，利用乘積將對應位置的值相加
		///                假設num1 : "123" num2: "456" ，那麼用乘法展開可以得知長度最多6位
		///                EX: 123
		///                    456
		///                -------
		///                   1368
		///                   912
		///                  456
		///       Runtime：  7 ms Beats 84.57 %
		/// Memory Usage ：6.7 MB Beats 70.33 %
		/// </summary>	
		string multiply(string num1, string num2) {
			//1. 排除0 ，可以有效加快速度
			if (num1.size() > 0)
			{
				if (num1[0] == '0')
					return "0";
			}
			if (num2.size() > 0)
			{
				if (num2[0] == '0')
					return "0";
			}

			vector<int> tempNumberSequence(num1.size() + num2.size(), 0);
			int moveIndex = 0;
			int tempValue = 0;
			int carry = 0;
			//2. 用兩個For迴圈將數值乘出
			for (int index = 0, useIndex = 0; index < num1.size(); index++)
			{
				useIndex = num1.size() - 1 - index;
				for (int innerIndex = 0, useInnerIndex = 0; innerIndex < num2.size(); innerIndex++)
				{
					//3. 將字元取出相乘，並且計算進位
					useInnerIndex = num2.size() - 1 - innerIndex;
					tempValue = (num1[useIndex] - '0') * (num2[useInnerIndex] - '0');
					moveIndex = index + innerIndex;
					tempNumberSequence[moveIndex] += ((tempValue % 10) + carry);
					carry = tempValue / 10 + tempNumberSequence[moveIndex] / 10;
					tempNumberSequence[moveIndex] %= 10;
				}
				if (carry > 0)
				{
					tempNumberSequence[moveIndex + 1] += carry;
					carry = 0;
				}
			}
			
			string result = "";
			//4. 印出時由後往前，如果第一個為0則排除
			auto sequenceLength = tempNumberSequence[tempNumberSequence.size() - 1] == 0
				                 ? tempNumberSequence.size() - 2
				                 : tempNumberSequence.size() - 1;
			for (int index = sequenceLength; index >= 0; index--)
			{
				result.push_back(tempNumberSequence[index] + '0');
			}
			return result;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Multiply_Strings_Model GetTestData001(void)
		{
			Multiply_Strings_Model result;
			result.num1 = "2";
			result.num2 = "3";
			return result;//except: "6"
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Multiply_Strings_Model GetTestData002(void)
		{
			Multiply_Strings_Model result;
			result.num1 = "123";
			result.num2 = "456";

			return result;//except: 56088
		};
#pragma endregion TestData

	};
}
