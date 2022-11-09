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