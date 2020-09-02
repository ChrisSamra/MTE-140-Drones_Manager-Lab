#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2, manager3, manager4;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
		
		manager3.insert_front(DronesManager::DroneRecord(20));
		manager4.insert_back(DronesManager::DroneRecord(20));
	    
	    //given testing
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))
		
//		//Student testing
		ASSERT_TRUE(manager3.get_size() == manager4.get_size() && manager3.get_size() == 1)
		ASSERT_TRUE(manager3.first != NULL && manager3.first == manager3.last)
		ASSERT_TRUE(manager4.first != NULL && manager4.first == manager4.last)
		ASSERT_TRUE(manager3.first->prev == NULL && manager3.last->next == NULL)
		ASSERT_TRUE(manager4.first->prev == NULL && manager4.last->next == NULL)
		ASSERT_TRUE(manager3.select(0) == manager4.select(0) && manager3.select(0) == DronesManager::DroneRecord(20))			
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(0));
		manager1.insert_front(DronesManager::DroneRecord(9));
		manager1.insert_front(DronesManager::DroneRecord(8));
		
		ASSERT_TRUE(manager2.select(2) == *manager1.last)
		ASSERT_TRUE(manager1.select(20) == *manager1.last)
		ASSERT_TRUE(manager1.select(0) == *manager1.first)
		ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager2.search(*manager1.first) == 0)
    	ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(100)) == 3)
		ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(9)) == 1 && manager1.search(DronesManager::DroneRecord(0)) == 2)
		return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(9));
		manager2 = manager2;
		manager1.remove_front();
		manager2.remove_back();
		
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)
		ASSERT_TRUE(manager1.first == NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first == NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.empty() && manager2.empty())
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(0))	
		
	    return true;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(0));
		manager1.insert_front(DronesManager::DroneRecord(9));
		manager1.insert_front(DronesManager::DroneRecord(8));
		manager1.replace(0, DronesManager::DroneRecord(20));
		
		//invalid
		ASSERT_FALSE(manager2.replace(0, DronesManager::DroneRecord(9)))
		ASSERT_FALSE(manager1.replace(10, DronesManager::DroneRecord(9)))
		//test replace twice and at start
		ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(20))
		manager1.replace(0, DronesManager::DroneRecord(30));
		ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(30))
		ASSERT_TRUE(*manager1.first->next == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager1.first->prev == NULL)
		//test replace at end
		manager1.replace(2, DronesManager::DroneRecord(21));
		ASSERT_TRUE(manager1.select(2) == DronesManager::DroneRecord(21))
		ASSERT_TRUE(*manager1.first->next == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager1.first->prev == NULL)
		//test reverse list
		ASSERT_FALSE(manager2.reverse_list())
		manager2.insert_front(DronesManager::DroneRecord(96));
		ASSERT_TRUE(manager2.reverse_list())
		manager1.reverse_list();
		ASSERT_TRUE(manager1.first->prev == NULL && *manager1.first->next == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager1.last->next == NULL && *manager1.last->prev == DronesManager::DroneRecord(9))
		ASSERT_TRUE(manager1.size == 3)
	
	   return true;
	   
	 }
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
        DronesManager manager1;
    	ASSERT_FALSE(manager1.select(0) == DronesManager::DroneRecord(567))
        ASSERT_TRUE(manager1.first == NULL)
        manager1.insert_front(DronesManager::DroneRecord(567));
        manager1.insert_front(DronesManager::DroneRecord(1));
        manager1.insert_front(DronesManager::DroneRecord(1193)); ////////
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(1193))
        manager1.insert_front(DronesManager::DroneRecord(40));
        manager1.insert_front(DronesManager::DroneRecord(5));
        ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(5))
	 return true;
	
	}
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		DronesManager manager1;
          manager1.insert_front(DronesManager::DroneRecord(5));
          ASSERT_FALSE(manager1.insert(DronesManager::DroneRecord(2),6))
          ASSERT_FALSE(manager1.select(6) == DronesManager::DroneRecord(2))
          manager1.insert_back(34);
          manager1.insert(DronesManager::DroneRecord(44),1);
          manager1.insert(DronesManager::DroneRecord(29),2);
          manager1.insert(DronesManager::DroneRecord(25),7);
          ASSERT_FALSE(manager1.select(7) == DronesManager::DroneRecord(25))
	    return true;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
	    DronesManager manager1;
        ASSERT_TRUE(manager1.empty())
        manager1.remove_front();
        manager1.remove_front();
        manager1.remove_back();
        manager1.remove_back();
        manager1.remove_front();
        ASSERT_TRUE(manager1.empty())
        manager1.insert_front(DronesManager::DroneRecord(567));
        manager1.insert_front(DronesManager::DroneRecord(1));
        manager1.insert_front(DronesManager::DroneRecord(1193));
        ASSERT_TRUE(!manager1.empty())
        
        return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager Drone1, Drone2;
		Drone1.insert(DronesManager::DroneRecord(10),0);
		ASSERT_TRUE(Drone1.select(0) == DronesManager::DroneRecord(10))
		Drone1.insert(DronesManager::DroneRecord(20),1);
		ASSERT_TRUE(*Drone1.first->next == DronesManager::DroneRecord(20))
		ASSERT_TRUE(Drone1.first->prev == NULL)
		Drone1.insert(DronesManager::DroneRecord(50),2);
		Drone1.insert(DronesManager::DroneRecord(120),1);
		Drone1.insert_front(DronesManager::DroneRecord(30));
		Drone1.insert_back(DronesManager::DroneRecord(40));
		
		ASSERT_TRUE(Drone1.remove(0))
		ASSERT_TRUE(Drone1.remove(1))
		ASSERT_TRUE(Drone1.remove(2))
		
	//Invalid
		ASSERT_FALSE(Drone1.remove(20))
		ASSERT_FALSE(Drone2.remove(20))
		ASSERT_FALSE(Drone1.remove(60))
		ASSERT_FALSE(Drone1.insert(DronesManager::DroneRecord(70),25))
		
	return true;   
	}
	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
        DronesManager manager1;
        
        manager1.insert(DronesManager::DroneRecord(140),10);
        ASSERT_FALSE(manager1.empty())
        
          manager1.insert_back(33);
          ASSERT_TRUE(!manager1.empty())
        
          manager1.insert_front(DronesManager::DroneRecord(567));
          manager1.insert_back(DronesManager::DroneRecord(1));
          manager1.insert_front(DronesManager::DroneRecord(1193));
          manager1.insert_front(DronesManager::DroneRecord(40));
          manager1.insert_front(DronesManager::DroneRecord(5));
          manager1.insert_back(DronesManager::DroneRecord(167));
          manager1.insert_back(DronesManager::DroneRecord(1660));
        
          manager1.reverse_list();
        
          manager1.remove(5);
          ASSERT_TRUE(manager1.size == 8)
          manager1.remove_front();
          manager1.remove_front();
          
          manager1.remove_back();
          manager1.remove_back();
          manager1.remove_front();
          manager1.remove_front();
          manager1.remove_front();
          manager1.remove_front();
          manager1.remove_front();
        
          ASSERT_TRUE(manager1.empty())      
	   return true;
	}
};

#endif
