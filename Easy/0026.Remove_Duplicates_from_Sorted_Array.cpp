#include <iostream>
#include <vector>
using namespace std;

namespace Solution26
{
#pragma region Paste to execute 
	/*
	#include "Easy\0026.Remove_Duplicates_from_Sorted_Array.cpp"
	using namespace Solution26;
	using namespace std;

	int main()
	{
		Solution26::Remove_Duplicates_from_Sorted_Array useClass;
		Solution26::Remove_Duplicates_from_Sorted_Array::Remove_Duplicates_from_Sorted_Array_Model getTestModel = useClass.GetTestData001();
		int result = useClass.removeDuplicates(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.removeDuplicates(getTestModel.nums);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �q�ƧǼƲդ��R�����ƶ�
	/// </summary>
	class Remove_Duplicates_from_Sorted_Array
	{
#pragma region Model
	public:
		class Remove_Duplicates_from_Sorted_Array_Model
		{
		public:
			vector<int> nums;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         ����G���b�z���D�ءA�N��O��J���}�C�n�N���P���ƭȥѤp��j��^��J���}�C��
		///               �åB�^�Ǥ@�@���X�Ӥ��P���ƭ�
		///      Runtime:   26 ms, faster than 74.46% of C++ online submissions for Remove Duplicates from Sorted Array.
		///Memory Usage : 18.3 MB,   less than 92.92% of C++ online submissions for Remove Duplicates from Sorted Array.
		/// </summary>
		int removeDuplicates(vector<int>& nums) {
			int total = 1;
			for (int index = 1; index < nums.size(); index++)
			{
				if (nums[index] != nums[index - 1])
					nums[total] = nums[index], total++;
			}
			return total;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Remove_Duplicates_from_Sorted_Array_Model GetTestData001(void)
		{
			Remove_Duplicates_from_Sorted_Array_Model result;
			result.nums = { 1,1,2 };
			return result;//except: 2
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Remove_Duplicates_from_Sorted_Array_Model GetTestData002(void)
		{
			Remove_Duplicates_from_Sorted_Array_Model result;
			result.nums = { 0,0,1,1,1,2,2,3,3,4 };
			return result;//expect:5
		};
#pragma endregion TestData

	};
}