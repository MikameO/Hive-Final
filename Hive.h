#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"
#include "Commander.h"
#include "Scenario.h"
#include "Task.h"
#include "structs.h"

using namespace std;

class Commander;
class Worker;
class Scenario;
class Task;

class Hive{

	vector <Commander*> cmds; // active high level commanders
	vector <Worker*> unassigned_workers; // free workers
	Scenario* current_scenario;
	
public:

	static int workers_num;

	Scenario* get_c_scenario(); //get current scenario
	
	void upd_hier(Commander*, Commander*); // update hierarchy
	
	void predict_abort(Task*); // create list of abortion
	
	void assign_cmd(Task*, Commander*);
	
	int get_amount_w();
	
	void set_scenario(Scenario*);
	void create_workers(int);
	void set_queue(Scenario*);

	void add_workers(vector <Worker*>); // to the unassigned_workers vectur

	vector <Worker*> get_unassigned(); // get vector unassigned workers

	Worker* add_worker();
	
	Commander* promote();

	void demote(Commander*);
	
};