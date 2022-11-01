#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution49
{
#pragma region Paste to execute 
	/*
	#include "0049.Group_Anagrams.cpp"
	using namespace Solution49;
	using namespace std;

	int main()
	{

		Solution49::Group_Anagrams useClass;
		Solution49::Group_Anagrams::Group_Anagrams_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.rotate(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.rotate(getTestModel.matrix);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ∏s≤’¶r¡º
	/// </summary>
	class Group_Anagrams
	{
#pragma region Model
	public:
		class Group_Anagrams_Model
		{
		public:
			vector<string> strs;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking°G 
		///                
		///       Runtime°G
		/// Memory Usage °G
		/// </summary>	
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Group_Anagrams_Model GetTestData001(void)
		{
			Group_Anagrams_Model result;
			result.strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
			return result;//except: {{"bat"},{"nat","tan"},{"ate","eat","tea"}}
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Group_Anagrams_Model GetTestData002(void)
		{
			Group_Anagrams_Model result;
			result.strs = {""};
			return result;//except:{{""}}
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Group_Anagrams_Model GetTestData003(void)
		{
			Group_Anagrams_Model result;
			result.strs = {"a"};
			return result;//except:{{"a"}}
		};

#pragma endregion TestData

	};
}
