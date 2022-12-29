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
		auto result1 = useClass.maxSubArray(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maxSubArray(getTestModel.nums);
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
		///     thinking�G �i�H�Q�Τ��n�k�A�C���B��N�W�������G���U��
		///                �H������ { -2,1,-3,4,-1,2,1,-5,4 }
		///                  Step 1:  (-2 + 1) �P 1  ���Ӥj?  ����[1] �� 1�j�A�ҥH�O�d���� [1] ����m
		///                  Step 2:  (1  + -3) �P -3 ���Ӥj?  �ۥ[��-2�j�A�ҥH�O�d���� [2] ����m
		///                  Step 3:  (-2 +  4) �P 4 ���Ӥj?  ����[3] �� 4�j�A�ҥH�O�d���� [3] ����m
		///                  Loop  :  ����̫�@�ӯ��޴N�O�̤j��
		///       Runtime�G 143 ms Beats 80.78 %
		/// Memory Usage �G67.6 MB Beats 90.92 %
		/// </summary>	
		int maxSubArray(vector<int>& nums) {
			int calculationValue = nums[0];
			int maxResult = calculationValue;
			for (int index = 1; index < nums.size(); index++)
			{
				calculationValue = max(calculationValue + nums[index], nums[index]);
				maxResult = max(calculationValue, maxResult);
			}
			return maxResult;
		}

		/// <summary>
		/// �ʺA�W����
		///       Runtime�G 123 ms Beats 90.57 %
		/// Memory Usage �G70.5 MB Beats  5.30 %
		/// </summary>
		/// <returns></returns>
		int maxSubArray_DpSolve(vector<int>& nums) {
			vector<int> dp(nums.size());
			dp[0] = nums[0];
			int maxResult = dp[0];
			for (int index = 1; index < nums.size(); index++)
			{
				dp[index] = max(dp[index - 1] + nums[index], nums[index]);
				maxResult = max(dp[index], maxResult);
			}
			return maxResult;
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
