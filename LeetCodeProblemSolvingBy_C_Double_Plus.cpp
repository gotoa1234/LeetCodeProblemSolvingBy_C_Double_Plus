#include "Easy\0551.Student_Attendance_Record_I.cpp"
using namespace Solution551;

int main()
{
	Solution551::Student_Attendance_Record_I useClass;
	Solution551::Student_Attendance_Record_I::Student_Attendance_Record_I_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.checkRecord(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.checkRecord(getTestModel.s);
}