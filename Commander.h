#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"
#include "structs.h"

using namespace std;

class Worker;
class Task;

class Commander: public Worker{	
	
	Task* task;
	vector <Worker*> workers;
	
public:
	void set_task(Task*); // Set current task
	void add_workers(vector <Worker*>); // add some workers from vector
	
	void start_task();
	void finish_task();
	
	void add_worker(int); //add certain amount of workers if possible
	
	void rnd_move(Area); // randomly distribute workers in given Area
	
	Commander();
	~Commander(); // create worker on commander destruction
	
	Task* get_task(); // get current task
	int get_amount(); // get number of working units
	vector <Worker*> get_workers(); // get vector workers

	void clear_workers(); // clear vector workers
	
};