#include "0045.Jump_Game_II.cpp"
using namespace Solution45;
using namespace std;

int main()
{
	int result = 0;
	Solution45::Jump_Game_II useClass;
	Solution45::Jump_Game_II::Jump_Game_II_Model getTestModel = useClass.GetTestData001();
	result = useClass.jump(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	result = useClass.jump(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	result = useClass.jump(getTestModel.nums);
	return 0;
}