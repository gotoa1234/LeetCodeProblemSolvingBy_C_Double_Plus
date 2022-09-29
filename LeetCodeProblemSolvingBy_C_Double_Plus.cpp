#include "0027.Remove_Element.cpp"
using namespace Solution27;
using namespace std;

int main()
{
	Solution27::Remove_Element useClass;
	Solution27::Remove_Element::Remove_Element_Model getTestModel = useClass.GetTestData001();
	int result = useClass.removeElement(getTestModel.nums, getTestModel.val);

	getTestModel = useClass.GetTestData002();
	result = useClass.removeElement(getTestModel.nums, getTestModel.val);

	return 0;
}