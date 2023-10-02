#include <unordered_map>
#include "Easy\0509.Fibonacci_Number.cpp"
using namespace Solution509;

int main()
{
    Solution509::Fibonacci_Number useClass;
    Solution509::Fibonacci_Number::Fibonacci_Number_Model getTestModel = useClass.GetTestData001();
    int result = useClass.fib_ResolveHash(getTestModel.n);

    getTestModel = useClass.GetTestData002();
    result = useClass.fib_ResolveHash(getTestModel.n);

    getTestModel = useClass.GetTestData003();
    result = useClass.fib_ResolveHash(getTestModel.n);
    return 0;
}