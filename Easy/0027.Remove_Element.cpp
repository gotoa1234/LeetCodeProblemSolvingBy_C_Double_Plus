#include <iostream>
#include <vector>
using namespace std;

namespace Solution27
{
#pragma region Paste to execute 
	/*
    #include "0027.Remove_Element.cpp"
    using namespace Solution27;
    using namespace std;
    
    int main()
    {
    	Solution27::Remove_Element useClass;
    	Solution27::Remove_Element::Remove_Element_Model getTestModel = useClass.GetTestData001();
    	int result = useClass.removeElement(getTestModel.nums, getTestModel.val);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.removeElement(getTestModel.nums, getTestModel.val);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 移除元素
	/// </summary>
	class Remove_Element
	{
#pragma region Model
	public:
		class Remove_Element_Model
		{
		public:
			vector<int> nums;
			int val;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：遍歷，並且使用一個索引變數，每當有發現時索引變數+1，在設定值時依照當前位置-索引位置設定值
		///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Remove Element.
		/// Memory Usage : 8.6 MB,   less than  99.70% of C++ online submissions for Remove Element.
		/// </summary>
		int removeElement(vector<int>& nums, int val) {
			int moveIndex = 0;
			for (int index = 0; index < nums.size(); index++)
			{
				if (val == nums[index])
					moveIndex++;
				else
					nums[index - moveIndex] = nums[index];
			}
			return nums.size() - moveIndex;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Remove_Element_Model GetTestData001(void)
		{
			Remove_Element_Model result;
			result.nums = { 1 };
			result.val =1;
			return result;//except: 2  nums = [2,2,_,_]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Remove_Element_Model GetTestData002(void)
		{
			Remove_Element_Model result;
			result.nums = { 0,1,2,2,3,0,4,2 };
			result.val = 2;
			return result;//expect:5  nums = [0,1,4,0,3,_,_,_]
		};
#pragma endregion TestData

	};
}