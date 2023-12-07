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
	/// 第一個壞掉版本
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
		///          思路： 二分搜尋的應用，前置作業先設定左與右範圍，然後在應用二分搜尋找出交界點
		///       Runtime :   0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
		///  Memory Usage : 5.7 MB,   less than  89.06% of C++ online submissions for First Bad Version.
		/// </summary>
		int firstBadVersion(int n) {
			int left = 0;
			int right = INT_MAX;

			//1. 決定左右範圍
			if (isBadVersion(n))
				right = n;
			else
				left = n;

			int result = n;
			//2-1. 不斷切割一半搜尋
			while (left <= right)
			{
				result = left + (right - left) / 2;
				if (isBadVersion(result))
					right = result - 1;
				else
					left = result + 1;

				//2-2. 持續左右中間壓縮必定遇到 false , true 的狀況
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
			if (version >= _badVersion)//在壞版本之後
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
		/// 測試資料1
		/// </summary>        
		First_Bad_Version_Model GetTestData001(void)
		{
			First_Bad_Version_Model result;
			result.n = 5;
			result.bad = 4;
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		First_Bad_Version_Model GetTestData002(void)
		{
			First_Bad_Version_Model result;
			result.n = 2;
			result.bad = 2;
			return result;
		};

		/// <summary>
		/// 測試資料3
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