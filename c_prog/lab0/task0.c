#include <stdio.h>

int main(const int argc, const char* argv[]) {
	char*				name;
	char*				group_name;
	char				num_in_list;
	char*				university_name;
	char*				faculty_name;

	name = "Роман Божко";
	group_name = "TP-02";
	num_in_list = 51;
	university_name = "Київський політехнічний інститут";
	faculty_name = "ТЕФ, АПЕПС";


	printf("%s навчається на %s(%s) в групі %s, де має номер %c\n",
			name, faculty_name, university_name, group_name, num_in_list);

	return 0;
}