#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution15
{
#pragma region Paste to execute 
	/*
	#include "0015.3Sum.cpp"
	using namespace Solution15;
	using namespace std;

	int main()
	{
		Solution15::Three_Sum useClass;
		Solution15::Three_Sum::Three_Sum_Model getTestModel = useClass.GetTestData001();
		vector<vector<int>> result = useClass.ThreeSum(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		result = useClass.ThreeSum(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		result = useClass.ThreeSum(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �̪��@�Ϋe��
	/// </summary>
	class Three_Sum
	{
#pragma region Model
	public:
		class Three_Sum_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�ƧǡA�M��M���N�̥��䪺�ƭ�(0)�T�w�A�M��N(1)�P�̫��(nums.size())�A�T�Ӭۥ[�A�Y���G�p��0 �N(1) -> (2);�Y�j��0�h
		///                (nums.size() -1) ���ɮɹM���_�I��(1) ......���ƫ���o���G
		///      Runtime:   128 ms, faster than 64.67% of C++ online submissions for 3Sum.
		/// Memory Usage : 19.8 MB,   less than 95.65% of C++ online submissions for 3Sum.
		/// </summary>
		vector<vector<int>> ThreeSum(vector<int>& nums) {
			vector<vector<int>> result;
			int leftIndex = 0;
			int rightIndex = 0;
			int middleValue = 0;
			int rightValue = 0;
			int numsMax = nums.size();
			//1. �Ƨ�
			sort(nums.begin(), nums.end());
			//2. �M��
			for (int index = 0; index < numsMax; index++)
			{
				//3.��ܨ���I(�̥��B�̥k)
				leftIndex = index + 1;
				rightIndex = numsMax - 1;

				//��涰�ɸ��X
				while (leftIndex < rightIndex)
				{
					middleValue = nums[leftIndex];
					rightValue = nums[rightIndex];
					if (nums[index] + middleValue + rightValue == 0)
					{
						//���ɰ�����
						result.push_back({ nums[index] ,middleValue , rightValue });

						//�H�U�O��X�ۦP�ƭȮɩ��k�P����
						int tempMiddleValue = nums[leftIndex];
						int tempRightValue = nums[rightIndex];
						while (leftIndex < rightIndex && nums[leftIndex] == tempMiddleValue)
							leftIndex++;
						while (rightIndex > 0 && nums[rightIndex] == tempRightValue)
							rightIndex--;
					}
					else if (nums[index] + middleValue + rightValue < 0)//�p��0�A���k���ƭ��ܤj�A�ͪ�0
						leftIndex++;
					else//�j��0�A�������ƭ��ܤp�A�ͪ�0
						rightIndex--;
				}
				//�H�U�O��X�_�I�ۦP�ƭȮɩ��k
				while (index + 1 < numsMax && nums[index + 1] == nums[index])
					index++;
			}
			return result;
		}		
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Three_Sum_Model GetTestData001(void)
		{
			Three_Sum_Model result;
			result.nums = { -1,0,1,2,-1,-4 };
			return result;//except: [[-1,-1,2],[-1,0,1]]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Three_Sum_Model GetTestData002(void)
		{
			Three_Sum_Model result;
			result.nums = { 0,1,1 };
			return result;//expect: []
		};

		/// <summary>
	    /// ���ո��3
	    /// </summary>   
		Three_Sum_Model GetTestData003(void)
		{
			Three_Sum_Model result;
			result.nums = { 0,0,0 };
			return result;//expect: [[0,0,0]]
		};
#pragma endregion TestData

	};
}