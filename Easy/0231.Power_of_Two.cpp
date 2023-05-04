#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution231
{
#pragma region Paste to execute 
	/*
	#include "Easy\0231.Power_of_Two.cpp"
	using namespace Solution231;

	int main()
	{

		Solution231::Power_of_Two useClass;
		Solution231::Power_of_Two::Power_of_Two_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isAnagram(getTestModel.s, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���Ī��r��
	/// </summary>
	class Power_of_Two
	{
#pragma region Model
	public:
		class Power_of_Two_Model
		{
		public:
			int n;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� : 
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 5.8 MB Beats 97.25 %
		/// </summary>
		bool isPowerOfTwo(int n) {
			bool result = false;
			while (n != 0)
			{
				if (result)
					return false;
				else 
				    result = n & 1;
				n = n >> 1;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Power_of_Two_Model GetTestData001(void)
		{
			Power_of_Two_Model result;
			result.n = 1;			
			return result;//expect : true
		};
		/// <summary>
		/// ���ո��2
		/// </summary>   
		Power_of_Two_Model GetTestData002(void)
		{
			Power_of_Two_Model result;
			result.n = 16;			
			return result;//expect : true
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Power_of_Two_Model GetTestData002(void)
		{
			Power_of_Two_Model result;
			result.n = 3;
			return result;//expect : false
		};
#pragma endregion TestData
	};
}