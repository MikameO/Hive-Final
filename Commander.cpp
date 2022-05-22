#include "Commander.h"
#include "Hive.h"

Commander::Commander(){
	
	this->name = rand();
	this->X = 0;
	this->Y = 0;
	this->rot = 0;
	this->cmd = nullptr;
	this->hive = nullptr;
	this->workers = {};
	
}

void Commander::set_task(Task* t){
	
	this->task = t;
	
}

void Commander::add_worker(int n){ //add certain amount of workers if possible
	
	if(n<=hive->unassigned_workers.size()){
		for(int i = 0; i<n;i++){
			this->workers.push_back(this->hive->unassigned_workers[0]);
			this->workers[workers.size()-1].set_cmd(this);
			this->hive->unassigned_workers.pop_front();
		}
	}else{
		printf("add_worker fault - not enough workers");
	}
	
}

~Commander(){ // create worker on commander destruction
	
	this->hive.create_workers(1);
	
}

void Commander::move_swarm(Area*){

	
	
}	

void Commander::rnd_move(Area){ // randomly distribute workers in given Area

	
	
}