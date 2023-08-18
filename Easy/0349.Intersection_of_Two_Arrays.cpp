#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

namespace Solution349
{
#pragma region Paste to execute 
	/*
	#include <vector>
	#include "Easy\0349.Intersection_of_Two_Arrays.cpp"
	using namespace Solution349;

	int main()
	{
		Solution349::Intersection_of_Two_Arrays useClass;
		Solution349::Intersection_of_Two_Arrays::Intersection_of_Two_Arrays_Model getTestModel = useClass.GetTestData001();
		int result = useClass.reverseVowels(getTestModel.s);

		getTestModel = useClass.GetTestData002();
		result = useClass.reverseVowels(getTestModel.s);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ��Ӱ}�C���涰
	/// </summary>
	class Intersection_of_Two_Arrays
	{
#pragma region Model
	public:
		class Intersection_of_Two_Arrays_Model
		{
		public:
			vector<int> nums1;
			vector<int> nums2;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///           Think�G���T�ذ򥻸Ѫk
		///                  1. �}�X1001 �D�ؽd�򪺤j�p�A�M��M���}�C�аO�s�b�A�M��A�M���t�@�Ӱ}�C��X����
		///                  2. HashTable���������ƶ��ءA�M��M���t�Ӱ}�C��X����
		///                  3. �ƧǨ�Ӱ}�C�A�M��b�M����X����
		///        Runtime :  3 ms Beats 90.69 %
		///   Memory Usage :9.9 MB Beats 93.17 %
		/// <returns></returns>
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			//��1�ظѪk
			vector<bool> isUse(1001, false);
			for (int index = 0; index < nums1.size(); index++)			
				isUse[nums1[index]] = true;			

			vector<int> result{};
			for (int index = 0; index < nums2.size(); index++)
			{
				if (isUse[nums2[index]])
				{
					result.push_back(nums2[index]);
					isUse[nums2[index]] = false;
				}
			}
			return result;
		}

		/* �Ѫk2 :       Runtime:    3 ms Beats 90.69% 
		            Memory Usage: 10.3 MB Beats 45.60%
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			return (nums1.size() < nums2.size()) ? GetResult(nums1, nums2)
				: GetResult(nums2, nums1);
		}

		vector<int> GetResult(vector<int>& numsFew, vector<int>& numsMany)
		{
			vector<int> result{};
			unordered_map<int, int> hashTable;
			for (int index = 0; index < numsFew.size(); index++)
			{
				hashTable[numsFew[index]]++;
			}

			for (int index = 0; index < numsMany.size(); index++)
			{
				if (hashTable.find(numsMany[index]) != hashTable.end())
				{
					result.push_back(numsMany[index]);
					hashTable.erase(numsMany[index]);
				}
			}
			return result;
		}
		*/

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Intersection_of_Two_Arrays_Model GetTestData001(void)
		{
			Intersection_of_Two_Arrays_Model result;
			result.nums1 = { 1,2,2,1 };
			result.nums2 = {2,2};
			return result;//expect:[2]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Intersection_of_Two_Arrays_Model GetTestData002(void)
		{
			Intersection_of_Two_Arrays_Model result;
			result.nums1 = { 4,9,5 };
			result.nums2 = { 9,4,9,8,4 };
			return result;//expect:[4,9]
		};


#pragma endregion TestData
	};
}