#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution17
{
#pragma region Paste to execute 
	/*
    #include "0017.Letter_Combinations_of_a_Phone_Number.cpp"
    using namespace Solution17;
    using namespace std;
    
    int main()
    {
    	Solution17::Three_Sum_Closet useClass;
    	Solution17::Three_Sum_Closet::Letter_Combinations_of_a_Phone_Number_Model getTestModel = useClass.GetTestData001();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	getTestModel = useClass.GetTestData002();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	getTestModel = useClass.GetTestData003();
    	vector<string> result = useClass.letterCombinations(getTestModel.digits);
    
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �q�ܸ��X���r���զX
	/// </summary>
	class Three_Sum_Closet
	{
#pragma region Model
	public:
		class Letter_Combinations_of_a_Phone_Number_Model
		{
		public:
			string digits;
		};
#pragma endregion Model

#pragma region Main
	public:
		/*
		1 2 3
		4 5 6
		7 8 9
		  0 

        -- �Ʀr(�W)�P�r������(�U) --

		 ""     "abc"  "def"
		 "ghi"  "jkl"  "mno"
		 "pqrs" "tuv"  "wxyz"
		        ""
		*/

		/// <summary>
		///          ����G�إߤ@�ӹ�����A�M��z�L���j�N�C�Ӧr�����ƦC�զX�զ����@�t�C���G
		///       Runtime :   0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
		///  Memory Usage : 6.6 MB,   less than 53.96 % of C++ online submissions for Letter Combinations of a Phone Number.
		/// </summary>
		

		vector<string> _mapping = { "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> letterCombinations(string digits) {
			vector<string> result;

			return result;
		}
		void Combination(string inputDigits, string msg, vector<string>& result)
		{
			if (inputDigits.empty())
			{
				if (!msg.empty())
					result.emplace_back(msg);
			}
			else
			{ 
				for (int index = 0; index < _mapping[inputDigits[0] - 49].size(); index++)
				{
					Combination(inputDigits.substr(1), msg + _mapping[inputDigits[0] - 49][index], result);
				}
			}
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Letter_Combinations_of_a_Phone_Number_Model GetTestData001(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "23";
			return result;//except: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Letter_Combinations_of_a_Phone_Number_Model GetTestData002(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "";
			return result;//expect: []
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Letter_Combinations_of_a_Phone_Number_Model GetTestData003(void)
		{
			Letter_Combinations_of_a_Phone_Number_Model result;
			result.digits = "2";
			return result;//expect: ["a","b","c"]
		};
#pragma endregion TestData

	};
}