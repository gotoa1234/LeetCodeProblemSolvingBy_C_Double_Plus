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
		///           
		///      Runtime�G  16 ms Beats 93.14 %
		/// Memory Usage�G10.8 MB Beats 49.77 %
		/// </summary>
		int countBinarySubstrings(string s) {
			int result = 0;
			int preCount = 0;
			int currentCount = 1;
			for (int index = 0; index < s.size() - 1; index++)
			{
				if (s[index] == s[index + 1])
					currentCount++;
				else
				{
					result += min(preCount, currentCount);
					preCount = currentCount;
					currentCount = 1;
				}
			}
			return result + min(preCount, currentCount);
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


#pragma endregion TestData

	};
}