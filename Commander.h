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
	void set_task(Task*);
	
	void start_task();
	
	void add_worker(int); //add certain amount of workers if possible
	
	void rnd_move(Area); // randomly distribute workers in given Area
	
	Commander();
	~Commander(); // create worker on commander destruction
	
	int get_amount(); // get number of working units
	
};