#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution504
{
#pragma region Paste to execute 
	/*
	#include "Easy\0504.Base_7.cpp"
	using namespace Solution504;

	int main()
	{
		Solution504::Base_7 useClass;
		Solution504::Base_7::Base_7_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.convertToBase7(getTestModel.num);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.convertToBase7(getTestModel.num);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���7
	/// </summary>
	class Base_7
	{
#pragma region Model
	public:
		class Base_7_Model
		{
		public:
			int num;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �B�z�t�ơA���_ %7 �B /7 �̫�b����r��Y������
		///       Runtime :   0 ms Beats 100.0 %
		///  Memory Usage :	6.2 MB Beats 17.55 %
		/// </summary>
	    string convertToBase7(int num) {
			string result{};

			//1. �B�z�t��
			bool isNeative = false;
			if (num < 0)
			{
				isNeative = true;
				num *= -1;
			}

			//2. ���_���l�ơA�åB���H7(��0�ɪ�ܰ��ɥi�H���X)
			while (true)
			{				
				auto bit = num % 7;
				num = num / 7;
			    result.push_back(bit + 48);				
				if (num == 0)
					break;
			}

			//3. �ɦ^�t�ƲŸ�
			if (isNeative)
			{
				result.push_back('-');
			}
			//4. ����r��A�]���L�{���� push_back()
			reverse(result.begin(), result.end());
			return result;
        }
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Base_7_Model GetTestData001(void)
		{
			Base_7_Model result;
			result.num = 100;
			return result;//expect : 202
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Base_7_Model GetTestData002(void)
		{
			Base_7_Model result;
			result.num = -7;
			return result;//expect : -10
		};
#pragma endregion TestData
	};
}