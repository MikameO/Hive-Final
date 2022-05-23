#include "Task.h"
#include <iostream>
using namespace std;

int Task::num_aborted = 0;

Task::Task(){
	
	this->name = rand();
	this->exec_time = rand();
	this->coords.x1 = rand();
	this->coords.y1 = rand();
	this->coords.x2 = rand();
	this->coords.y2 = rand();
	this->amount = rand();
	to_abort = false;
	finished = false;
}

Task::Task(int i, int j, float X1, float X2, float Y1, float Y2, int a)
{
	this->name = i;
	this->exec_time = j;
	this->coords.x1 = X1;
	this->coords.y1 = Y1;
	this->coords.x2 = X2;
	this->coords.y2 = Y2;
	this->amount = a;
	to_abort = false;
	finished = false;
}

Task::Task(int i, int j, int a)
{
	if(a==0){throw runtime_error("No workers needed - not good");}
	this->name = i;
	this->exec_time = j;
	this->coords.x1 = rand();
	this->coords.y1 = rand();
	this->coords.x2 = rand();
	this->coords.y2 = rand();
	this->amount = a;
	to_abort = false;
	finished = false;
}

Task::~Task(){
	
	++num_aborted;
	
}

void Task::set_name()
{
	name = rand() % 256;
}

void Task::set_exec_time(int t)
{
	exec_time = t;
}

void Task::set_coords(Area x)
{
	coords = x;
}

void Task::set_amount(int a)
{
	amount = a;
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
char Task::get_name(){
	return name;
}