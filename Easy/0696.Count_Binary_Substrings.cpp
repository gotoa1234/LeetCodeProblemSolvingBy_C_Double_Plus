#include <iostream>
#include <vector>
using namespace std;

namespace Solution696
{
#pragma region Paste to execute 
	/*
	#include "Easy\0696.Count_Binary_Substrings.cpp"
	using namespace Solution696;
	using namespace std;

	int main()
	{
		Solution696::Count_Binary_Substrings useClass;
		Solution696::Count_Binary_Substrings::Count_Binary_Substrings_Model getTestModel = useClass.GetTestData001();
		int result = useClass.countBinarySubstrings(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.countBinarySubstrings(getTestModel.s);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.countBinarySubstrings(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �έp�G�i��l�r�Ŧ�
	/// </summary>
	class Count_Binary_Substrings
	{
#pragma region Model
	public:
		class Count_Binary_Substrings_Model
		{
		public:
			string s;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         ����G�D�حn�D��J�@�Ӧr��A�̭����l�r�ꤤ�n�P��"�]�t0�P1" ���r�����l�r�꦳�h�֭�
		///               ���k���Ѥƫ᪺�ѡA�i�H���Ѧ� countBinarySubstrings_Solve2
		///      Runtime�G  16 ms Beats 93.14 %
		/// Memory Usage�G10.8 MB Beats 49.77 %
		/// </summary>
		int countBinarySubstrings(string s) {
			int result = 0;
			int prevMatch = 0;
			int currentMatch = 0;

			for (int index = 0, currentMatch = 1; index < s.length() - 1; index++)
			{				
				if (s[index] == s[index + 1])
					currentMatch++;
				else
				{
					result += min(prevMatch, currentMatch);
					prevMatch = currentMatch;
					currentMatch = 1;
				}
			}
			return result + min(prevMatch, currentMatch);
		}

		/// <summary>
		///         ����G�o�O�@�ӫܦn�z�Ѫ��@�k�A���M���@���N�C�ӳs�򪺦r�����s���A�M��A�M���@���[�`�Ҧ����ƭ�	
		///      Runtime�G  22 ms Beats 46.88 %
		/// Memory Usage�G14.4 MB Beats 10.25 %
		/// </summary>
		int countBinarySubstrings_Solve2(string s) {
			//�إߤ@�Ӹs�խӼ�
			vector<int> groups{};
			int addcount = 0;
			for (int index = 0; index < s.size();)
			{		
				addcount = 0;
				int innerIndex = 0;
				for (innerIndex = index;innerIndex < s.size(); innerIndex++)
				{
					if (s[index] == s[innerIndex])
						addcount++;
					else					
						break;
				}
				index = innerIndex;
				groups.push_back(addcount);
			}

			//���w�O0���s��ƻP1���s��ư����A�����p���A�Ҧp 110 �N�O1�� 1100 �N�|�O2��
			//�������P�ɥX�{0�P1 �~����
			int result = 0;
			for (int index = 1; index < groups.size(); index++)
			{
				result += min(groups[index - 1], groups[index]);
			}
			return result;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Count_Binary_Substrings_Model GetTestData001(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "00110011";			
			return result;//except: 6
			//�|���l�r�� : "0","00","001","0011","1","11","110","1100","100","1001"
			//���]�t0�P1 : "001","0011","110","1100","100","1001" �@�@6��

		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Count_Binary_Substrings_Model GetTestData002(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "10101";
			return result;//expect:4
		    //�|���l�r�� : "","00","001","0011","1","11","110","1100","100","1001"
			//���]�t0�P1 : "001","0011","110","1100","100","1001" �@�@6��
		};


		/// <summary>
		/// ���ո��3
		/// </summary>   
		Count_Binary_Substrings_Model GetTestData003(void)
		{
			Count_Binary_Substrings_Model result;
			result.s = "000111000111";
			return result;//expect:9
		};



#pragma endregion TestData

	};
}