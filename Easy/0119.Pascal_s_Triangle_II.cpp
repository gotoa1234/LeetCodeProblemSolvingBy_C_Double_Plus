#include <iostream>
#include <vector>
using namespace std;

namespace Solution119
{
#pragma region Paste to execute 
	/*
	#include "Easy\0119.Pascal_s_Triangle_II.cpp"
	using namespace Solution119;
	using namespace std;

	int main()
	{
		Solution119::Pascal_s_Triangle_II useClass;
		Solution119::Pascal_s_Triangle_II::Pascal_s_Triangle_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.getRow(getTestModel.rowIndex);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.getRow(getTestModel.rowIndex);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �����d�T�� II
	/// </summary>
	class Pascal_s_Triangle_II
	{
#pragma region Model
	public:
		class Pascal_s_Triangle_II_Model
		{
		public:
			int rowIndex;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G �P118.�޿�ۦP�A���n����2���}�C�A�çQ�Υ��������G�p���U�@���A�~��[�ֳt��
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 6.3 MB Beats 81.35 %
		/// </summary>
		vector<int> getRow(int rowIndex) {
			vector<int> result{};
			//1. �M���C�h
			for (int index = 0; index <= rowIndex; index++)
			{
				//2. �C�i�s���@�h�[�J�����d�������1�b�̫e��
				result.insert(result.begin(), 1);
				//3. �C���[�`���u�֭p�������ȡA���������d�ֶi
				for (int loopCount = 1; loopCount < index; loopCount++)				
					result[loopCount] = result[loopCount] + result[loopCount + 1];
			}
			return result;
		}



#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Pascal_s_Triangle_II_Model GetTestData001(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.rowIndex = 3;

			return result;//expect:[1,3,3,1]
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData002(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.rowIndex = 0;
			return result;//expect:[[1]]
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Pascal_s_Triangle_II_Model GetTestData003(void)
		{
			Pascal_s_Triangle_II_Model result;
			result.rowIndex = 1;
			return result;//expect:[[1,1]]
		};

#pragma endregion TestData
	};
}
