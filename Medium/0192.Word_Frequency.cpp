#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

namespace Solution192
{
#pragma region Paste to execute 
	/*
	#include <unordered_map>
	#include "Medium/0192.Word_Frequency.cpp"
	using namespace Solution192;

	int main()
	{
		Solution192::Word_Frequency useClass;
		Solution192::Word_Frequency::Word_Frequency_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.findRepeatedDnaSequences(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.findRepeatedDnaSequences(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// ¦rµüÀW²v
	/// </summary>
	class Word_Frequency
	{
#pragma region Model
	public:
		class Word_Frequency_Model
		{
		public:

		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         «ä¸ô¡G
		///      Runtime¡G101 ms Beats 85.69 %
		/// Memory Usage¡G3.7 MB Beats 72.23 %
		/// </summary>
		/// <returns></returns>
	public:
		void file() 
		{
			//# Read from the file words.txtand output the word frequency list to stdout.
			//grep -oE '[a-z]+' words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
		}
	public:
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Word_Frequency_Model GetTestData001(void)
		{
			Word_Frequency_Model result;
			/*
			the day is sunny the the
            the sunny is is
			
			*/
			return result;//expect:
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Word_Frequency_Model GetTestData002(void)
		{
			Word_Frequency_Model result;
			/*
			the 4
            is 3
            sunny 2
            day 1			
			*/
			return result;//expect: 
		};

#pragma endregion TestData
	};
}