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
	/// ���o���w��m���ƦC�զX
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
		///     thinking�G 
		///       Runtime�G0 ms Beats 100 %
		/// Memory Usage �G6 MB Beats 52.14 %
		/// </summary>	
		string getPermutation(int n, int k) {
			//1-1. 0! = 1 , 1! = 1 ... ����X�Ҧ����h
			const int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
			vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
			string result;
			//1-2. �[��string�ϥΡA�t�m�O����
			result.reserve(n);
			numbers.resize(n);

			//2. �ǳƤu�@�A�����O�� (n - 1)! �B��A�åB k-1
			int factorial;
			k = k - 1;

			//3. �i��n���p���X�C�Ӧr��
			while (n--)
			{
				//3-1. ���]�Ĥ@���N�|�o�� k / (n-1)! ����m  ��while�i�Ӯ�n �|�P�_�A�M���1
				factorial = factorials[n];
				int offset = k / factorial;
				//3-2. ���o�Ӧ�m����
				result += to_string(numbers[offset]);
				//3-3. �����[�J����
				numbers.erase(numbers.begin() + offset);
				//4. �d��U�@�ӭ� 				
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
�H�U�O���D�W�h�ѡA��n=5 ���H�U�ƦC�A
                �o�{�W�h1 : �� n=5 �� 1~5 �C�ӼƦr��24�ӭ�n��4!
                            �]���i�H�����A��n=X �ɡA�C�ӼƦr�� (X-1)! 
                ��X��m  : ��25�Ӧ�m 21345 �Y��Ĥ@�Ӧ�m2���X��A�i�H���D�ѤU 1345
                            �A�N�ѤU����k �i��U�@�h (X-2)! ���� (X-n) = 0;
                  
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