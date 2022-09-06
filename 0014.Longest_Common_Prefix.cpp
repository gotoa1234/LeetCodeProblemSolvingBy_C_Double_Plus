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
	/// �̪��@�Ϋe��
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
		///          ����G�ƧǡA�Ĥ@�ӥ��w�O�̤p���סA�M���C�Ӷ��ؤ��A�Y���ۦP�h�O���A���ۦP�ɸ��X
		///      Runtime :   3 ms, faster than 92.55% of C++ online submissions for Longest Common Prefix.
		/// Memory Usage : 9.2 MB,   less than 83.20% of C++ online submissions for Longest Common Prefix.
		/// </summary>
		string longestCommonPrefix(vector<string>& strs) {
			string result = "";
			char currentChar = 0;
			short moveIndex = 0;			
			short index = 0;
			sort(strs.begin(), strs.end());
			short minLength = strs[0].size();
			while (moveIndex < minLength)
			{
				currentChar = strs[0][moveIndex];
				for (index = 0; index < strs.size() && currentChar == strs[index][moveIndex]; index++) {}
				if (index != strs.size())
					break;
				result.push_back(currentChar);
				moveIndex++;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Longest_Common_Prefix_Model GetTestData001(void)
		{
			Longest_Common_Prefix_Model result;
			result.strs = { "flower","flow","flight" };
			return result;//except: "fl"
		};

		/// <summary>
		/// ���ո��2
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