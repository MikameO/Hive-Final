#pragma once

#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;

class Commander;
class Hive;

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
	Commander* get_cmd();
	
	int get_num_workers();

	void set_name();
	void set_X(float);
	void set_Y(float);
	void set_rot(float);
	void set_cmd(Commander*);
	void set_hive(Hive*);

	vector <log_pos*> get_log();

	void w_log();

	Hive* get_hive();

	Worker();
	~Worker();

};