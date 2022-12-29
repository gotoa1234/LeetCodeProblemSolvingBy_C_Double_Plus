#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution31
{
#pragma region Paste to execute 
	/*
	#include "0031.Next_Permutation.cpp"
	using namespace Solution31;
	using namespace std;

	int main()
	{
		Solution31::Next_Permutation useClass;
		Solution31::Next_Permutation::Next_Permutation_Model getTestModel = useClass.GetTestData001();
	    useClass.nextPermutation(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		useClass.nextPermutation(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		useClass.nextPermutation(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �U�@�ӹw�����ƦC�զX
	/// </summary>
	class Next_Permutation
	{
#pragma region Model
	public:
		class Next_Permutation_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:


		/* �i�Q��for�j�� + next_permutation(nums.begin(), nums.end()); ��X�H�U���Ǫ��ƦC�զX
            1 , 2 , 3 , 4
            1 , 2 , 4 , 3
            1 , 3 , 2 , 4
            1 , 3 , 4 , 2
            1 , 4 , 2 , 3
            1 , 4 , 3 , 2
            2 , 1 , 3 , 4
            2 , 1 , 4 , 3
            2 , 3 , 1 , 4
            2 , 3 , 4 , 1
            2 , 4 , 1 , 3
            2 , 4 , 3 , 1
            3 , 1 , 2 , 4
            3 , 1 , 4 , 2
            3 , 2 , 1 , 4
            3 , 2 , 4 , 1
            3 , 4 , 1 , 2
            3 , 4 , 2 , 1
            4 , 1 , 2 , 3
            4 , 1 , 3 , 2
            4 , 2 , 1 , 3
            4 , 2 , 3 , 1
            4 , 3 , 1 , 2
            4 , 3 , 2 , 1
        */
		/// <summary>
		///          ����G�D�N���ƦC�զX�A��X�U�@�ӲզX�����ءA�H�W����1,2,3,4 ����J�A��X�N�n1,2,4,3
		///                �i�H�Q�θӱƦC���޿�
		///                Condition 1�G 5, 4, 3, 2, 1 ���w 1, 2, 3, 4, 5
		///                              �q�᩹�e�� - ��X�p���@�ӼƭȪ�����
		///                              �q�᩹�e�� - ��X�j��nums[anchorIndex] �ƭȪ�����
		///                Condition 2�G �û��N anchorIndex �P replaceIndex ���ƭȹﴫ
		///                Condition 3�G �û��N anchorIndex ���᪺�ƭȰ��˧ǱƧ�
		///      Runtime :    0 ms Beats   100 %
		/// Memory Usage :   12 MB Beats 74.75 % 
		/// </summary>
		void nextPermutation(vector<int>& nums) {
			int numsCount = nums.size();
			int anchorIndex;//�q�᩹�e�� - ��X�p���@�ӼƭȪ�����
			int replaceIndex;//�q�᩹�e�� - ��X�j��nums[anchorIndex] �ƭȪ�����
			//��X�O�_���W or ����
			for (anchorIndex = numsCount - 2; anchorIndex >= 0; anchorIndex--)
			{
				if (nums[anchorIndex] < nums[anchorIndex + 1]) {
					break;
				}
			}

			//1. �S����� EX: 5, 4, 3, 2, 1 ���w 1, 2, 3, 4, 5
			if (anchorIndex < 0)
				reverse(nums.begin(), nums.end());
			else
			{
				//2-1 ��X�j��nums[anchorIndex] �ƭȪ�����
				for (replaceIndex = numsCount - 1; replaceIndex > anchorIndex; replaceIndex--)
				{
					if (nums[replaceIndex] > nums[anchorIndex])
						break;
				}
				//2-2 �û��N anchorIndex �P replaceIndex ���ƭȹﴫ
				swap(nums[anchorIndex], nums[replaceIndex]);
				//2-3 �û��N anchorIndex ���᪺�ƭȰ��˧ǱƧ�
				reverse(nums.begin() + anchorIndex + 1, nums.end());
			}
		}

		/// <summary>
		/// �����N�O��{�H�U���y�k
		/// </summary>
		/// <param name="nums"></param>
		void nextPermutation_cPlusPlusFunction(vector<int>& nums) {
			next_permutation(nums.begin(), nums.end());
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Next_Permutation_Model GetTestData001(void)
		{
			Next_Permutation_Model result;
			result.nums = { 3 , 4 , 1 , 2 };
			return result;//except: {3 , 4 , 2 , 1}
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Next_Permutation_Model GetTestData002(void)
		{
			Next_Permutation_Model result;
			result.nums = { 3 , 4 , 2 , 1 };
			return result;//except: {4 , 1 , 2 , 3}
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Next_Permutation_Model GetTestData003(void)
		{
			Next_Permutation_Model result;
			result.nums = { 4 , 3 , 2 , 1 };
			return result;//except: {1 , 2 , 3 , 4}
		};
#pragma endregion TestData
	};
}