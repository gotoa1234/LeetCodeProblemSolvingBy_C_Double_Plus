#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

namespace Solution187
{
#pragma region Paste to execute 
	/*
	#include <unordered_map>
	#include "Medium/0187.Repeated_DNA_Sequences.cpp"
	using namespace Solution187;

	int main()
	{
		Solution187::Repeated_DNA_Sequences useClass;
		Solution187::Repeated_DNA_Sequences::Repeated_DNA_Sequences_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.findRepeatedDnaSequences(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.findRepeatedDnaSequences(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// ���ƪ�DNA�ǦC
	/// </summary>
	class Repeated_DNA_Sequences
	{
#pragma region Model
	public:
		class Repeated_DNA_Sequences_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         ����G�D�ئ����� s[i] is either 'A', 'C', 'G', or 'T'. 
		///               �]�����ΦҼ{�O�_��DNA�H�~���r���A�]���D�إi�H�אּ : 10�Ӫ��ת��r��O�_����
		///               �Q�Ψ��Hashset�A�@�Ӭ�����e�o�{���A�t�@�Ӭ����O�_�w�g�s�b�A�Y���N������DNA�ǦC	
		///      Runtime�G  44 ms Beats 97.14 %
		/// Memory Usage�G19.4 MB Beats 81.41 %
		/// </summary>
		/// <returns></returns>
	public:
		vector<string> findRepeatedDnaSequences(string s) 
		{
			unordered_set<string> dnaResult;
			unordered_set<string> findRecords;
			for (int index = 0; index + 9 < s.size(); index++)
			{
				auto subString = s.substr(index, 10);
				if (findRecords.count(subString))
					dnaResult.insert(subString);
				else
					findRecords.insert(subString);
			}
			return vector<string>{dnaResult.begin(), dnaResult.end() };
		}
	public:
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Repeated_DNA_Sequences_Model GetTestData001(void)
		{
			Repeated_DNA_Sequences_Model result;
			result.s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
			return result;//expect: ["AAAAACCCCC","CCCCCAAAAA"]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Repeated_DNA_Sequences_Model GetTestData002(void)
		{
			Repeated_DNA_Sequences_Model result;
			result.s = "AAAAAAAAAAAAA";
			return result;//expect: ["AAAAAAAAAA"]
		};

#pragma endregion TestData
	};
}