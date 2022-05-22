#include "Task.h"

static int Task::num_aborted = 0;

Task::Task(){
	
	this->name = rand();
	this->exec_time = rand();
	this->coords.x1 = rand();
	this->coords.y1 = rand();
	this->coords.x2 = rand();
	this->coords.y2 = rand();
	this->amount = rand();
	
}

Task::~Task(){
	
	++num_aborted;
	
}

int Task::get_exec_time(){

	return this->exec_time;

}

int Task::get_amount(){

	return this->amount;

}

Area Task::get_Area(){

	return coords;

}