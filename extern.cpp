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
		return new Hive;
	}
	
	void create_workers_hive(Hive* h, int i){
		h->create_workers(i);
	}
	
	float get_worker_X(Hive* h, int pos){
		return h->get_unassigned()[pos-1]->get_X();
	}
	
    Task* create_rand_task(){
        Task* t = new Task;
        //printf("Random task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }
    
    Task* create_simp_task(int name, int time, int amount){
        Task* t = new Task(name, time, amount);
        //printf("Simple task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }
    
    Task* create_cust_task(int name, int time, float X1, float X2, float Y1, float Y2, int amount){
        Task* t = new Task(name, time, X1, X2, Y1, Y2, amount);
        //printf("Custom task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return t;
    }

	void add_task(Scenario* sc, Task* t){
        sc->add_task(t);
    }
	
    
	void print_status(Scenario* sc){
        sc->status();
    }

    Worker* create_worker(){
        return new Worker;
    }
      
    void upd_hierarchy(Hive* h, Commander* a, Commander* b){
        h->upd_hier(a, b);
    }

	void dispose_workers_hive(Hive* h){
		Worker* w;
		for(int i = 0; i<h->get_amount_w(); i++){
			w = h->get_unassigned()[h->get_amount_w()-1];
			h->get_unassigned().pop_back();
			delete w;
		}
	}

	void dispose_hive(Hive* h){
		delete h;
	}

}
