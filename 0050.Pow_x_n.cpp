#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution50
{
#pragma region Paste to execute 
	/*
	#include "0050.Pow_x_n.cpp"
	using namespace Solution50;
	using namespace std;

	int main()
	{

		Solution50::Pow_x_n useClass;
		Solution50::Pow_x_n::Pow_x_n_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.myPow(getTestModel.x, getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.myPow(getTestModel.x, getTestModel.n);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ����x^n
	/// </summary>
	class Pow_x_n
	{
#pragma region Model
	public:
		class Pow_x_n_Model
		{
		public:
			double x;
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G �Q�Ϋ���n���S�� EX: 2��10����
		///                - �i� 2��"8"���譼�H 2��"2"����A�� "" ��_�Ӫ��a��ۥ[�N�O n = 10
		///                - ����n�2��"8" ����O�A�]��"8"�i�H�ݦ� 2��"4"���� ���H 2��4���� 
		///                ���^�Ӭ�
		///                           2^8
		///                     2^4    *    2^4
		///                  2^2 * 2^2   2^2 * 2^2
		///               =    2*2*2*2 * 2*2*2*2 
		///                 �i�N�Ҧ���n �2������ ���W�D2���誺���ơA�Y�i�D��
		///                 time : O(nlogn) 
		///                �����D�� O(n) �|����
		///       Runtime�G
		/// Memory Usage �G
		/// </summary>	
		double myPow(double x, int n) {
			double result = 1.0;
			for (int index = n; index != 0; index = index / 2)
			{
				if (index % 2 != 0)
					result *= x;
				x *= x;
			}
			return n < 0 ? 1 / result : result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Pow_x_n_Model GetTestData001(void)
		{
			Pow_x_n_Model result;
			result.x = 2.00000;
			result.n = 24;
			return result;//except:1024.00000
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Pow_x_n_Model GetTestData002(void)
		{
			Pow_x_n_Model result;
			result.x = 2.10000;
			result.n = 3;
			return result;//except:9.26100
		};

		/// <summary>
		/// test data 3
		/// </summary>   
		Pow_x_n_Model GetTestData003(void)
		{
			Pow_x_n_Model result;
			result.x = 2.00000;
			result.n = -2;
			return result;//except:2-2 = 1/22 = 1/4 = 0.25
		};

		/// <summary>
		/// test data 4
		/// </summary>   
		Pow_x_n_Model GetTestData004(void)
		{
			Pow_x_n_Model result;
			result.x = 1.00000;
			result.n = 2147483647;
			return result;//except:1  ����for�j��w�ҹ�W��
		};

		/// <summary>
		/// test data 5
		/// </summary>   
		Pow_x_n_Model GetTestData005(void)
		{
			Pow_x_n_Model result;
			result.x = 0.44528;
			result.n = 0;
			return result;//except:1 
		};


#pragma endregion TestData

	};
}
