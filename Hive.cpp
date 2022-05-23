#include "Hive.h"

int Hive::workers_num = 0;

Scenario* Hive::get_c_scenario(){
	
	return this->current_scenario;
	
} //get current scenario

void Hive::upd_hier(Commander* cmd, Commander* new_cmd){
	
	cmd->get_cmd()->add_workers(cmd->get_workers());
	cmd->clear_workers();
	cmd->set_cmd(new_cmd);
	
} // update hierarchy

void Hive::predict_abort(Task* t){

	if (t->get_amount() > workers_num) {
		t->to_abort = true;
	}

} // abort task or not

void Hive::assign_cmd(Task* t, Commander* c){
	
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
	
	workers_num += n;

}

Worker* Hive::add_worker(){

	if(!unassigned_workers.empty()){
		Worker* w;		
		w=unassigned_workers[unassigned_workers.size()-1];
		this->unassigned_workers.pop_back();
		return w;
	}else{printf("add_worker fault - not enough workers"); return nullptr;}
	
}

void Hive::set_queue(Scenario* c){ // create queue and send it to current scenario
	vector <Task*> t_q1 = c->get_tasks();
	vector <Task*> t_q2 = {};
	for (int i = 0; i < t_q1.size(); i++) {
		this->predict_abort(t_q1[i]);
		if (!t_q1[i]->to_abort) { t_q2.push_back(t_q1[i]); }
		else { Scenario::abort_num++; }
	}
	c->set_tasks(t_q2);
}

void Hive::add_workers(vector <Worker*> w)
{
	for (int i = 0; i < w.size(); i++) {
		unassigned_workers.push_back(w[i]);
	}
}

vector<Worker*> Hive::get_unassigned()
{
	return unassigned_workers;
}

int Hive::get_amount_w(){
	
	return this->unassigned_workers.size();
	
}

Commander* Hive::promote(){
	Commander* c;
	Worker* w;
	c = new Commander;
	c->set_hive(this);
	cmds.push_back(c);
	w = unassigned_workers[unassigned_workers.size() - 1];
	this->unassigned_workers.pop_back();
	w->~Worker();
	return c;
}

void Hive::demote(Commander* c) {
	for (int i = 0; i < cmds.size(); i++) {
		if (cmds[i] == c) {
			for (int j = i; j < cmds.size()-1; j++) {
				cmds[j] = cmds[j + 1];
			}
			cmds.pop_back();
			break;
		}
	}
	c->get_hive()->add_workers(c->get_workers());
	workers_num--;
	c->get_hive()->create_workers(1);
}