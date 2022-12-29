#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution45
{
#pragma region Paste to execute 
	/*
	#include "0045.Jump_Game_II.cpp"
	using namespace Solution45;
	using namespace std;

	int main()
	{
		int result = 0;
		Solution45::Jump_Game_II useClass;
		Solution45::Jump_Game_II::Jump_Game_II_Model getTestModel = useClass.GetTestData001();
		result = useClass.jump(getTestModel.num1, getTestModel.num2);

		getTestModel = useClass.GetTestData002();
		result = useClass.jump(getTestModel.num1, getTestModel.num2);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 铬臘笴栏-2
	/// </summary>
	class Jump_Game_II
	{
#pragma region Model
	public:
		class Jump_Game_II_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking 砱褒簍衡猭–˙计常ǐ筂т程环禯瞒
		///                Time O(n)
		///       Runtime  12 ms Beats 97.89 %
		/// Memory Usage 16.5 MB Beats 96.53 %
		/// </summary>	
		int jump(vector<int>& nums) {
			int resultStep = 0;//魁羆˙计
			int last = 0;//˙计程竚
			int current = 0;//讽玡竚
			for (int index = 0; index < nums.size() - 1; index++)
			{
				//–Ωт程
				current = max(current, nums[index] + index);
				if (last == index)//狦笿Ω程ボ惠˙计┕钡玡秈
				{
					resultStep++;
					last = current;
					if (current >= nums.size() - 1)
						break;
				}
			}
			return resultStep;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Jump_Game_II_Model GetTestData001(void)
		{
			Jump_Game_II_Model result;
			result.nums = { 2,3,1,1,4 };
			return result;//except: 2
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Jump_Game_II_Model GetTestData002(void)
		{
			Jump_Game_II_Model result;
			result.nums = { 2,3,0,1,4 };
			return result;//except: 2
		};

		Jump_Game_II_Model GetTestData003(void)
		{
			Jump_Game_II_Model result;
			result.nums = { 2,3,2,5,4,8,2,1,5 };
			return result;//except: 3			
		};
#pragma endregion TestData

	};
}
