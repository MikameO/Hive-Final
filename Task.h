#pragma once

#include "structs.h"

class Task{

	char name[20];
	int exec_time;
	Area coords;
	int amount;

public:

	static int num_aborted;
	int get_exec_time();
	int get_amount();
	Area get_Area();
	
	Task();
	
};