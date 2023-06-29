#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

namespace Solution194
{
#pragma region Paste to execute 
	/*
	#include <unordered_map>
	#include "Medium/0194.Transpose_File.cpp"
	using namespace Solution194;

	int main()
	{
		Solution194::Transpose_File useClass;
		Solution194::Transpose_File::Transpose_File_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.findRepeatedDnaSequences(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.findRepeatedDnaSequences(getTestModel.nums);
		return 0;
	}
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// 轉置文件
	/// </summary>
	class Transpose_File
	{
#pragma region Model
	public:
		class Transpose_File_Model
		{
		public:

		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：
		///   awk : 輸出指令
		///    NF : 橫列
		///    NR : 直行
		/// END{} : 結束指令
		///      Runtime： 85 ms Beats 95.57 %
		/// Memory Usage：3.8 MB Beats 71.43 %
		/// </summary>
		/// <returns></returns>
	public:
		void file()
		{
			//# Read from the file words.txtand output the word frequency list to stdout.
			/*
awk '{
		for (i=1; i<=NF; i++)
		{
		  if(NR==1)
		  {
			res[i]=$i;
		  }
		  else
		  {
			res[i]=res[i] " " $i
		  }
		}
	 }END{
	   for(i=1; i<=NF; i++)
	   {
		 print res[i]
	   }}' file.txt
*/
		}
	public:
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Transpose_File_Model GetTestData001(void)
		{
			Transpose_File_Model result;
			/*
			name age
            alice 21
            ryan 30
			*/
			return result;
			//expect:
			/*
			name alice ryan
            age 21 30
			*/
		};
#pragma endregion TestData
	};
}