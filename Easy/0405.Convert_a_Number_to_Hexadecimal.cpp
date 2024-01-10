#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

namespace Solution405
{
#pragma region Paste to execute 
	/*
	#include "Easy/0405.Convert_a_Number_to_Hexadecimal.cpp"
	using namespace Solution405;
	using namespace std;

	int main()
	{
	Solution405::Convert_a_Number_to_Hexadecimals useClass;
	Solution405::Convert_a_Number_to_Hexadecimals::Convert_a_Number_to_Hexadecimals_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.toHex(getTestModel.num);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.toHex(getTestModel.num);

	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 數字轉為16進位
	/// </summary>
	class Convert_a_Number_to_Hexadecimals
	{
#pragma region Model
	public:
		//Definition for singly-linked list.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode() : val(0), left(nullptr), right(nullptr) {}
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};
	public:
		class Convert_a_Number_to_Hexadecimals_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：排除0，負數的時候用 unsinged int 最大值開始做16進位換算
		///       Runtime :    0 ms Beats 100.00 %
		///  Memory Usage : 6.27 mb Beats  87.90 % 
		/// </summary>
		string toHex(int num) {
			if (num == 0)
				return "0";

			string result{};
			unsigned int temp = num;
			if (num <= -1)
			{
				temp = UINT32_MAX + temp + 1;
			}
			int current = 0;
			while (temp != 0)
			{
				current = temp % 16;
				temp = temp / 16;
				if (current >= 0 && current <= 9)
				{
					result.insert(result.begin(), current + 48);
				}
				else
				{
					result.insert(result.begin(), current + 87);
				}	
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Convert_a_Number_to_Hexadecimals_Model GetTestData001(void)
		{
			Convert_a_Number_to_Hexadecimals_Model result;
			result.num = 26;
			return result;//expect: "1a"      就是（1 * 16 + 10）
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Convert_a_Number_to_Hexadecimals_Model GetTestData002(void)
		{
			Convert_a_Number_to_Hexadecimals_Model result{};
			result.num = -1;
			return result;//expect: "ffffffff"
		}; 

	private:

#pragma endregion TestData
	};
}