#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution41
{
#pragma region Paste to execute 
	/*
	#include "0041.First_Missing_Positive.cpp"
	using namespace Solution41;
	using namespace std;

	int main()
	{
		int result = 0;
		Solution41::First_Missing_Positive useClass;
		Solution41::First_Missing_Positive::First_Missing_Positive_Model getTestModel = useClass.GetTestData001();
		result = useClass.firstMissingPositive(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		result = useClass.firstMissingPositive(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		result = useClass.firstMissingPositive(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �D�Ĥ@�ӯʤ֪����� 
	/// �����ơG�j��0�������
	/// </summary>
	class First_Missing_Positive
	{
#pragma region Model
	public:
		class First_Missing_Positive_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G ���ձM���D�ءA�i�H�q�Q�׹L�{���t�ƥX�̨κt��k
		///      (���ή�)  1.              �w�j�j�M - Time:O(n^2)   Space:O(1)
		///      (���ή�)  2.              �ƧǷj�M - Time:O(nlogn) Space:O(1)
		///                3.            HashTable - Time:O(n)     Space:O(n)
		///                4. ���C(���ϥ�HashTable) - Time:O(n)     Space:O(1)
		///      (���u)    5.        ���C + ���ΰϤ� - Time:O(n)     Space:O(1)
		///       Runtime�G
		/// Memory Usage �G
		/// </summary>
		
		/// <summary>
		///      thinking�GHashTable
		///       Runtime�G	 146 ms Beats 27.59 %
		/// Memory Usage �G 46.7 MB Beats 16.40 %
		/// </summary>
		int firstMissingPositive(vector<int>& nums) {
			unordered_map<int, bool> hashMap;
			int maxValue = 0;
			for (int index = 0; index < nums.size(); index++)
			{
				maxValue = max(maxValue, nums[index]);
				hashMap[nums[index]] = true;
			}

			for (int index = 1; index < nums.size(); index++)
			{
				if (hashMap.find(index) == hashMap.end())
				{
					return index;
				}
			}
			return maxValue == nums.size() ? nums.size() + 1 : nums.size();
		}

		/// <summary>
		///      thinking�G���C(���ϥ�HashTable)
	    ///       Runtime�G   78 ms Beats 74.39 %
		/// Memory Usage �G 31.2 MB Beats 98.80 %
		/// </summary>
		/// <returns></returns>
		int firstMissingPositive_in_place_hashing(vector<int>& nums) {
			int maxLength = nums.size();
			//1. ���M��O(n) �洫�C�ӼƭȨ������index�W
			for (int index = 0; index < maxLength; index++) 
			{
				while (nums[index] >= 0 && //�ư��t��
					   nums[index] < maxLength && //�ư��j�󵥩�}�C���ת����
					   nums[index] != index && //�ư��ۤv�P��e���޼Ʀr�ȬۦP��
					   nums[index] != nums[nums[index]])//�n�洫����H���i�P��e�Ʀr�ۦP
				{
					swap(nums[index], nums[nums[index]]);
				}
			}
			/*
			{ 3,4,-1,1 };
			�� i = 0 ���� nums[0] �P nums[ nums[0] ] �Ĥ@���洫��
			{ 1,4,-1,3};
			�� i = 0 ���� nums[0] �P nums[ nums[0] ] �ĤG���洫��
			{ 4,1,-1,3};
			�� i = 0 ���� nums[0] �P nums[ nums[0] ] �ĤT�����i�洫
			�]��nums[0] �w�g�O4�F�j�󵥩���סA�ҥH���洫

			�� i = 1 ���� nums[1] �P nums[ nums[1] ] �ȬۦP���i�洫
			�� i = 2 ���� nums[2] �S���j�󵥩�0 ���t�ƬG���L
			�� i = 3 ���� nums[3] �P nums[ nums[3] ] �ȬۦP���i�洫
			*/

			//2. Nums�w�洫�����A�C�ӭ������bindex = value �W�A�Y�L��ܸӭȬ��ʤ֪�����
			for (int index = 0; index < maxLength; index++) 
			{
				if (nums[index] != index && index != 0) 
					return index;
			}
			//3. �ư����񺡪����p
			if (nums[0] == maxLength)//EX: [1] Expect: 2
			{
				return maxLength + 1;
			}
			return maxLength;//EX: [0,1,2] Expect: 3
		}

		/// <summary>
		///      thinking�G  ���C + ���ΰϤ� (�t�׳q�`��´��C���)
		///       Runtime�G  62 ms Beats 82.1 %
		/// Memory Usage �G31.2 MB Beats 94.92 %
		/// </summary>
		/// <returns></returns>
		int firstMissingPositive_in_place_hashing_AND_Partition(vector<int>& nums) {
			int maxLength = nums.size();
			for (int index = 0; index < maxLength; index++) {
				if (nums[index] <= 0) {
					nums[index] = maxLength + 1;
				}
			}
			for (int index = 0; index < maxLength; index++) {
				if (abs(nums[index]) <= maxLength) {
					nums[abs(nums[index]) - 1] = -abs(nums[abs(nums[index]) - 1]);
				}
			}
			for (int index = 0; index < maxLength; index++) {
				if (nums[index] > 0) {
					return index + 1;
				}
			}
			return maxLength + 1;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		First_Missing_Positive_Model GetTestData001(void)
		{
			First_Missing_Positive_Model result;	


			result.nums = { 1,2,0};
			return result;//except: 3
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		First_Missing_Positive_Model GetTestData002(void)
		{
			First_Missing_Positive_Model result;
			result.nums = { 3,4,-1,1 };
			
			return result;//except: 2
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		First_Missing_Positive_Model GetTestData003(void)
		{
			First_Missing_Positive_Model result;
			result.nums = { 7,8,9,11,12 };
			return result;//except: 1
		};
#pragma endregion TestData

	};
}