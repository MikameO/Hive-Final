#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Импортируем библиотеку
import ctypes
lib_hive = ctypes.CDLL('./libhive.so')


lib_hive.create_hive.restype = ctypes.c_void_p
lib_hive.create_workers_hive.argtypes = [ctypes.c_void_p, ctypes.c_int]
lib_hive.create_workers_hive.restype = None
lib_hive.create_rand_task.restype = ctypes.c_void_p
lib_hive.create_simp_task.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib_hive.create_simp_task.restype = ctypes.c_void_p
lib_hive.create_cust_task.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib_hive.create_cust_task.restype = ctypes.c_void_p
lib_hive.add_task.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
lib_hive.add_task.restype = None
lib_hive.print_status.argtypes = [ctypes.c_void_p]
lib_hive.print_status.restype = None
lib_hive.create_worker.restype = [ctypes.c_void_p]
lib_hive.upd_hierarchy.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
lib_hive.upd_hierarchy.restype = None

# Вызываем функции из импортированной библиотеки.
# Для вызова create_monster нужно как-то передать в библиотеку char*.
# Создаём переменную нужного типа для параметра:
monster_name = ctypes.c_char_p('lion'.encode('utf-8'))
# Кодировка utf-8 указана, чтобы однозначно перевести строки Python,
# которые в общем случае используют несколько байт на 1 символ, в 
# строку C. Теперь вызываем:
monster1 = lib_hive.create_monster(1, 3, monster_name, 100)
# Передаём полученный указатель на монстра как параметр 
# библиотечных функций, не пытаясь получать доступ к нему непосредственно:
health = lib_hive.get_health(monster1)
print(health)  #  вывод: 100

# новая переменная для переименования монстра:
new_name = ctypes.c_char_p('tiger'.encode('utf-8'))
lib_hive.set_name(monster1, new_name)

# Прочтём имя монстра функцией 
# void get_name(Monster *m, char* name, int max_name_len).
# Имя будет выдано в параметре name, причём надо заранее создать
# буфер для него и при создании указать длину:
name = ctypes.create_string_buffer(100)
lib_hive.get_name(monster1, name, ctypes.sizeof(name))
print(name.value.decode('utf-8'))
# Общее правило: Python освобождает ту память, которую он сам и выделял, 
# но не память, выделенную C-библиотеками. Поэтому, если бы get_name 
# выдавала char* как возвращаемое значение, выделяя для этой строки память,
# пришлось бы делать и C-функцию для очистки такой строки;
# если бы она не была вызвана, возникла бы memory leak.

# Для вызова функции get_pos нужна передача параметров по указателям;
# сделаем две переменных для таких параметров
int_x = ctypes.c_int(-1)  # первая переменная
p_int_x = ctypes.pointer(int_x)  # указатель на неё
int_y = ctypes.c_int(-1)  # вторая переменная
p_int_y = ctypes.pointer(int_y)  # указатель на неё
# вызываем 
lib_hive.get_pos(monster1, p_int_x, p_int_y)
# распечатаем значения переменных
print(int_x.value)
print(int_y.value)

# Можно и не делать отдельных переменных для указателей,
# а использовать byref:
int_x.value = -1
int_y.value = -1
lib_hive.get_pos(monster1, ctypes.byref(int_x), ctypes.byref(int_y))
# снова распечатаем значения переменных
print(int_x.value)
print(int_y.value)

# очистим память
lib_hive.dispose_monster(monster1)
