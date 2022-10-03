#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution11
{
#pragma region Paste to execute 
	/*
	#include "0011.Container_With_Most_Water.cpp"
	using namespace Solution11;
	using namespace std;

	int main()
	{
		Solution11::Container_With_Most_Water useClass;
		Solution11::Container_With_Most_Water::Container_With_Most_Water_Model getTestModel = useClass.GetTestData001();
		int result = useClass.maxArea(getTestModel.height);

		getTestModel = useClass.GetTestData002();
		result = useClass.maxArea(getTestModel.height);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �e�������̤j��n
	/// </summary>
	class Container_With_Most_Water
	{
#pragma region Model
	public:
		class Container_With_Most_Water_Model
		{
		public:
			vector<int> height;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�إ̥߳�(left)�P�̥k(right) ���ޡA�C���� �p�Ȫ����� * �Z��(right- left) �A�C�������̤j���ȡA
		///                ����left �j��right ���X��ܵ��G
		///      Runtime : Runtime 93  ms Beats	96.85 %
		/// Memory Usage : Memory 58.7 MB Beats	99.89 %
		/// </summary>
		int maxArea(vector<int>& height) {
			int left = 0;
			int right = height.size() - 1;
			int maxResult = 0;
			int selectMin = 0;
			while (left < right)
			{
				selectMin = min(height[left], height[right]);
				maxResult = max(maxResult, selectMin * (right - left)  );
				
				if (selectMin == height[left])
					left++;
				else
					right--;
			}
			return maxResult;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Container_With_Most_Water_Model GetTestData001(void)
		{
			Container_With_Most_Water_Model result;
			result.height = { 1,8,6,2,5,4,8,3,7 };
			return result;//except: 49
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Container_With_Most_Water_Model GetTestData002(void)
		{
			Container_With_Most_Water_Model result;
			result.height = { 1,1 };
			return result;//expect: 1
		};
#pragma endregion TestData
	};
}