#include <iostream>
#include <stack>
#include <string>
using namespace std;

namespace Solution394
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "0394.Decode_String.cpp"
	using namespace Solution394;

	int main()
	{
		Solution394::Decode_String useClass;
		Solution394::Decode_String::Decode_String_Model getTestModel = useClass.GetTestData001();
		int result = useClass.decodeString(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.decodeString(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 解碼字符串
	/// </summary>
	class Decode_String
	{
#pragma region Model
	public:
		class Decode_String_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///            思路：遍歷，利用2個堆疊將數字、字母做累積。在遇到 '[' 時將目前走過的數字、字母放進堆疊中
		///                 直到走到']' 取出數字堆疊，將字串重複累加，重複前面步驟。最後輸出結果。
		///        Runtime :   0 ms, faster than 100.00% of C++ online submissions for Decode String.
		///   Memory Usage : 6.5 MB,   less than  77.13% of C++ online submissions for Decode String.
		///Time complexity : O(N)
		/// <returns></returns>
		string decodeString(string s) {
			stack<string> digitStack, alphaStack;//設定數字、字母堆疊
			string digitStr = "";//數字紀錄成字串，才能紀錄2位以上數字
			string resultStr = "";//結果字串

			for (int index = 0; index < s.size(); index++)
			{
				if (isdigit(s[index])) //數字
					digitStr += s[index];
				else if (isalpha(s[index]))//字母
					resultStr += s[index];
				else if (s[index] == '[') //遇到 [ 要將累積的放進堆疊
				{
					digitStack.push(digitStr);
					alphaStack.push(resultStr);
					digitStr.clear();
					resultStr.clear();
				}
				else
				{
					//2. 遇到 ] 時把最近的 數字取出，並且將當前字串重複累加
					if (s[index] == ']')
					{
						int digit = stoi(digitStack.top());
						digitStack.pop();
						string newResult = "";
						for (int repeatTime = 0; repeatTime < digit; repeatTime++)
						{
							newResult += resultStr;
						}
						resultStr = newResult;
					}
					//3. 若數字旁有字母取出累加
					resultStr = alphaStack.top() + resultStr;
					alphaStack.pop();
				}
			}
			return resultStr;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料2
		/// </summary>        
		Decode_String_Model GetTestData001(void)
		{
			Decode_String_Model result;
			result.s = "3[a]22[bc]";
			return result;//expect:"aaabcbc"
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Decode_String_Model GetTestData002(void)
		{
			Decode_String_Model result;
			result.s = "3[a2[c]]";
			return result;//expect:"accaccacc"
		};

#pragma endregion TestData
	};
}