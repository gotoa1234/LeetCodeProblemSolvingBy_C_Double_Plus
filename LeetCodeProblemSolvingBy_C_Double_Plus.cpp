#include "0724.Find_Pivot_Index.cpp"
using namespace Solution724;
using namespace std;

int main()
{
    Solution724::Find_Pivot_Index useClass;
	Solution724::Find_Pivot_Index::Find_Pivot_Index_Model getTestModel = useClass.GetTestData001();
	int result = useClass.pivotIndex(getTestModel.nums);
	getTestModel = useClass.GetTestData002();
	result = useClass.pivotIndex(getTestModel.nums);
	getTestModel = useClass.GetTestData003();
	result = useClass.pivotIndex(getTestModel.nums);
	return 0;
}
