#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Импортируем библиотеку
import ctypes
lib_hive = ctypes.CDLL('./libhive.so')


lib_hive.create_hive.restype = ctypes.c_void_p
lib_hive.create_workers_hive.argtypes = [ctypes.c_void_p, ctypes.c_int]
lib_hive.create_workers_hive.restype = None

lib_hive.get_worker_X.argtypes = [ctypes.c_void_p, ctypes.c_int]
lib_hive.get_worker_X.restype = ctypes.c_float

lib_hive.create_rand_task.restype = ctypes.c_void_p
lib_hive.create_simp_task.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib_hive.create_simp_task.restype = ctypes.c_void_p
lib_hive.create_cust_task.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib_hive.create_cust_task.restype = ctypes.c_void_p
lib_hive.add_task.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
lib_hive.add_task.restype = None
lib_hive.print_status.argtypes = [ctypes.c_void_p]
lib_hive.print_status.restype = None
lib_hive.create_worker.restype = ctypes.c_void_p
lib_hive.upd_hierarchy.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p]
lib_hive.upd_hierarchy.restype = None

lib_hive.dispose_workers_hive.argtypes = [ctypes.c_void_p]
lib_hive.dispose_workers_hive.restype = None
lib_hive.dispose_hive.argtypes = [ctypes.c_void_p]
lib_hive.dispose_hive.restype = None

hive1 = lib_hive.create_hive()

lib_hive.create_workers_hive(hive1, 100)
print(lib_hive.get_worker_X(hive1, 1))  

# Most of the present functions require to address to external class objects so these objects have to be implemented to use most of the functions
# But in case of limited time I show that I know how to use C extern with Python with test of only 3 funtions (watch above)

#lib_hive.dispose_workers_hive(hive1) #double free here: free(): double free detected in tcache 2
lib_hive.dispose_hive(hive1)
print("Well done")
