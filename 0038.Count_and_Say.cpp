#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution38
{
#pragma region Paste to execute 
	/*
	#include "0038.Count_and_Say.cpp"
	using namespace Solution38;
	using namespace std;

	int main()
	{
	    string result = "";
		Solution38::Count_and_Say useClass;
		Solution38::Count_and_Say::Count_and_Say_Model getTestModel = useClass.GetTestData001();
		result = useClass.countAndSay(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		result = useClass.countAndSay(getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �p��"��"���Ʀr
	/// ���D�N: �w�T�w n = 1 ���ɭԬO "1"
	///         ��n = 2 �ɬݨ� n = 1 �� "1"    �n���� 1��1       �ҥH n = 2 ���׬O "11"
	///         ��n = 3 �ɬݨ� n = 2 �� "11"   �n���� 2��1       �ҥH n = 3 ���׬O "21"
	///         ��n = 4 �ɬݨ� n = 3 �� "21"   �n���� 1��2�P1��1 �ҥH n = 4 ���׬O "1211"
	///         ��n = 5 �ɬݨ� n = 4 �� "1211" �n���� 1��1�P1��2�P2��1 �ҥH n = 5 ���׬O "111221"
	/// </summary>
	class Count_and_Say
	{
#pragma region Model
	public:
		class Count_and_Say_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G ���j�ѡA��f(1) = "1" ���}�Y�A�v�B���o��
		///       Runtime�G  3 ms Beats 94.21%
		/// Memory Usage �G7.1 MB Beats 33.02%
		/// </summary>
		unordered_map<int, string> _dpHashMap;
		string countAndSay(int n) {
			_dpHashMap[1] = "1";
			auto result = FindSayCount(n);
			return result;
		}
	private:
		string FindSayCount(int n)
		{
			if (_dpHashMap.find(n) != _dpHashMap.end())
			{
				return _dpHashMap[n];
			}
			else
			{
				string getMessage = FindSayCount(n - 1);							
				string iSay = "";
				int count = 1;
				//f(n) �ѪR f(n-1) ���r��A�åB�զ� f(n) ����
				for (int index = 0; index < getMessage.size(); index++)
				{
					//������ɥi���}
					if (index + 1 == getMessage.size())
					{
						iSay.push_back(count + 48);
						iSay.push_back(getMessage[index]);
						count == 1;
						break;
					}
					else
					{
						//��e�r���P�U�@�r�����P�A�i�H���p
						if (getMessage[index + 1] != getMessage[index])
						{
							iSay.push_back(count + 48);
							iSay.push_back(getMessage[index]);
							count = 1;
						}
						else
						{
							//�֭p�ƭ�
							count++;
						}
					}
				}
				_dpHashMap[n] = iSay;
				return iSay;
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Count_and_Say_Model GetTestData001(void)
		{
			Count_and_Say_Model result;
			result.n = 1;
			return result;//except: "1"
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Count_and_Say_Model GetTestData002(void)
		{
			Count_and_Say_Model result;
			result.n = 5;
			return result;//except: "1211"
		};
#pragma endregion TestData

	};
}