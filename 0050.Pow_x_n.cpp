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
		auto result1 = useClass.myPow(getTestModel.x, getTestModel.y);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.myPow(getTestModel.x, getTestModel.y);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// «ü¼Æx^n
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
		///     thinking¡G 
		///                
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>	
		double myPow(double x, int n) {
			return {};
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
			result.n = 10;
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

#pragma endregion TestData

	};
}
