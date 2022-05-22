#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"
#include "Commander.h"
#include "Scenario.h"
#include "Hive.h"
#include "structs.h"

using namespace std;

class Task{

	char name;
	int exec_time;
	Area coords;
	int amount;

public:

	bool finished;
	bool to_abort;

	void set_name();
	void set_exec_time(int);
	void set_coords(Area);
	void set_amount(int);

	static int num_aborted;
	int get_exec_time();
	int get_amount();
	Area get_Area();
	
	Task();
	~Task();
	
};