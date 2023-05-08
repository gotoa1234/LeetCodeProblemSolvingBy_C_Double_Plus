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
	/// �r�ǰt
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
		///          ��� :���D�ئ������A�i��s��pattern���i�ण�O1��1�A���ت��p��false
		///                �إߨ��HashTable�A�M��"�r����r��"�P"�r���r��"�P�ɰO���A�Y�����ǰt�ɫh��False
		///       Runtime :  0 ms Beats   100 %
		///  Memory Usage :6.2 MB Beats 99.85 %
		/// </summary>
		bool wordPattern(string pattern, string s) 
		{
			//�r����r�� Hash
			unordered_map<char, string> _hashStrMap;
			//�r���r�� Hash
			unordered_map<string, char> _hashCharMap;
			string temp;
			stringstream splitVar(s);
			//1. �C��Pattern�����r���@�@Ū��
			for (int index = 0; index < pattern.size(); index++)
			{	
				auto charItem = pattern[index];
				//2. �������As�w�g�Χ��F
				if (splitVar.eof() == true)
					return false;

				//3-1. s�@�@���X�A�Ppattern�@��@ 
				getline(splitVar, temp, ' ');
				//3-2. ���s�b�ɡA����۬���
				if (_hashStrMap.find(charItem) == _hashStrMap.end() &&
					_hashCharMap.find(temp) == _hashCharMap.end())
				{
					_hashStrMap[charItem] = temp;
					_hashCharMap[temp] = charItem;
				}
				else
				{
					//3-3. �s�b���ˬd�O�_1��1�ǰt
					if (_hashStrMap[charItem] != temp || _hashCharMap[temp] != charItem)
						return false;
				}
			}	
			//4. �̫��ˬds�O�_�Χ��A�p�G�S�Χ��^��false
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