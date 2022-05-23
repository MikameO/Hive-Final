#include <cstdio>
#include <vector>

#include "Commander.h"
#include "Hive.h"
#include "Scenario.h"
#include "structs.h"
#include "Task.h"
#include "Worker.h"

extern "C" {
    Task* create_rand_task(){
        Task* t = new Task::Task;
        //printf("Random task:\n\tname: %c\n\ttime: %d\n", t->get_name(), t->get_exec_time());
        return Task;
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
  /*  
    //предстоит обернуть:
    
	void add_task(Scenario* sc, Task* t){
        sc->add_task(t);
        return;
    }
    
	void print_status(Scenario* sc){
        sc->status();
        return;
    }
    
    Worker* create_worker(){
        return new Worker;
    }
    
    void upd_hierarchy(Commander* a, Commander* b){
        upd_hier(a, b);
        return;
    }
    
    */
}
