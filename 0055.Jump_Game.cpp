#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution55
{
#pragma region Paste to execute 
	/*
	#include "0055.Jump_Game.cpp"
	using namespace Solution55;
	using namespace std;

	int main()
	{
		Solution55::Jump_Game useClass;
		Solution55::Jump_Game::Jump_Game_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.canJump(getTestModel.nums);

		getTestModel = useClass.GetTestData004();
		auto result4 = useClass.canJump(getTestModel.nums);
		return 0;
	}

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���D�C��
	/// </summary>
	class Jump_Game
	{
#pragma region Model
	public:
		class Jump_Game_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking�G �C���N��e�B�ƥi���̤j�B�Ƨ�s�A�C���@�B����A�Y��U������ nums[Index] �i�H����I��ܥ��T
		///                Time�GO(n)  Space�GO(1)
		///       Runtime�G  63 ms Beats 97.49 %
		/// Memory Usage �G48.3 MB Beats 93.68 %
		/// </summary>	
		bool canJump(vector<int>& nums)
		{
			//1. �|�l�i�γ̤j�B��
			int maxStep = 0;
			//2. O(n) �C���e�@�B�̤j�B�Ʒ|��1�A�������I (nums.size() - 1)�V����
			for (int index = 0, maxStep = 0; index < nums.size() && maxStep > -1; index++, maxStep--)
			{
				//3. �p�G�i���D�Z���W�[�h�i��s�̤j����
				maxStep = max(nums[index], maxStep);
				//4. �P�_��e�B�ƬO�_�i�H��������I
				if (nums[index] + index >= nums.size() - 1)
					return true;
			}
			//�S����k����I
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Jump_Game_Model GetTestData001(void)
		{
			Jump_Game_Model result;
			result.nums = { 2,3,1,1,4 };
			return result;//except: true
		};

		/// <summary>
		/// test data 2
		/// </summary>        
		Jump_Game_Model GetTestData002(void)
		{
			Jump_Game_Model result;
			result.nums = { 3,2,1,0,4 };
			return result;//except: false
		};

		/// <summary>
		/// test data 3
		/// </summary>        
		Jump_Game_Model GetTestData003(void)
		{
			Jump_Game_Model result;
			result.nums = { 2, 0, 0 };
			return result;//except: true
		};

		/// <summary>
		/// test data 4
		/// </summary>        
		Jump_Game_Model GetTestData004(void)
		{
			Jump_Game_Model result;
			result.nums = { 0 };
			return result;//except: true
		};
#pragma endregion TestData

	};
}
