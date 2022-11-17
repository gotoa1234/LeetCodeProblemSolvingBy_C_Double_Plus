#include "0061.Rotate_List.cpp"
using namespace Solution61;
using namespace std;

int main()
{
	Solution61::Rotate_List useClass;
	Solution61::Rotate_List::Rotate_List_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.rotateRight(getTestModel.head, getTestModel.k);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.rotateRight(getTestModel.head, getTestModel.k);
	
	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.rotateRight(getTestModel.head, getTestModel.k);

	getTestModel = useClass.GetTestData004();
	auto result4 = useClass.rotateRight(getTestModel.head, getTestModel.k);

	getTestModel = useClass.GetTestData005();
	auto result5 = useClass.rotateRight(getTestModel.head, getTestModel.k);
	return 0;
}