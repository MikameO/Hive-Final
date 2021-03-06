#include "test_work.h"
#include "Hive.h"
#include "Task.h"
#include "Scenario.h"

using namespace std;

void test_work(){

	Hive hv;

	hv.create_workers(100000);

	Commander* cmd1 = hv.promote();
	Commander* cmd2 = hv.promote();

	cout << &hv << " " << cmd1->get_hive() << "\n";
	cout << &hv << " " << cmd2->get_hive() << "\n";

	Scenario sc;
	sc.create_tasks(100);

	cmd1->add_worker(50000);
	cmd2->add_worker(rand());

	cmd1->set_task(sc.get_tasks()[0]);

	cout << cmd1->get_task()->get_amount() << "\n";

	cmd1->start_task();
	cmd2->add_worker(hv.get_unassigned().size());

	cout << cmd1->get_workers()[0]->get_X() << "\n";

	cmd1->rnd_move(sc.get_tasks()[0]->get_Area());

	cout << cmd1->get_workers()[0]->get_X() << "\n";

	cmd1->get_workers()[0]->w_log();

	cout << cmd1-> get_workers()[0]->get_log()[cmd1->get_workers()[0]->get_log().size() - 1]->Y - cmd1->get_workers()[0]->get_Y() << " is it null? \n";

	cmd1->rnd_move(sc.get_tasks()[0]->get_Area());

	cmd1->get_workers()[0]->w_log();

	cout << cmd1->get_workers()[0]->get_log()[cmd1->get_workers()[0]->get_log().size() - 1]->Y - cmd1->get_workers()[0]->get_Y() << " is it null? \n";

	cmd1->rnd_move(sc.get_tasks()[0]->get_Area());

	cmd1->get_workers()[0]->w_log();

	cout << cmd1->get_workers()[0]->get_log()[cmd1->get_workers()[0]->get_log().size() - 1]->Y - cmd1->get_workers()[0]->get_Y() << " is it null? \n";

	cmd1->rnd_move(sc.get_tasks()[0]->get_Area());

	cmd1->get_workers()[0]->w_log();

	printf("It finally works!!!  NICEEEEE");

	delete cmd1;
	delete cmd2; // works down to here

}