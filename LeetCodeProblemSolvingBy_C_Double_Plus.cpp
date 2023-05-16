#include "Easy\0283.Move_Zeroes.cpp"
using namespace Solution283;
using namespace std;

int main()
{
	Solution283::Move_Zeroes useClass;
	Solution283::Move_Zeroes::Move_Zeroes_Model getTestModel = useClass.GetTestData001();
	useClass.moveZeroes(getTestModel.nums);
	getTestModel = useClass.GetTestData002();
	useClass.moveZeroes(getTestModel.nums);
}