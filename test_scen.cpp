#include "test_scen.h"

using namespace std;

void test_scen(){

	cout << Hive::workers_num;

	Hive hv;

	hv.create_workers(10);

	cout << "" << "\n";
	
	Scenario sc;
	cout << Hive::workers_num << " \n";
	sc.create_tasks(10);
	sc.status();
	hv.set_scenario(&sc);
	cout << sc.get_tasks().size() << " task in queue \n";
	hv.set_queue(&sc);
	cout << sc.get_tasks().size() << " task in queue after processing\n";
	sc.status();
}