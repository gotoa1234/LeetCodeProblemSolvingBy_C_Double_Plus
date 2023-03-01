#include <iostream>
#include <vector>
using namespace std;

namespace Solution134
{
#pragma region Paste to execute 
	/*
	#include "Medium\0134.Gas_Station.cpp"
	using namespace Solution134;
	using namespace std;

	int main()
	{
		Solution134::Gas_Station useClass;
		Solution134::Gas_Station::Gas_Station_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);

		getTestModel = useClass.GetTestData003();
        auto result3 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¥Ë´µ¯¸ 
	/// </summary>
	class Gas_Station
	{
#pragma region Model
	public:
		class Gas_Station_Model
		{
		public:
			vector<int> gas;
			vector<int> cost;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          «ä¸ô¡G 		
		///       Runtime : 
		///  Memory Usage : 
		/// </summary>
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int totalGas = 0; 
			int total_cost = 0;
			int starting_station = 0; int curr_gas = 0;
			for (int i = 0; i < gas.size(); i++) {
				totalGas += gas[i];
				total_cost += cost[i];
				curr_gas += gas[i] - cost[i];
				if (curr_gas < 0) {
					starting_station = i + 1;
					curr_gas = 0;
				}
			}
			return (totalGas < total_cost) ? -1 : starting_station;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Gas_Station_Model GetTestData001(void)
		{
			Gas_Station_Model result;
			result.gas = { 1, 2, 3, 4, 5 };
			result.cost ={ 3, 4, 5, 1, 2 };
			return result;//expect:3
		}

		/// <summary>
		/// test 2
		/// </summary>   
		Gas_Station_Model GetTestData002(void)
		{
			Gas_Station_Model result;
			result.gas = { 2, 3, 4  };
			result.cost = { 3, 4, 3 };
			return result;//expect:-1
		};

		/// <summary>
        /// test 3
        /// </summary>   
		Gas_Station_Model GetTestData003(void)
		{
			Gas_Station_Model result;
			result.gas = { 5, 1, 2, 3, 4 };
			result.cost ={ 4, 4, 1, 5, 1 };
			return result;//expect:4
		};
#pragma endregion TestData
	};
}
