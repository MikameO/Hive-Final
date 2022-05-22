#include <iostream>
#include <vector>

#include "Commander.h"
#include "Hive.h"
#include "Scenario.h"
#include "structs.h"
#include "Task.h"
#include "Worker.h"

#include "test_cmd.h"
#include "test_hive.h"
#include "test_scen.h"
#include "test_task.h"
#include "test_work.h"

int main(){

	cout << "\n\n#######################\n\n";

	test_cmd();

	cout << "\n\n#######################\n\n";

	test_hive();

	cout << "\n\n#######################\n\n";

	test_scen();

	cout << "\n\n#######################\n\n";

	test_work();

	cout << "\n\n#######################\n\n";

	test_task();

	cout << "\n\n#######################\n\n";
	int i;

	cin >> i;

	return 0;
	
}