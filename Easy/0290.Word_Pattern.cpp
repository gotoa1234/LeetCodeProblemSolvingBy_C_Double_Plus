#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

namespace Solution290
{
#pragma region Paste to execute 
	/*
    #include "Easy\0290.Word_Pattern.cpp"
    using namespace Solution290;
    using namespace std;    
    int main()
    {
    	Solution290::Word_Pattern useClass;
    	Solution290::Word_Pattern::Word_Pattern_Model getTestModel = useClass.GetTestData001();
    	auto result = useClass.wordPattern(getTestModel.pattern, getTestModel.s);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 字匹配
	/// </summary>
	class Word_Pattern
	{
#pragma region Model
	public:
		class Word_Pattern_Model
		{
		public:
			string pattern;
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :此題目有說明，可能s或pattern有可能不是1比1，此種狀況為false
		///                建立兩個HashTable，然後"字元對字串"與"字串對字元"同時記錄，若有布匹配時則為False
		///       Runtime :  0 ms Beats   100 %
		///  Memory Usage :6.2 MB Beats 99.85 %
		/// </summary>
		bool wordPattern(string pattern, string s) 
		{
			//字元對字串 Hash
			unordered_map<char, string> _hashStrMap;
			//字串對字元 Hash
			unordered_map<string, char> _hashCharMap;
			string temp;
			stringstream splitVar(s);
			//1. 每個Pattern內的字元一一讀取
			for (int index = 0; index < pattern.size(); index++)
			{	
				auto charItem = pattern[index];
				//2. 跳脫條件，s已經用完了
				if (splitVar.eof() == true)
					return false;

				//3-1. s一一取出，與pattern一對一 
				getline(splitVar, temp, ' ');
				//3-2. 不存在時，兩邊相紀錄
				if (_hashStrMap.find(charItem) == _hashStrMap.end() &&
					_hashCharMap.find(temp) == _hashCharMap.end())
				{
					_hashStrMap[charItem] = temp;
					_hashCharMap[temp] = charItem;
				}
				else
				{
					//3-3. 存在時檢查是否1對1匹配
					if (_hashStrMap[charItem] != temp || _hashCharMap[temp] != charItem)
						return false;
				}
			}	
			//4. 最後檢查s是否用完，如果沒用完回傳false
			return splitVar.eof() == false ? false : true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Word_Pattern_Model GetTestData001(void)
		{
			Word_Pattern_Model result;
			result.pattern = "abba";
			result.s = "dog cat cat dog";
			return result;//expect : true
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Word_Pattern_Model GetTestData002(void)
		{
			Word_Pattern_Model result;
			result.pattern = "abba";
			result.s = "dog cat cat fish";
			return result;//expect: false
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Word_Pattern_Model GetTestData003(void)
		{
			Word_Pattern_Model result;
			result.pattern = "aaaa";
			result.s = "dog cat cat dog";
			return result;//expect: false
		};
#pragma endregion TestData
	};
}