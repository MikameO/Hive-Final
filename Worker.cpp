#include "Worker.h"
#include "Hive.h"

Worker::Worker(){
	
	this->name = rand();
	this->X = 0;
	this->Y = 0;
	this->rot = 0;
	this->cmd = nullptr;
	this->hive = nullptr;
	
}

Worker::~Worker()
{
}

float Worker::get_X(){
	
	return this->X;
	
}

float Worker::get_Y(){
	
	return this->Y;
	
}

float Worker::get_rot(){
	
	return this->rot;
	
}

int Worker::get_num_workers(){
	
	return this->get_hive()->get_amount_w();
	
}

void Worker::set_name()
{
	name = rand()%256;
}

void Worker::set_X(float x){
	
	this->X=x;
	
}

void Worker::set_Y(float y){
	
	this->Y=y;
	
}

void Worker::set_rot(float r){
	
	this->rot=r;
	
}

void Worker::set_cmd(Commander* cmd_new){
	
	this->cmd=cmd_new;
	
}

void Worker::set_hive(Hive* hive_new){
	
	this->hive=hive_new;
	
}

void Worker::w_log(){
	
	log_pos* l_p;
	l_p = new log_pos;
	l_p->X=this->X;
	l_p->Y=this->Y;
	l_p->rot=this->rot;
	this->log_p.push_back(l_p);
	
}

Hive* Worker::get_hive()
{
	return hive;
}
