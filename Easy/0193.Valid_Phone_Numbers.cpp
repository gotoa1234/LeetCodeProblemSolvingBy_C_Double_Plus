#include <iostream>
using namespace std;

namespace Solution193
{
#pragma region Paste to execute 
	/*
	*/
#pragma endregion Paste to executes

	/// <summary>
	/// Τ筿杠腹絏
	/// </summary>
	class Valid_Phone_Numbers
	{
#pragma region Model
	public:
		class Valid_Phone_Numbers_Model
		{
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         隔 肈ヘ璶―ノBash粂猭
		///      Runtime : 91 ms					
		/// Memory Usage : 3.1 MB						
		/// </summary>
		/// <returns></returns>        
		void file()
		{
			/*弧
			- o 块で皌ゅセぃㄤず甧
			- w で皌场才
			- e ﹚才﹃暗琩тゅンず甧妓Α
			1. 钡帝玡琿"" ず甧琌タ玥笷で皌硂家Αノで皌"123 456-7890"ゅセ︽ㄤい玡琌计ぇ琌ぇ琌计㎝硈才程琌计
			2. 钡帝琿"" 琌タ玥笷で皌硂家Αノで皌"123-456-7890"ゅセ︽ㄤい玡琌计ぇ琌硈才ぇ琌计㎝硈才程琌计
			狦骸ì1. 2. 穦块 file.txt い
			*/

			/* Bash粂猭			
			grep -o -w -e "^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" -o -w -e "^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" file.txt
			grep -o -w -e "^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" -o -w -e "^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$" file.txtz
			*/
		}
	public:
#pragma endregion Main
		/* 肈ヘ
		987-123-4567
        123 456 7890
        (123) 456-7890
		*/

		/* 块 Τ硂ㄢ才
		987-123-4567
        (123) 456-7890
		*/
	};
}