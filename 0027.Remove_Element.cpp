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
		int result = useClass.removeDuplicates(getTestModel.nums, getTestModel.val);

		getTestModel = useClass.GetTestData002();
		result = useClass.removeDuplicates(getTestModel.nums, getTestModel.val);
		
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
		///         思路：
		///               
		///      Runtime: 
		///Memory Usage : 
		/// </summary>
		int removeElement(vector<int>& nums, int val) {
			return 0;
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
			result.nums = { 3,2,2,3 };
			return result;//except: 2  nums = [2,2,_,_]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Remove_Element_Model GetTestData002(void)
		{
			Remove_Element_Model result;
			result.nums = { 0,1,2,2,3,0,4,2 };
			return result;//expect:5  nums = [0,1,4,0,3,_,_,_]
		};
#pragma endregion TestData

	};
}