#include "Commander.h"
#include "Task.h"

Commander::Commander():Worker(){
	this->workers = {};
}



void Commander::set_task(Task* t){
	
	this->task = t;
	
}

void Commander::start_task(){
	
	if(this->task->get_amount()<=this->get_amount()){
		this->rnd_move(task->get_Area());
	}else{printf("Can't start task - not enough workers");}
	
}
void Commander::add_worker(int n){ //add certain amount of workers if possible
	if(this->get_hive()->get_amount_w() >= n) {
		Worker* w;
		for(int i = 0; i<n;i++){
			w = this->get_hive()->add_worker();
			this->workers.push_back(w);
		}
	}else{ printf("add_worker fault  - not enough workers");}
}

Commander::~Commander(){ // create worker on commander destruction
	
	this->get_hive()->create_workers(1);
	
}

void Commander::rnd_move(Area a){ // randomly distribute workers in given Area
	
	for(int i=0; i<this->workers.size();i++){
		workers[i]->set_X(min(a.x1,a.x2) + rand()*rand()%(abs(int(a.x1)-int(a.x2))));
		workers[i]->set_Y(min(a.x1,a.x2) + rand()*rand()%(abs(int(a.x1)-int(a.x2))));
		workers[i]->set_rot(rand()%360);
	}
	
}

int Commander::get_amount(){ // get number of working units
	
	return workers.size()+1; // +1 is because commander works too
	
}