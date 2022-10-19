#include "0038.Count_and_Say.cpp"
using namespace Solution38;
using namespace std;

int main()
{
	string result = "";
	Solution38::Count_and_Say useClass;
	Solution38::Count_and_Say::Count_and_Say_Model getTestModel = useClass.GetTestData001();
	result = useClass.countAndSay(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	result = useClass.countAndSay(getTestModel.n);
	return 0;
}
