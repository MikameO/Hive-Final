#pragma once
#include "structs.h"

class Worker;
class Commander;

class Commander: public Worker{	
	
	Task* task;
	vector <Worker*> workers;
	
public:
	void set_task(Task*);
	
	void start_task();
	
	void add_worker(int); //add certain amount of workers if possible
	
	void rnd_move(Area); // randomly distribute workers in given Area
	
	Commander();
	~Commander(); // create worker on commander destruction
	
	void get_amount(); // get number of working units
	
};