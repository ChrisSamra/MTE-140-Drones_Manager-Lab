# MTE-140-Drones_Manager-Lab

This code was from a lab assignment I had in my Data Structures and Algorithims course back in February 2020.


The concept behind the Drones Manager software is that it can store a record with multiple characteristics of each drone in a fleet.
This record can be updated and modified with new information at the users discretion.
The data is stored in a doubly-linked list, with each node containing a drone object.


The structure of the header files were provided by the instructor, with the functions/classes having to be filled in by the student (myself).
The cpp files were made from scratch.


# lab2_drones_manager.hpp 

-creates the structure of a DroneRecord (each drone object will be an instance of this) in the protected section of the DronesManager class
-instantiates all of the functions (written in lab2_drones_manager.cpp) in the public section of the class


# lab2_drones_manager.cpp

-implements all of the methods needed for the DronesManager class including constructor, destructor,
 comparison operator, as well as the accesor and mutator functions needed to preperly view and modify elements of the data structure  
 
 
# lab2_drones_manager_test.hpp

-header file with a class containing a variety of tests that test the methods of the DronesManager class


# lab2_main.cpp

-main function that runs all of the tests against the DronesMangaer class and returns the results of the tests



