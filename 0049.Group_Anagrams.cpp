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
	/// �s�զr��
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
		///     thinking�G �Ѫk1 - �Q��HashTable + �ƧǦr��Ѥp��j time: O(N) ~ O(2N)
		///                1. �M���@���A�Ƨǫ᪺�r���iHashTable ���s����
		///                2. �A�M���@���A�NHashTable�������G��i vector<vector<string>> ���A��X
		///       Runtime�G  31 ms Beats 98.16 %
		/// Memory Usage �G19.5 MB Beats 85.28 %
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
		///     thinking�G �Ѫk2 - �q�`�į�n: �Q��HashTable + �ƧǦr��Ѥp��j (�u�M���@��) time:O(N)
		///                1. �Ƨǫ᪺�r�ꤣ�s�bHashTable ���A��ܥi�طs���s	
		///                2. �Ƨǫ᪺�r��s�bHashTable ���A�h��H�إߪ��s��X��J (�o��Τ@���ܼƬ������ަ�m�A�åB�ӯ��ެOHashTable��Key)
		///       Runtime�G  31 ms Beats 98.16 %
		/// Memory Usage �G19.4 MB Beats 90.12 %
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
