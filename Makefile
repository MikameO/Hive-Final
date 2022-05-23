libhive.so: extern.cpp
	g++ -fPIC -shared -g -O0 -Wall -Wextra -o libhive.so extern.cpp