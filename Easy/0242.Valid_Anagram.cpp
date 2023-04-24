#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution242
{
#pragma region Paste to execute 
	/*
    #include "Easy\0242.Valid_Anagram.cpp"
    using namespace Solution242;
    
    int main()
    {
    
    	Solution242::Valid_Anagram useClass;
    	Solution242::Valid_Anagram::Valid_Anagram_Model getTestModel = useClass.GetTestData001();
    	bool result = useClass.isAnagram(getTestModel.s, getTestModel.s);
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���Ī��r��
	/// </summary>
	class Valid_Anagram
	{
#pragma region Model
	public:
		class Valid_Anagram_Model
		{
		public:
			string s;
			string t;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �o��O�]�t�i����Unicode�r�����g�k�A�p�G���Ҽ{unicode������vector<int>�į�|���ɫܦh
		///      �[�����D : Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
		///                 �]�t��L�r�����Ѫk�C
		///       Runtime :   8 ms Beats 75.50 %
		///  Memory Usage : 7.4 MB Beats 60.39 %
		/// </summary>
		bool isAnagram(string s, string t) {
			if (s.size() != t.size())
				return false;			
			unordered_map<char, int> recordHashTable{};
			//1. �����C�Ӧr�������ơAt������As�����[
			for (int index = 0; index < s.size(); index++)
			{
				recordHashTable[s[index]]++;
				recordHashTable[t[index]]--;
			}
			//�̫�Ҧ�������������0�~�A�X�k��
			for (auto item : recordHashTable)
			{
				if (item.second != 0)
					return false;
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Valid_Anagram_Model GetTestData001(void)
		{
			Valid_Anagram_Model result;
			result.s = "anagram";
			result.t = "nagaram";
			return result;//expect : true
		};
		/// <summary>
		/// ���ո��2
		/// </summary>   
		Valid_Anagram_Model GetTestData002(void)
		{
			Valid_Anagram_Model result;
			result.s = "rat";
			result.t = "car";
			return result;//expect : false
		};
#pragma endregion TestData
	};
}