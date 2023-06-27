#include <unordered_map>
#include "Easy/0338.Counting_Bits.cpp"
using namespace Solution338;

int main()
{

	using namespace std;

	Solution338::Counting_Bits useClass;
	Solution338::Counting_Bits::Counting_Bits_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.countBits(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.countBits(getTestModel.n);
}