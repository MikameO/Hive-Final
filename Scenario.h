#pragma once

#include <iostream>
#include <vector>
#include "Worker.h"
#include "Commander.h"
#include "Task.h"
#include "Hive.h"
#include "structs.h"

using namespace std;

class Task;
class Hive;

class Scenario{

	char name;
	vector <Task*> task_queue;
	
public:
	static int task_num; // overall amount of tasks
	static int abort_num; //aborted
	static int fin_num; //finished
	void add_task(Task*);
	void status();
	void create_tasks(int);

	vector <Task*> get_tasks();
	
	void set_tasks(vector <Task*>);

	Scenario();
	
};