#include "0392.Is_Subsequence.cpp"
using namespace Solution392;
using namespace std;

int main()
{


	Solution392::Is_Subsequence useClass;
	Solution392::Is_Subsequence::Is_Subsequence_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isSubsequence(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData002();
	result = useClass.isSubsequence(getTestModel.s, getTestModel.t);
	return 0;
}
