#include "test_hive.h"

using namespace std;

void test_hive(){

	Hive hv;

	hv.create_workers(100000);

	Commander* cmd1 = hv.promote();
	Commander* cmd2 = hv.promote();

	cout << hv.get_amount_w() << " get_amount_w()\n";

	cout << hv.get_c_scenario() << " get_c_scenario()\n";

	cout << hv.get_unassigned().size() << " get_unassigned().size()\n";

	Scenario sc;
	sc.create_tasks(100);

	hv.set_scenario(&sc);

	hv.set_queue(hv.get_c_scenario());

	cout << hv.get_c_scenario() << " get_c_scenario()\n";

	// other methods were checked in test_cmd test

}