#include "0278.First_Bad_Version.cpp"
using namespace Solution278;
using namespace std;


int main()
{
	Solution278::First_Bad_Version useClass;
	Solution278::First_Bad_Version::First_Bad_Version_Model getTestModel = useClass.GetTestData001();
	useClass._badVersion = getTestModel.bad;
	int result = useClass.firstBadVersion(getTestModel.n);

	getTestModel = useClass.GetTestData003();
	useClass._badVersion = getTestModel.bad;
	result = useClass.firstBadVersion(getTestModel.n);

	return 0;
}
