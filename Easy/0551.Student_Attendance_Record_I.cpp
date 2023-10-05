#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution551
{
#pragma region Paste to execute 
	/*
	#include "Easy\0551.Student_Attendance_Record_I.cpp"
	using namespace Solution551;

	int main()
	{
		Solution551::Student_Attendance_Record_I useClass;
		Solution551::Student_Attendance_Record_I::Student_Attendance_Record_I_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.checkRecord(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.checkRecord(getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �ǥͥX�u��
	/// </summary>
	class Student_Attendance_Record_I
	{
#pragma region Model
	public:
		class Student_Attendance_Record_I_Model
		{
		public:
			string s;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : �D�ئ���ت��A���i�o��
		///                 1. 2�� 'A' �r���A��ܯʮu���i2���H�W
		///                 2. �s��X�{3�� 'L'�A��ܿ�줣�i�H�s��3���H�W
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage :	6.6 MB Beats 12.32 %
		/// </summary>
		bool checkRecord(string s) {
			int absenctCount = 0;
			bool continueLate = false;
			for (int index = 0; index < s.size(); index++)
			{
				if (s[index] == 'A')
				{
					absenctCount++;
					if (absenctCount >= 2)
						return false;
				}
				else if (s[index] == 'L')
				{
					if (index + 2 < s.size())
					{
						if (s[index + 1] == 'L' &&
							s[index + 2] == 'L')
							return false;
					}
				}
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Student_Attendance_Record_I_Model GetTestData001(void)
		{
			Student_Attendance_Record_I_Model result;
			result.s = "AA";
			return result;//expect : True
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Student_Attendance_Record_I_Model GetTestData002(void)
		{
			Student_Attendance_Record_I_Model result;
			result.s = "PPALLL";
			return result;//expect : false
		};

#pragma endregion TestData
	};
}