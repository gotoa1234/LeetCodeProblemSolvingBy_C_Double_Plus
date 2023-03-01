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
	/// �˴��� 
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
		///          ����G �M���˴����A��X
		///                1. �P�_�O�_�i�إ߰j��
		///                2. �P�_�̫᪺�˴������ަ�m
		///       Runtime :   128 ms Beats 13.70 %
		///  Memory Usage : 108.7 MB Beats  5.85 %
		/// </summary>
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int summary = 0;
			int station = 0; 
			int currentGas = 0;
			int temp = 0;
			//1. �M���˴���
			for (int index = 0; index < gas.size(); index++) 
			{
				//2. summary�p��A�̫�p��0��ܤ��i��j��
				temp = gas[index] - cost[index];
				summary += temp;
				//3. ��e�˴��q�A�Y�p��0��ܷs���˴����b�U�@�ӯ��ަ�m
				currentGas += temp;
				if (currentGas < 0) {
					station = index + 1;
					currentGas = 0;
				}
			}
			return (summary < 0) ? -1 : station;
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
