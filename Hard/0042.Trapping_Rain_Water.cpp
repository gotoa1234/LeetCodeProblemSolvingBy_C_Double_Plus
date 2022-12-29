#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution42
{
#pragma region Paste to execute 
	/*
    #include "0042.Trapping_Rain_Water.cpp"
    using namespace Solution42;
    using namespace std;
    
    int main()
    {
    	int result = 0;
    	Solution42::Trapping_Rain_Water useClass;
    	Solution42::Trapping_Rain_Water::Trapping_Rain_Water_Model getTestModel = useClass.GetTestData001();
    	result = useClass.trap(getTestModel.height);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.trap(getTestModel.height);
    	return 0;
    }

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 區間內的雨水容積
	/// </summary>
	class Trapping_Rain_Water
	{
#pragma region Model
	public:
		class Trapping_Rain_Water_Model
		{
		public:
			vector<int> height;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 本題有多解
		///       Runtime：  24 ms Beats 74.58 %
		/// Memory Usage ：19.8 MB Beats 81.68 %
		/// </summary>
		
		/// <summary>
		/// thinking：Time: O(n) Space:O(1) 
		///           由最左與最右兩個索引，每次比較值，較小的會向對方縮進(left 會遞增，right會遞減)
		///           若是height 比上次小，表示可以累加水容積，但如果內縮時高度變高，則不可加水容積
		/// </summary>		
		int trap(vector<int>& height) {
			int leftIndex = 0;
			int rightIndex = height.size() - 1;
			int waterVolume = 0;
			int getUseIndex = 0;
			int getUseHeight = 0;
			int maxHeight = 0;
			while (leftIndex < rightIndex)
			{
				getUseIndex = height[leftIndex] < height[rightIndex] ? leftIndex++ : rightIndex--;
				getUseHeight = height[getUseIndex];
				maxHeight = max(maxHeight, getUseHeight);
				waterVolume += maxHeight - getUseHeight;
			}
			return waterVolume;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Trapping_Rain_Water_Model GetTestData001(void)
		{
			Trapping_Rain_Water_Model result;
			result.height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
			return result;//except: 6
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Trapping_Rain_Water_Model GetTestData002(void)
		{
			Trapping_Rain_Water_Model result;
			result.height = { 4,2,0,3,2,5 };

			return result;//except: 5
		};
#pragma endregion TestData

	};
}
