#include <iostream>
#include <vector>
using namespace std;

namespace Solution278
{
#pragma region Paste to execute 
	/*
	#include "Easy\0278.First_Bad_Version.cpp"
	using namespace Solution278;
	using namespace std;

	Solution278::First_Bad_Version useClass;
	Solution278::First_Bad_Version::First_Bad_Version_Model getTestModel = useClass.GetTestData001();
	useClass._badVersion = getTestModel.bad;
	int result = useClass.firstBadVersion(getTestModel.n);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �Ĥ@���a������
	/// </summary>
	class First_Bad_Version
	{
#pragma region Model
	public:
		class First_Bad_Version_Model
		{
		public:
			int n;
			int bad;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G �G���j�M�����ΡA�e�m�@�~���]�w���P�k�d��A�M��b���ΤG���j�M��X����I
		///       Runtime :   0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
		///  Memory Usage : 5.7 MB,   less than  89.06% of C++ online submissions for First Bad Version.
		/// </summary>
		int firstBadVersion(int n) {
			int left = 0;
			int right = INT_MAX;

			//1. �M�w���k�d��
			if (isBadVersion(n))
				right = n;
			else
				left = n;

			int result = n;
			//2-1. ���_���Τ@�b�j�M
			while (left <= right)
			{
				result = left + (right - left) / 2;
				if (isBadVersion(result))
					right = result - 1;
				else
					left = result + 1;

				//2-2. ���򥪥k�������Y���w�J�� false , true �����p
				if (false == isBadVersion(result - 1) &&
					true == isBadVersion(result)
					)
					return result;
			}
			return result;
		}
	private:
		bool isBadVersion(int version)
		{
			if (version >= _badVersion)//�b�a��������
			{
				return true;
			}
			else
				return false;
		}
	public:
		int _badVersion = 0;
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		First_Bad_Version_Model GetTestData001(void)
		{
			First_Bad_Version_Model result;
			result.n = 5;
			result.bad = 4;
			return result;
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		First_Bad_Version_Model GetTestData002(void)
		{
			First_Bad_Version_Model result;
			result.n = 2;
			result.bad = 2;
			return result;
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		First_Bad_Version_Model GetTestData003(void)
		{
			First_Bad_Version_Model result;
			result.n = 2126753390;
			result.bad = 1702766719;
			return result;
		};
#pragma endregion TestData
	};
}