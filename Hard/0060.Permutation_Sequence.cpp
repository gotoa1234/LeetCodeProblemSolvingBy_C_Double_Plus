#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

namespace Solution60
{
#pragma region Paste to execute 
	/*
	#include "0060.Permutation_Sequence.cpp"
	using namespace Solution60;
	using namespace std;

	int main()
	{
		Solution60::Permutation_Sequence useClass;
		Solution60::Permutation_Sequence::Permutation_Sequence_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.getPermutation(getTestModel.n, getTestModel.k);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.getPermutation(getTestModel.n, getTestModel.k);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.getPermutation(getTestModel.n, getTestModel.k);
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 取得指定位置的排列組合
	/// </summary>
	class Permutation_Sequence
	{
#pragma region Model
	public:
		class Permutation_Sequence_Model
		{
		public:
			int n;
			int k;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 
		///       Runtime：0 ms Beats 100 %
		/// Memory Usage ：6 MB Beats 52.14 %
		/// </summary>	
		string getPermutation(int n, int k) {
			//1-1. 0! = 1 , 1! = 1 ... 先找出所有階層
			const int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
			vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
			string result;
			//1-2. 加快string使用，配置記憶體
			result.reserve(n);
			numbers.resize(n);

			//2. 準備工作，首次是用 (n - 1)! 運算，並且 k-1
			int factorial;
			k = k - 1;

			//3. 進行n次計算找出每個字元
			while (n--)
			{
				//3-1. 假設第一次就會得到 k / (n-1)! 的位置  ※while進來時n 會判斷，然後減1
				factorial = factorials[n];
				int offset = k / factorial;
				//3-2. 取得該位置的值
				result += to_string(numbers[offset]);
				//3-3. 移除加入的值
				numbers.erase(numbers.begin() + offset);
				//4. 查找下一個值 				
				k %= factorial;
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Permutation_Sequence_Model GetTestData001(void)
		{
			Permutation_Sequence_Model result;
			result.n = 3;
			result.k = 3;
			return result;//except: "213"
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Permutation_Sequence_Model GetTestData002(void)
		{
			Permutation_Sequence_Model result;
			result.n = 4;
			result.k = 9;
			return result;//except:  "2314"
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Permutation_Sequence_Model GetTestData003(void)
		{
			Permutation_Sequence_Model result;
			result.n = 3;
			result.k = 1;
			return result;//except:  "123"
		};
#pragma endregion TestData

	};
}

/*
以下是此題規則解，當n=5 有以下排列，
                發現規則1 : 當 n=5 時 1~5 每個數字有24個剛好為4!
                            因此可以類推，當n=X 時，每個數字有 (X-1)! 
                找出位置  : 第25個位置 21345 若把第一個位置2取出後，可以知道剩下 1345
                            再將剩下的的k 進行下一層 (X-2)! 直到 (X-n) = 0;
                  
 1   12345
     12354
     12435
     12453
     12534
     12543
     13245
     13254
     13425
     13452
     13524
     13542
     14235
     14253
     14325
     14352
     14523
     14532
     15234
     15243
     15324
     15342
     15423
24   15432
     21345
     21354
     21435
     21453
     21534
     21543
     23145
     23154
     23415
     23451
     23514
     23541
     24135
     24153
     24315
     24351
     24513
     24531
     25134
     25143
     25314
     25341
     25413
48   25431
     31245
     31254
     31425
     31452
     31524
     31542
     32145
     32154
     32415
     32451
     32514
     32541
     34125
     34152
     34215
     34251
     34512
     34521
     35124
     35142
     35214
     35241
     35412
72   35421
     41235
     41253
     41325
     41352
     41523
     41532
     42135
     42153
     42315
     42351
     42513
     42531
     43125
     43152
     43215
     43251
     43512
     43521
     45123
     45132
     45213
     45231
     45312
96   45321
     51234
     51243
     51324
     51342
     51423
     51432
     52134
     52143
     52314
     52341
     52413
     52431
     53124
     53142
     53214
     53241
     53412
     53421
     54123
     54132
     54213
     54231
     54312
120  54321


*/