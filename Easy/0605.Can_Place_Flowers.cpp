#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution605
{
#pragma region Paste to execute 
	/*
	#include "Easy\0605.Can_Place_Flowers.cpp"
	using namespace Solution605;

	int main()
	{
		Solution605::Can_Place_Flowers useClass;
		Solution605::Can_Place_Flowers::Can_Place_Flowers_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.canPlaceFlowers(getTestModel.flowerbed, getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.canPlaceFlowers(getTestModel.flowerbed, getTestModel.n);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 罐頭場的花群
	/// </summary>
	class Can_Place_Flowers
	{
#pragma region Model
	public:
		class Can_Place_Flowers_Model
		{
		public:
			vector<int> flowerbed;
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :算出1與1之間0的連續數量K的 (k-1)/2 加總，並且對頭尾為0的狀況添加0，當結果大於等於n時為True		
		///       Runtime :   8 ms Beats 88.60 %
		///  Memory Usage :20.6 MB Beats 33.12 %
		/// </summary>
		bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			int ablePot = 0;
			if (flowerbed[flowerbed.size() - 1] == 0)
				flowerbed.push_back(0);
			if (flowerbed[0] == 0)
				flowerbed.insert(flowerbed.begin() + 0, 0);
			for (int index = 0; index < flowerbed.size(); index++)
			{
				if (1 == flowerbed[index])
					continue;
				int total = 0;
				int potIndex = index;
				for (;index < flowerbed.size(); index++)
				{
					if (flowerbed[index] == 1)
						break;
				}
				total += (index - potIndex - 1) / 2;
				ablePot += total;
			}
			return ablePot >= n;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Can_Place_Flowers_Model GetTestData001(void)
		{
			Can_Place_Flowers_Model result;
			result.flowerbed = { 1, 0, 0, 0 ,1 };
			result.n = 1;			
			return result;//expect : true
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Can_Place_Flowers_Model GetTestData002(void)
		{
			Can_Place_Flowers_Model result;
			result.flowerbed = { 1, 0, 0, 0 ,1 };
			result.n = 2;
			return result;//expect : false
		};

#pragma endregion TestData
	};
}