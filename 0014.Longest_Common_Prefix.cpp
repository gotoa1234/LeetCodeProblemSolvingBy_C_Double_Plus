#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution14
{
#pragma region Paste to execute 
	/*
	#include "0014.Longest_Common_Prefix.cpp"
    using namespace Solution14;
    using namespace std;
    
    int main()
    {
    	Solution14::Longest_Common_Prefix useClass;
    	Solution14::Longest_Common_Prefix::Longest_Common_Prefix_Model getTestModel = useClass.GetTestData001();
    	string result = useClass.longestCommonPrefix(getTestModel.strs);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.longestCommonPrefix(getTestModel.strs);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 最長共用前綴
	/// </summary>
	class Longest_Common_Prefix
	{
#pragma region Model
	public:
		class Longest_Common_Prefix_Model
		{
		public:
			vector<string> strs;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime :
		/// Memory Usage :
		/// </summary>
		string longestCommonPrefix(vector<string>& strs) {
			string result = "";
			int currentCaculation = 0;
			int tempCaculation = 0;
			int moveIndex = 0;
			int minLength = 201;
			int currentLength = 0;
			while (moveIndex < minLength)
			{
				currentCaculation = strs[0][moveIndex];
				tempCaculation = currentCaculation;
				for (int index = 0; index < strs.size(); index++)
				{
					if (moveIndex == 0)
					{
						currentLength = strs[index].size();
						minLength = min(minLength, currentLength);
						if (minLength == 0)
							return result;
					}
					tempCaculation = tempCaculation & strs[index][moveIndex];
				}
				if (tempCaculation != currentCaculation)
					break;
				result.push_back(strs[0][moveIndex]);
				moveIndex++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Longest_Common_Prefix_Model GetTestData001(void)
		{
			Longest_Common_Prefix_Model result;
			result.strs = { "flower","flow","flight" };
			return result;//except: "fl"
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Longest_Common_Prefix_Model GetTestData002(void)
		{
			Longest_Common_Prefix_Model result;
			result.strs = { "dog","racecar","car" };
			return result;//expect: ""
		};
#pragma endregion TestData
	};
}