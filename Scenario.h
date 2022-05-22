#pragma once

class Task;
class Hive;

class Scenario{

	char name;
	vector <Task*> task_queue
	
public:
	static int task_num; // overall amount of tasks
	static int abort_num; //aborted
	static int del_num; //delayed 
	static int fin_num; //finished
	void set_tasks(Task*);
	void status();
	void create_tasks(int);
	
	Scenario();
	
};