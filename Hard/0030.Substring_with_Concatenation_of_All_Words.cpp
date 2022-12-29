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
	/// ��X�Ҧ��}�C���]�t���l�r�� 
	/// �����Ѫ���J words �l�r��}�C�A�C�Ӥl�r����׳��ۦP�A�B�n�D�O�������ǡA�������ƶq
	/// EX: ��J s = acdabcdeab �P words= {ab, cd}
	///               ----
	///                 ----
	///               �ŦX����m�N���W��-���a��A�ҥH��X�|�O 1,3 
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
		///     thinking�G �����D���������A�q�N�X�������� findSubstring() ���D�禡�}�l���R
		///      Runtime�G   83 ms Beats 87.44 %
		///Memory Usage �G 18.9 MB Beats 87.21 %
		/// </summary>
		
		//�����ܼ�
		unordered_map<string, int> recordMap;//�����Ϊ�Hash��
		int wordMaxCount;//�l�r��}�C�����`�ƶq
		int stringUnitLength;//�l�r��}�C��@�r�����
		
		/// <summary>
		/// �l�禡-��X���ަ�m
		/// </summary>
		void FindIndexPosition(int startIndex, int moveIndex, vector<int>& result, string& inputString) 
		{
			//4. ��e�d��쪺�ƶq
			int currentCount = 0;
			//5. �}�l�̷Ӥl�r����װ��첾�d��
			while (moveIndex + stringUnitLength <= inputString.length()) 
			{
				string subStringItem = inputString.substr(moveIndex, stringUnitLength);

				//5-1. �Ӥl�r��ŦX�d���H
				if (recordMap.count(subStringItem)) 
				{
					//6-1. �YHash���٥i�H�����A��ܲŦX
					if (recordMap[subStringItem] > 0) 
					{
						recordMap[subStringItem]--;
						currentCount++;
						moveIndex += stringUnitLength;
					}
					else //6-2 ���]�w�����Ӥl�r�ꪺ�ƶq�A��ܤ��ŦX
					{
						//���srecordMap���ȡA�u�^�u�w�B�z����
						while (inputString.substr(startIndex, stringUnitLength) != subStringItem) 
						{ 
							currentCount--; 
							recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
							startIndex += stringUnitLength; 
						}
						startIndex += stringUnitLength;
						moveIndex += stringUnitLength;
					}
				}
				else //5-2. �Ӥl�r�ꤣ�ŦX
				{
					//���srecordMap���ȡA�u�^�u�w�B�z����
					while (startIndex < moveIndex) 
					{ 
						currentCount--; 
						recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
						startIndex += stringUnitLength; 
					}
					moveIndex += stringUnitLength;
					startIndex += stringUnitLength;
				}

				//7. �p�G�d��쪺�ƶq�P�l�r��ƶq�@�P�A��ܧ��F
				if (currentCount == wordMaxCount) 
				{ 
					result.push_back(startIndex); 
				}
			}
		}

		/// <summary>
		/// �D�禡-��X�Ҧ��l�r�ꤣ������
		/// </summary>
		/// <param name="s"></param>
		/// <param name="words"></param>
		/// <returns></returns>
		vector<int> findSubstring(string s, vector<string>& words) {
			//1. �إ߹w�]��
			wordMaxCount = words.size();
			stringUnitLength = words[0].size();
			unordered_map<string, int> hashMap;
			
			//2. �إ߹w�]��Hash��A�C�Ӥl�r�����
			for (int index = 0; index < wordMaxCount; index++)
				hashMap[words[index]]++;			
			
			//3. �M���l�r�ꪺ����
			vector<int> result;
			for (int index = 0; 
				 index < stringUnitLength; 
				 index++)
			{
				//3-1. �C���s���ܤƴN���s�w�]���d�������
				for (auto item : hashMap) 
				{
					recordMap[item.first] = item.second;
				}
				//3-2. ��쪺���ަ�m�|������i result��
				FindIndexPosition(index, index, result, s);
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
			result.s = "wordgoodgoodgoodbestword";
			result.words = { "word","good","best","word" };
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