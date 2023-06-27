#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution338
{
#pragma region Paste to execute 
	/*
#include <unordered_map>
#include "Easy/0338.Counting_Bits.cpp"
using namespace Solution338;

int main()
{

	using namespace std;

	Solution338::Counting_Bits useClass;
	Solution338::Counting_Bits::Counting_Bits_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.countBits(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.countBits(getTestModel.n);
}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �p��bit��
	/// </summary>
	class Counting_Bits
	{
#pragma region Model
	public:
		class Counting_Bits_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ��� :�Q�μƾǪ��W�߸Ѧ��D�A�b��J��1���ɭԻݶi��2^0�ӥH�e���Ҧ��ƭ�+1 (�u�� [0])
		///                                      �b��J��2���ɭԻݶi��2^1�ӥH�e���Ҧ��ƭ�+1 ([0], [1])
		///                �G�i��    ��Jn   �һݭ��ƪ��ƶq
		///                    0        0
		///                   01        1 --- 2^0
		///                   10        2
		///                   11        3 --- 2^1
		///                  100        4
		///                  101        5
		///                  110        6  
		///                  111        7 --- 2^2 
		///                 1000        8   
		///       Runtime :  3 ms Beats 96.69 %
		///  Memory Usage :7.7 MB Beats	88.75 %
		/// </summary>
		vector<int> countBits(int n)
		{
            vector<int> result(n + 1, 0);			
			//1. �]�w2�i��
			int binary = 0;
			for (int index = 1; index <= n; binary++)
			{
				//2-1. �����p���
				int currentLength = pow(2, binary);
				for (int innerIndex = 0; 
					 innerIndex < currentLength && index <= n; 
					 innerIndex++, index++)
				{
					//2-2. +1
					result[index] = result[innerIndex] + 1;
				}
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Counting_Bits_Model GetTestData001(void)
		{
			Counting_Bits_Model result;
			result.n = 2;
			return result;//expect : [0,1,1]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Counting_Bits_Model GetTestData002(void)
		{
			Counting_Bits_Model result;
			result.n = 5;
			return result;//expect: [0,1,1,2,1,2]
		};
#pragma endregion TestData
	};
}