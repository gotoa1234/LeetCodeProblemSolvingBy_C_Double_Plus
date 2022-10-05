#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution30
{
#pragma region Paste to execute 
	/*
	#include "0030.Substring_with_Concatenation_of_All_Words.cpp"
	using namespace Solution30;
	using namespace std;

	int main()
	{
		Solution30::Substring_with_Concatenation_of_All_Words useClass;
		Solution30::Substring_with_Concatenation_of_All_Words::Substring_with_Concatenation_of_All_Words_Model getTestModel = useClass.GetTestData001();
		vector<int> result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		getTestModel = useClass.GetTestData002();
		result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		getTestModel = useClass.GetTestData003();
		result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// т┮Τ皚い﹃ 
	/// “矗ㄑ块 words ﹃皚–﹃常
	/// </summary>
	class Substring_with_Concatenation_of_All_Words
	{
#pragma region Model
	public:
		class Substring_with_Concatenation_of_All_Words_Model
		{
		public:
			string s;
			vector<string> words;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking            
		///      Runtime 
		///Memory Usage 
		/// </summary>
		
		//办跑计
		unordered_map<string, int> recordMap;
		int wordMaxCount;//﹃皚い羆计秖
		int stringUnitLength;//﹃皚虫﹃
		
		/// <summary>
		/// 
		/// </summary>
		void func(int startIndex, int endIndex, vector<int>& result, string& inputString) 
		{
			int len = 0;
			while (endIndex + stringUnitLength <= inputString.length()) 
			{
				string subStringItem = inputString.substr(endIndex, stringUnitLength);
				if (recordMap.count(subStringItem)) 
				{
					if (recordMap[subStringItem] > 0) 
					{
						recordMap[subStringItem]--;
						len++;
						endIndex += stringUnitLength;
					}
					else 
					{
						while (inputString.substr(startIndex, stringUnitLength) != subStringItem) 
						{ 
							len--; 
							recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
							startIndex += stringUnitLength; 
						}
						startIndex += stringUnitLength;
						endIndex += stringUnitLength;
					}
				}
				else 
				{
					while (startIndex < endIndex) 
					{ 
						len--; 
						recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
						startIndex += stringUnitLength; 
					}
					endIndex += stringUnitLength;
					startIndex += stringUnitLength;
				}

				if (len == wordMaxCount) 
				{ 
					result.push_back(startIndex); 
				}
			}

		}

		vector<int> findSubstring(string s, vector<string>& words) {

			wordMaxCount = words.size();
			stringUnitLength = words[0].size();
			unordered_map<string, int> hashMap;
			
			for (int index = 0; index < wordMaxCount; index++)
			{
				hashMap[words[index]]++;
			}
			
			vector<int> result;

			for (int startIndex = 0, endIndex = 0; 
				 startIndex < stringUnitLength; 
				 startIndex++ , endIndex++)
			{
				for (auto item : hashMap) 
				{
					recordMap[item.first] = item.second;
				}
				func(startIndex, endIndex, result, s);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Substring_with_Concatenation_of_All_Words_Model GetTestData001(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "barfoothefoobarman";
			result.words = { "foo","bar" };
			return result;//except: [0,9]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Substring_with_Concatenation_of_All_Words_Model GetTestData002(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "barfoothefoobarman";
			result.words = { "foo","bar" };
			return result;//expect: []
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Substring_with_Concatenation_of_All_Words_Model GetTestData003(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "barfoofoobarthefoobarman";
			result.words = { "bar","foo","the" };
			return result;//expect: [6,9,12]
		};
#pragma endregion TestData

	};
}