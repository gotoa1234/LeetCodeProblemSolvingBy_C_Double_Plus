#include "0035.Search_Insert_Position.cpp"
using namespace Solution35;
using namespace std;

int main()
{
	int result = 0;
	Solution35::Search_Insert_Position useClass;
	Solution35::Search_Insert_Position::Search_Insert_Position_Model getTestModel = useClass.GetTestData001();
	result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.searchInsert(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData004();
	result = useClass.searchInsert(getTestModel.nums, getTestModel.target);
	return 0;
}