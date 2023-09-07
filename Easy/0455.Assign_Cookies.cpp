#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution455
{
#pragma region Paste to execute 
	/*
	#include "Easy\0455.Assign_Cookies.cpp"
	using namespace Solution455;

	int main()
	{
		Solution455::Assign_Cookies useClass;
		Solution455::Assign_Cookies::Assign_Cookies_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.findContentChildren(getTestModel.g, getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.findContentChildren(getTestModel.g, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 分配餅乾
	/// </summary>
	class Assign_Cookies
	{
#pragma region Model
	public:
		class Assign_Cookies_Model
		{
		public:
			vector<int> g;
			vector<int> s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 關鍵是先排序。 將人與餅乾進行排序，由小而大，逐一分配
		///       Runtime :  19 ms Beats 90.38 %
		///  Memory Usage :17.6 MB Beats 17.19 %
		/// </summary>
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());
			int result = 0;
			for (int index = 0; index < s.size() && result < g.size(); index++)
			{
				if (g[result] <= s[index])
					result++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Assign_Cookies_Model GetTestData001(void)
		{
			Assign_Cookies_Model result;
			result.g = { 1, 2, 3 };
			result.s = { 1, 1 };
			return result;//expect : 1
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Assign_Cookies_Model GetTestData002(void)
		{
			Assign_Cookies_Model result;
			result.g = { 1, 2 };
			result.s = { 1, 2, 3 };
			return result;//expect : 2
		};

#pragma endregion TestData
	};
}