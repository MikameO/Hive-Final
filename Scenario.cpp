#include "Scenario.h"

int Scenario::task_num = 0; // overall amount of tasks
int Scenario::abort_num = 0; //aborted
int Scenario::fin_num = 0; //finished

Scenario::Scenario(){
	this->name = rand();
	task_queue = {};
}

void Scenario::add_task(Task* t){
	this->task_queue.push_back(t);
}

void Scenario::status(){
	printf("Number of aborted tasks: %d \n", Scenario::abort_num);
	printf("Number of finished tasks: %d \n", Scenario::fin_num);
	printf("Number of tasks: %d \n", Scenario::task_num);
}

void Scenario::create_tasks(int n){
	Area a;
	for(int i=0; i<n; i++){

		a.x1 = rand();
		a.x2 = rand();
		a.y1 = rand();
		a.y2 = rand();
		this->task_queue.push_back(new Task);
		this->task_queue[i]->set_name();
		this->task_queue[i]->set_exec_time(rand());
		this->task_queue[i]->set_coords(a);
		this->task_queue[i]->set_amount(rand());
	}
	Scenario::task_num += n;
}

vector <Task*> Scenario::get_tasks()
{
	return task_queue;
}

void Scenario::set_tasks(vector <Task*> task_q)
{
	task_queue.clear();
	for (int i = 0; i < task_q.size(); i++) {
		task_queue.push_back(task_q[i]);
	}
}