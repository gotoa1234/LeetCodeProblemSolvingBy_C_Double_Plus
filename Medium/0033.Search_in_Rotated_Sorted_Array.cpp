#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution33
{
#pragma region Paste to execute 
	/*
	#include "0033.Search_in_Rotated_Sorted_Array.cpp"
	using namespace Solution33;
	using namespace std;

	int main()
	{
	Solution33::Search_in_Rotated_Sorted_Array useClass;
	Solution33::Search_in_Rotated_Sorted_Array::Search_in_Rotated_Sorted_Array_Model getTestModel = useClass.GetTestData001();
	int result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData004();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData005();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData006();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData007();
	result = useClass.search(getTestModel.nums, getTestModel.target);
	return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �b����ƧǼƲդ��j��
	/// </summary>
	class Search_in_Rotated_Sorted_Array
	{
#pragma region Model
	public:
		class Search_in_Rotated_Sorted_Array_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G ����ƧǪ��W�h�O�Ѥp��j�A�]���Q�ΤG���j�M�k���ήɡC 
		///                ����Ƥ��ΡA���ɧP�_����O�Ѥp��j�A�٬O�k�䬰�Ѥp��j
		///                �p�GTarget���b�Ѥp��j������A���w�O�b�t�@��
		///                �Y�G���j�M��᳣̫�S���A���Target���s�b �^��-1
		///      Runtime�G    3 ms Beats 91.18 %
		///Memory Usage �G 11.1 MB Beats 74.94 %
		/// </summary>
		int search(vector<int>& nums, int target) {
			int leftIndex = 0;
			int rightIndex = nums.size() - 1;

			while (leftIndex <= rightIndex)
			{
				//1. �C������������
				int mid = (leftIndex + rightIndex) / 2;

				if (nums[mid] == target)
					return mid;
				else if (nums[leftIndex] <= nums[mid])//2-1. �p�G������ �j�� �����
				{
					//2-1-1. �ؼЦb���b��
					if (nums[leftIndex] <= target &&
						target < nums[mid])
					{
						rightIndex = mid - 1;
					}
					else//2-1-2. �ؼЦb�k�b��
					{
						leftIndex = mid + 1;
					}
				}
				else//2-2. ������ �p�� ����� ����ܤ����ȳB�b���त
				{
					//2-2-1. �ؼЦb�k�b��
					if (nums[mid] < target &&
						target <= nums[rightIndex])
					{
						leftIndex = mid + 1;
					}
					else//2-2-2. �ؼЦb���b��
					{
						rightIndex = mid - 1;
					}
				}
			}
			return -1;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Search_in_Rotated_Sorted_Array_Model GetTestData001(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 4,5,6,7,0,1,2 };
			result.target = 1;
			return result;//except: 4
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Search_in_Rotated_Sorted_Array_Model GetTestData002(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 4,5,6,7,0,1,2 };
			result.target = 3;
			return result;//except: -1
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Search_in_Rotated_Sorted_Array_Model GetTestData003(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 1 };
			result.target = 0;
			return result;//except: -1
		};

		/// <summary>
		/// test data 4
		/// </summary>        
		Search_in_Rotated_Sorted_Array_Model GetTestData004(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 1, 3, 5 };
			result.target = 1;
			return result;//except: 0
		};

		/// <summary>
		/// test data 5
		/// </summary>        
		Search_in_Rotated_Sorted_Array_Model GetTestData005(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 1, 3};
			result.target = 2;
			return result;//except: -1
		};

		/// <summary>
		/// test data 6
		/// </summary>        
		Search_in_Rotated_Sorted_Array_Model GetTestData006(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 3, 1 };
			result.target = 1;
			return result;//except: 1
		};

		/// <summary>
		/// test data 7
		/// </summary>        
		Search_in_Rotated_Sorted_Array_Model GetTestData007(void)
		{
			Search_in_Rotated_Sorted_Array_Model result;
			result.nums = { 4,5,6,7,0,1,2 };
			result.target = 2;
			return result;//except: 6
		};
#pragma endregion TestData

	};
}