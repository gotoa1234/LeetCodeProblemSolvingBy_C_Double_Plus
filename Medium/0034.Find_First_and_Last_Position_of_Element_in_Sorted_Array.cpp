#include <iostream>
#include <vector>
using namespace std;

namespace Solution34
{
#pragma region Paste to execute 
	/*
    #include "0034.Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp"
    using namespace Solution34;
    using namespace std;
    
    int main()
    {
    	Solution34::Find_First_and_Last_Position_of_Element_in_Sorted_Array useClass;
    	Solution34::Find_First_and_Last_Position_of_Element_in_Sorted_Array::Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model getTestModel = useClass.GetTestData001();
    	vector<int> result = useClass.searchRange(getTestModel.nums, getTestModel.target);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.searchRange(getTestModel.nums, getTestModel.target);
    
    	getTestModel = useClass.GetTestData003();
    	result = useClass.searchRange(getTestModel.nums, getTestModel.target);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 在旋轉排序數組中搜索
	/// </summary>
	class Find_First_and_Last_Position_of_Element_in_Sorted_Array
	{
#pragma region Model
	public:
		class Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model
		{
		public:
			vector<int> nums;
			int target;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 利用二分搜尋法找出第一個起點，由此值往左(遞減)往右(遞增) 找出結果
		///      Runtime：    8 ms Beats 89.68 %
		///Memory Usage ： 13.7 MB Beats 64.29 %
		/// </summary>
		vector<int> searchRange(vector<int>& nums, int target) {

			//排除為空的狀況
			if (nums.size() == 0)
				return {-1, -1};

			vector<int> result = {};
			int leftIndex = 0;
			int rightIndex = nums.size() - 1;
			int middleIndex = 0;
			//1. 二分搜尋找出Target的第一個值作為起點
			while (leftIndex <= rightIndex)
			{
				middleIndex = (leftIndex + rightIndex) / 2;
				if (nums[middleIndex] == target)
				{
					//找出第一個起點
					break;
				}
				if (nums[leftIndex] <= target && // nums[leftIndex] <= target 處理最左側邊界問題
					target < nums[middleIndex])
				{
					rightIndex = middleIndex;
				}
				else if (nums[middleIndex] < target &&
					target <= nums[rightIndex]) // target <= nums[rightIndex] 處理最右側邊界問題
				{
					leftIndex = middleIndex + 1;
				}
				//不可能找出值的狀況
				else if(target < nums[leftIndex] ||
					target > nums[rightIndex] ||
					rightIndex == leftIndex)
				{
					return { -1, -1 };
				}
			}

			int searchLeftIndex = middleIndex;
			//2. 由此值往左搜尋
			while (searchLeftIndex > 0 && nums[searchLeftIndex] == nums[searchLeftIndex - 1])
					searchLeftIndex--;
			result.push_back(searchLeftIndex);
		
			//3. 由此值往右搜尋
			while (middleIndex < nums.size() - 1 && nums[middleIndex] == nums[middleIndex + 1])
				middleIndex++;
			result.push_back(middleIndex);
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model GetTestData001(void)
		{
			Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model result;
			result.nums = { 1,4 };
			result.target = 4;
	/*		result.nums = { 5,7,7,8,8,10 };
			result.target = 8;*/
			return result;//except: [3, 4]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model GetTestData002(void)
		{
			Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model result;
			result.nums = { 5,7,7,8,8,10 };
			result.target = 5;
			return result;//except: -1,-1
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model GetTestData003(void)
		{
			Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model result;
			result.nums = {0};
			result.target = 1;
			return result;//except: -1,-1
		};
#pragma endregion TestData

	};
}