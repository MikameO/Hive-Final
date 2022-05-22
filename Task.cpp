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