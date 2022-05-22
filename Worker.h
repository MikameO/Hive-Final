#pragma once

#include "struct.h"
#include <vector>

class Commander;

class Worker{

	char name;
	float X;
	float Y;
	float rot; // rotation
	Commander* cmd;
	vector <log_pos*> log_p;
	Hive* hive;
public:
	float get_X();
	float get_Y();
	float get_rot();
	
	int get_num_workers();

	void set_X(float);
	void set_Y(float);
	void set_rot(float);
	void set_cmd(Commander*);
	void set_hive(Hive*);

	void w_log();

	Worker();
	~Worker();

};