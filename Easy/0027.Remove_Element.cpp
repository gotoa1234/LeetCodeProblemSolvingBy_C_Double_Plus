#include <iostream>
#include <vector>
using namespace std;

namespace Solution27
{
#pragma region Paste to execute 
	/*
    #include "Easy\0027.Remove_Element.cpp"
    using namespace Solution27;
    using namespace std;
    
    int main()
    {
    	Solution27::Remove_Element useClass;
    	Solution27::Remove_Element::Remove_Element_Model getTestModel = useClass.GetTestData001();
    	auto result = useClass.removeElement(getTestModel.nums, getTestModel.val);
    
    	getTestModel = useClass.GetTestData002();
    	auto result2 = useClass.removeElement(getTestModel.nums, getTestModel.val);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ��������
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
		///         ����G�M���A�åB�ϥΤ@�ӯ����ܼơA�C���o�{�ɯ����ܼ�+1�A�b�]�w�Ȯɨ̷ӷ�e��m-���ަ�m�]�w��
		///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Remove Element.
		/// Memory Usage : 8.6 MB,   less than  99.70% of C++ online submissions for Remove Element.
		/// </summary>
		int removeElement(vector<int>& nums, int val) {
			int recordIndex = 0;
			for (int index = 0; index < nums.size(); index++)
			{
				if (nums[index] != val)
				{
					nums[recordIndex] = nums[index];
					recordIndex++;
				}
			}
			return recordIndex;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Remove_Element_Model GetTestData001(void)
		{
			Remove_Element_Model result;
			result.nums = { 3,2,2,3 };
			result.val = 3;
			return result;//except: 2  nums = [2,2,_,_]
		};

		/// <summary>
		/// ���ո��2
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