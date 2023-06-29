#include <unordered_map>
#include "Medium/0189.Rotate_Array.cpp"
using namespace Solution189;

int main()
{
	Solution189::Rotate_Array useClass;
	Solution189::Rotate_Array::Rotate_Array_Model getTestModel = useClass.GetTestData001();
	useClass.rotate(getTestModel.nums, getTestModel.k);

	getTestModel = useClass.GetTestData002();
	useClass.rotate(getTestModel.nums, getTestModel.k);
	return 0;
}