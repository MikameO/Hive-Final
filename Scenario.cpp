#include "Scenario.h"

static int Scenario::task_num = 0; // overall amount of tasks
static int Scenario::abort_num = 0; //aborted
static int Scenario::del_num = 0; //delayed 
static int Scenario::fin_num = 0; //finished

Scenario::Scenario(){
	this->name = rand();
}

void Scenario::set_task(Task* t){
	this->task_queue.push_back(t);
}

void Scenario::status();{
	printf("Number of aborted tasks: %d", Scenario::abort_num);
}

void Scenario::create_tasks(int n){
	for(int i=0; i<n; i++){
		this->task_queue.push_back(new Task);
		this->task_queue[i]->name = rand();
		this->task_queue[i]->exec_time = rand();
		this->task_queue[i]->coords.x1 = rand();
		this->task_queue[i]->coords.y1 = rand();
		this->task_queue[i]->coords.x2 = rand();
		this->task_queue[i]->coords.y2 = rand();
		this->task_queue[i]->amount = rand();
	}
	Scenario::task_num += n;
}