#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution30
{
#pragma region Paste to execute 
	/*
	#include "0030.Substring_with_Concatenation_of_All_Words.cpp"
	using namespace Solution30;
	using namespace std;

	int main()
	{
		Solution30::Substring_with_Concatenation_of_All_Words useClass;
		Solution30::Substring_with_Concatenation_of_All_Words::Substring_with_Concatenation_of_All_Words_Model getTestModel = useClass.GetTestData001();
		vector<int> result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		getTestModel = useClass.GetTestData002();
		result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		getTestModel = useClass.GetTestData003();
		result = useClass.findSubstring(getTestModel.s, getTestModel.words);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出所有陣列中包含的子字串 
	/// ※提供的輸入 words 子字串陣列，每個子字串長度都相同，且要求是不分順序，但有分數量
	/// EX: 輸入 s = acdabcdeab 與 words= {ab, cd}
	///               ----
	///                 ----
	///               符合的位置就有上面-的地方，所以輸出會是 1,3 
	/// </summary>
	class Substring_with_Concatenation_of_All_Words
	{
#pragma region Model
	public:
		class Substring_with_Concatenation_of_All_Words_Model
		{
		public:
			string s;
			vector<string> words;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 此問題較為複雜，從代碼中有註解 findSubstring() 為主函式開始分析
		///      Runtime：   83 ms Beats 87.44 %
		///Memory Usage ： 18.9 MB Beats 87.21 %
		/// </summary>
		
		//全域變數
		unordered_map<string, int> recordMap;//紀錄用的Hash表
		int wordMaxCount;//子字串陣列中的總數量
		int stringUnitLength;//子字串陣列單一字串長度
		
		/// <summary>
		/// 子函式-找出索引位置
		/// </summary>
		void FindIndexPosition(int startIndex, int moveIndex, vector<int>& result, string& inputString) 
		{
			//4. 當前查找到的數量
			int currentCount = 0;
			//5. 開始依照子字串長度做位移查詢
			while (moveIndex + stringUnitLength <= inputString.length()) 
			{
				string subStringItem = inputString.substr(moveIndex, stringUnitLength);

				//5-1. 該子字串符合查找對象
				if (recordMap.count(subStringItem)) 
				{
					//6-1. 若Hash表中還可以扣除，表示符合
					if (recordMap[subStringItem] > 0) 
					{
						recordMap[subStringItem]--;
						currentCount++;
						moveIndex += stringUnitLength;
					}
					else //6-2 假設已扣完該子字串的數量，表示不符合
					{
						//重製recordMap的值，只回滾已處理的值
						while (inputString.substr(startIndex, stringUnitLength) != subStringItem) 
						{ 
							currentCount--; 
							recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
							startIndex += stringUnitLength; 
						}
						startIndex += stringUnitLength;
						moveIndex += stringUnitLength;
					}
				}
				else //5-2. 該子字串不符合
				{
					//重製recordMap的值，只回滾已處理的值
					while (startIndex < moveIndex) 
					{ 
						currentCount--; 
						recordMap[inputString.substr(startIndex, stringUnitLength)]++; 
						startIndex += stringUnitLength; 
					}
					moveIndex += stringUnitLength;
					startIndex += stringUnitLength;
				}

				//7. 如果查找到的數量與子字串數量一致，表示找到了
				if (currentCount == wordMaxCount) 
				{ 
					result.push_back(startIndex); 
				}
			}
		}

		/// <summary>
		/// 主函式-找出所有子字串不分順序
		/// </summary>
		/// <param name="s"></param>
		/// <param name="words"></param>
		/// <returns></returns>
		vector<int> findSubstring(string s, vector<string>& words) {
			//1. 建立預設值
			wordMaxCount = words.size();
			stringUnitLength = words[0].size();
			unordered_map<string, int> hashMap;
			
			//2. 建立預設的Hash表，每個子字串紀錄
			for (int index = 0; index < wordMaxCount; index++)
				hashMap[words[index]]++;			
			
			//3. 遍歷子字串的長度
			vector<int> result;
			for (int index = 0; 
				 index < stringUnitLength; 
				 index++)
			{
				//3-1. 每次新的變化就重製預設的查找紀錄表
				for (auto item : hashMap) 
				{
					recordMap[item.first] = item.second;
				}
				//3-2. 找到的索引位置會直接放進 result中
				FindIndexPosition(index, index, result, s);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Substring_with_Concatenation_of_All_Words_Model GetTestData001(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "barfoothefoobarman";
			result.words = { "foo","bar" };
			return result;//except: [0,9]
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Substring_with_Concatenation_of_All_Words_Model GetTestData002(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "wordgoodgoodgoodbestword";
			result.words = { "word","good","best","word" };
			return result;//expect: []
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Substring_with_Concatenation_of_All_Words_Model GetTestData003(void)
		{
			Substring_with_Concatenation_of_All_Words_Model result;
			result.s = "barfoofoobarthefoobarman";
			result.words = { "bar","foo","the" };
			return result;//expect: [6,9,12]
		};
#pragma endregion TestData

	};
}