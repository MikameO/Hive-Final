#include "Hive.h"

Scenario* Hive::get_c_scenario(){
	
	return this->current_scenario;
	
} //get current scenario

void Hive::upd_hier(){
	
// Don't know what to do here [-]_[-]
	
} // update hierarchy

void Hive::predict_abort(Task*){
	
	//mlem [§]╚[§]
	
} // create list of abortion

void Hive::assing_cmd(Task* t, Commander* c){
	
	c->set_task(t);
	
}

void Hive::set_scenario(Scenario* s){
	
	this->current_scenario=s;
	
}

void Hive::create_workers(int n){
	
	for(int i=0; i<n; i++){
		this->unassigned_workers.push_back(new Worker);
		this->unassigned_workers[i]->set_name();
		this->unassigned_workers[i]->set_X(0);
		this->unassigned_workers[i]->set_Y(0);
		this->unassigned_workers[i]->set_rot(0);
		this->unassigned_workers[i]->set_cmd(nullptr);
		this->unassigned_workers[i]->set_hive(this);
	}
	
}

Worker* Hive::add_worker(){

	if(!unassigned_workers.empty()){
		Worker* w;		
		w=unassigned_workers[unassigned_workers.size()-1];
		this->unassigned_workers.pop_back();
		return w;
	}else{printf("add_worker fault - not enough workers"); return nullptr;}
	
}

void Hive::set_queue(Scenario*){
	
	// thread use ~_^
	
}

int Hive::get_amount_w(){
	
	return this->unassigned_workers.size();
	
}

Commander* Hive::promote(){
	Commander* c;
	Worker* w;
	c = new Commander;
	w = unassigned_workers[unassigned_workers.size() - 1];
	this->unassigned_workers.pop_back();
	w->~Worker();
	return c;
}