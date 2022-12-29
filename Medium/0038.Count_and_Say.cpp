#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution38
{
#pragma region Paste to execute 
	/*
	#include "0038.Count_and_Say.cpp"
	using namespace Solution38;
	using namespace std;

	int main()
	{
	    string result = "";
		Solution38::Count_and_Say useClass;
		Solution38::Count_and_Say::Count_and_Say_Model getTestModel = useClass.GetTestData001();
		result = useClass.countAndSay(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		result = useClass.countAndSay(getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 計算"說"的數字
	/// ※題意: 已確定 n = 1 的時候是 "1"
	///         當n = 2 時看到 n = 1 的 "1"    要說成 1個1       所以 n = 2 答案是 "11"
	///         當n = 3 時看到 n = 2 的 "11"   要說成 2個1       所以 n = 3 答案是 "21"
	///         當n = 4 時看到 n = 3 的 "21"   要說成 1個2與1個1 所以 n = 4 答案是 "1211"
	///         當n = 5 時看到 n = 4 的 "1211" 要說成 1個1與1個2與2個1 所以 n = 5 答案是 "111221"
	/// </summary>
	class Count_and_Say
	{
#pragma region Model
	public:
		class Count_and_Say_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 遞迴解，由f(1) = "1" 為開頭，逐步取得解
		///       Runtime：  3 ms Beats 94.21%
		/// Memory Usage ：7.1 MB Beats 33.02%
		/// </summary>
		unordered_map<int, string> _dpHashMap;
		string countAndSay(int n) {
			_dpHashMap[1] = "1";
			auto result = FindSayCount(n);
			return result;
		}
	private:
		string FindSayCount(int n)
		{
			if (_dpHashMap.find(n) != _dpHashMap.end())
			{
				return _dpHashMap[n];
			}
			else
			{
				string getMessage = FindSayCount(n - 1);							
				string iSay = "";
				int count = 1;
				//f(n) 解析 f(n-1) 的字串，並且組成 f(n) 的解
				for (int index = 0; index < getMessage.size(); index++)
				{
					//走到邊界可離開
					if (index + 1 == getMessage.size())
					{
						iSay.push_back(count + 48);
						iSay.push_back(getMessage[index]);
						count == 1;
						break;
					}
					else
					{
						//當前字元與下一字元不同，可以重計
						if (getMessage[index + 1] != getMessage[index])
						{
							iSay.push_back(count + 48);
							iSay.push_back(getMessage[index]);
							count = 1;
						}
						else
						{
							//累計數值
							count++;
						}
					}
				}
				_dpHashMap[n] = iSay;
				return iSay;
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Count_and_Say_Model GetTestData001(void)
		{
			Count_and_Say_Model result;
			result.n = 1;
			return result;//except: "1"
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Count_and_Say_Model GetTestData002(void)
		{
			Count_and_Say_Model result;
			result.n = 5;
			return result;//except: "1211"
		};
#pragma endregion TestData

	};
}