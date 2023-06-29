#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

namespace Solution189
{
#pragma region Paste to execute 
	/*
    #include <unordered_map>
    #include "Medium/0189.Rotate_Array.cpp"
    using namespace Solution189;
    
    int main()
    {
    	Solution189::Rotate_Array useClass;
    	Solution189::Rotate_Array::Rotate_Array_Model getTestModel = useClass.GetTestData001();
    	useClass.rotate(getTestModel.nums, getTestModel.k);
    
    	getTestModel = useClass.GetTestData002();
    	useClass.rotate(getTestModel.nums, getTestModel.k);
    	return 0;
    }
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// ����}�C
	/// </summary>
	class Rotate_Array
	{
#pragma region Model
	public:
		class Rotate_Array_Model
		{
		public:
			vector<int> nums;
			int k;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         ����G�Q�Ψ�W�� 
		///               EX: k=2 nums ={1,2,3,4,5,6,7} => �w��{6, 7 ,1, 2, 3, 4, 5}
		///  step1 :  {1, 2, 3, 4, 5} ���� => {5, 4, 3, 2, 1}
		///  step2 :  {6, 7} ���� => {7, 6}
		///  step3 :  {5, 4, 3, 2, 1, 7, 6} ���� => {6, 7, 1, 2, 3, 4, 5}
		///      Runtime�G  25 ms Beats 96.93 %
		/// Memory Usage�G24.9 MB Beats 88.86 %
		/// </summary>
		/// <returns></returns>
	public:
		void rotate(vector<int>& nums, int k) {
			//���b�A����k�i�Q�㰣�����p�U(����)
			if (nums.empty() || (k %= nums.size()) == 0) 
				return;
			int lastStartIndex = nums.size() - k;
			reverse(nums.begin(), nums.begin() + lastStartIndex);
			reverse(nums.begin() + lastStartIndex, nums.end());
			reverse(nums.begin(), nums.end());
		}
	public:
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Rotate_Array_Model GetTestData001(void)
		{
			Rotate_Array_Model result;
			result.k = 2;
		    result.nums = { 1, 2, 3, 4, 5, 6, 7 };
			return result;//expect: [5,6,7,1,2,3,4]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Rotate_Array_Model GetTestData002(void)
		{
			Rotate_Array_Model result;
			result.k = 2;
			result.nums = { -1,-100,3,99 };
			return result;//expect: [3,99,-1,-100]
		};

		/// <summary>
	    /// test 2
	    /// </summary>   
		Rotate_Array_Model GetTestData002(void)
		{
			Rotate_Array_Model result;
			result.k = 2;
			result.nums = { -1 };
			return result;//expect: [-1]
		};

#pragma endregion TestData
	};
}