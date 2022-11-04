#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution49
{
#pragma region Paste to execute 
	/*
	#include "0049.Group_Anagrams.cpp"
	using namespace Solution49;
	using namespace std;

	int main()
	{

		Solution49::Group_Anagrams useClass;
		Solution49::Group_Anagrams::Group_Anagrams_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.groupAnagrams(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.groupAnagrams(getTestModel.matrix);

		getTestModel = useClass.GetTestData002();
		auto result3 = useClass.groupAnagrams(getTestModel.matrix);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 群組字謎
	/// </summary>
	class Group_Anagrams
	{
#pragma region Model
	public:
		class Group_Anagrams_Model
		{
		public:
			vector<string> strs;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 解法1 - 利用HashTable + 排序字串由小到大 time: O(N) ~ O(2N)
		///                1. 遍歷一次，排序後的字串放進HashTable 的群集中
		///                2. 再遍歷一次，將HashTable中的結果放進 vector<vector<string>> 中，輸出
		///       Runtime：  31 ms Beats 98.16 %
		/// Memory Usage ：19.5 MB Beats 85.28 %
		/// </summary>	
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> result{};
			unordered_map<string, vector<string>> hashMap;			
			int inde = 0;
			for (int index = 0; index < strs.size(); index ++)
			{
				inde++;
				string origineString = strs[index];
				sort(strs[index].begin(), strs[index].end());
				hashMap[strs[index]].push_back(origineString);
			}
			for (auto item = hashMap.begin(); item != hashMap.end(); item++)
			{
				inde++;
				result.push_back(item->second);
			}
			return result;
		}

		/// <summary>
		///     thinking： 解法2 - 通常效能好: 利用HashTable + 排序字串由小到大 (只遍歷一次) time:O(N)
		///                1. 排序後的字串不存在HashTable 中，表示可建新的群	
		///                2. 排序後的字串存在HashTable 中，則把以建立的群找出塞入 (這邊用一個變數紀錄索引位置，並且該索引是HashTable的Key)
		///       Runtime：  31 ms Beats 98.16 %
		/// Memory Usage ：19.4 MB Beats 90.12 %
		/// </summary>
		/// <param name="strs"></param>
		/// <returns></returns>
		vector<vector<string>> groupAnagrams_solve2(vector<string>& strs) {

			vector<vector<string>> result{};
			unordered_map<string, int> hashTable;
			int searchIndex = 0;
			for (int index = 0; index < strs.size(); index++)
			{
				auto origineStr = strs[index];
				sort(strs[index].begin(), strs[index].end());

				if (hashTable.find(strs[index]) != hashTable.end())
				{
					auto findIndex = hashTable[strs[index]];
					result[findIndex].push_back(origineStr);
				}
				else
				{
					hashTable[strs[index]] = searchIndex;
					vector<string> newGroup;
					newGroup.push_back(origineStr);
					result.push_back(newGroup);
					searchIndex++;
				}
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Group_Anagrams_Model GetTestData001(void)
		{
			Group_Anagrams_Model result;
			result.strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
			return result;//except: {{"bat"},{"nat","tan"},{"ate","eat","tea"}}
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Group_Anagrams_Model GetTestData002(void)
		{
			Group_Anagrams_Model result;
			result.strs = {""};
			return result;//except:{{""}}
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Group_Anagrams_Model GetTestData003(void)
		{
			Group_Anagrams_Model result;
			result.strs = {"a"};
			return result;//except:{{"a"}}
		};

#pragma endregion TestData

	};
}
