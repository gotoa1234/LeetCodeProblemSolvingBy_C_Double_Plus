#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution53
{
#pragma region Paste to execute 
	/*
	#include "0053.Maximum_Subarray.cpp"
	using namespace Solution53;
	using namespace std;

	int main()
	{

		Solution53::Maximum_Subarray useClass;
		Solution53::Maximum_Subarray::Maximum_Subarray_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.maxSubArray(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maxSubArray(getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �̤j���l�}�C �ƭ�
	/// ���@�Ӱ}�C�̭����s�򤸯��[�`�O�̤j�� EX: [3,4,-5,6]  0-1 ���ƭ�(7)�[�`�O�Ӱ}�C�̤j
	/// </summary>
	class Maximum_Subarray
	{
#pragma region Model
	public:
		class Maximum_Subarray_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G 
		///       Runtime�G
		/// Memory Usage �G
		/// </summary>	
		int maxSubArray(vector<int>& nums) {
			return 0;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Maximum_Subarray_Model GetTestData001(void)
		{
			Maximum_Subarray_Model result;
			result.nums = { -2,1,-3,4,-1,2,1,-5,4 };
			return result;//except: 6
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Maximum_Subarray_Model GetTestData002(void)
		{
			Maximum_Subarray_Model result;
			result.nums = { 1 };
			return result;//except: 1
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Maximum_Subarray_Model GetTestData003(void)
		{
			Maximum_Subarray_Model result;
			result.nums = { 5,4,-1,7,8 };
			return result;//except: 23
		};
#pragma endregion TestData

	};
}
