#pragma once
#include "Worker.h"
#include "structs.h"

class Commander;
class Worker;
class Scenario;
class Task;

class Hive{

	vector <Commander*> cmds; // active high level commanders
	vector <Worker*> unassigned_workers; // free workers
	Scenario* current_scenario;
	
public:
	Scenario* get_c_scenario(); //get current scenario
	
	void upd_hier(); // update hierarchy
	
	void predict_abort(); // create list of abortion
	
	void task_daemon();
	
	void assing_cmd(Task*, Commander*);
	
	void set_scenario(Scenario*);
	void create_workers(int);
	void set_queue(Scenario*);
	void send_queue(Scenario*);
	
	void add_worker(Worker*);
	
	Commander* promote();
	
	Hive();
	
};