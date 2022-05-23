#include <cstdio>
#include <vector>

#include "Commander.h"
#include "Hive.h"
#include "Scenario.h"
#include "structs.h"
#include "Task.h"
#include "Worker.h"

extern "C" {
	
	Hive* create_hive(){
		return new Hive::Hive;
	}
	
	void create_workers_hive(Hive* h, int i){
		h->Hive::create_worker(i);
	}
	
	float get_worker_X(Hive* h, int pos){
		return h->Hive::get_unassigned()[pos-1]->Worker::get_X();
	}
	
    Task* create_rand_task(){
        Task* t = new Task::Task;
        //printf("Random task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }
    
    Task* create_simp_task(int name, int time, int amount){
        Task* t = new Task::Task(name, time, amount);
        //printf("Simple task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }
    
    Task* create_cust_task(int name, int time, float X1, float X2, float Y1, float Y2, int amount){
        Task* t = new Task::Task(name, time, X1, X2, Y1, Y2, amount);
        //printf("Custom task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }

	void add_task(Scenario* sc, Task* t){
        sc->Scenario::add_task(t);
    }
	
    
	void print_status(Scenario* sc){
        sc->Scenario::status();
    }

    Worker* create_worker(){
        return new Worker::Worker;
    }
      
    void upd_hierarchy(Commander* a, Commander* b){
        Hive::upd_hier(a, b);
    }

	void dispose_workers_hive(Hive* h){
		Worker* w;
		for(int i = 0; i<h->Hive::get_amount_w(); i++){
			w = h->Hive::get_unassigned()[Hive::get_amount_w()-1];
			h->Hive::get_unassigned().pop_back();
			delete w;
		}
	}

	void dispose_hive(Hive* h){
		delete h;
	}

}
