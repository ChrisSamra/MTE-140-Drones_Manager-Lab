#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include "lab2_drones_manager.hpp"


DronesManager::DronesManager() {
	first = NULL;
	last = NULL;
	size = 0;
}

DronesManager::~DronesManager() {
	DroneRecord* temp = NULL;
	DroneRecord* cur = first;
	while (cur)
	{
		temp = cur->next;
		delete cur;
		cur = NULL;
		cur = temp;
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.droneID == rhs.droneID) && (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought) && (lhs.droneType == rhs.droneType) 
	&& (lhs.manufacturer == rhs.manufacturer) && (lhs.description == rhs.description) && (lhs.batteryType == rhs.batteryType);
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return(first == NULL);
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord* cur = first; 
	
	if (cur == NULL || cur == 0)
	{
		return DroneRecord(0);
		 
	}
	else if (index > size||index + 1 == size)
	{
		return *last;
	}
	else
	{
		for(int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
	}
	return *cur;
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* cur = first;
	if(cur == NULL)
	{
		return 0;
	}
	else 
	{
		for (int i = 0; i < size; i++)
		{
			if (select(i) == value)
			{
				return i;
			}
			cur = cur->next;
		}
		return size;
	}
}

void DronesManager::print() const {
	DroneRecord* cur = first;
	while (cur)
	{
		cout << cur->droneType << endl << cur->droneID << endl << cur->range << endl << cur->yearBought << endl << cur->manufacturer << endl << cur->description 
		<< endl << cur->batteryType << endl;
	
		cur = cur->next;
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if(index == 0 || size == 0)
	{
		return insert_front(value);
	}
	else if(index == size)
		return insert_back(value);
	
	else if (index > size)
		return false;
	else
	{
		DroneRecord* newval = new DroneRecord(value);
		DroneRecord* temp = first;
		DroneRecord* temp2 = NULL;
		for(int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		temp2 = temp->prev;
		newval->next = temp;
		newval->prev = temp2;
		temp2->next = newval;
		temp->prev = newval;
	}
	size++;
	
	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* newval = new DroneRecord(value);
	if (!first)
	{
		newval->prev = NULL;
		newval->next = NULL;
		first = newval;
		last = newval;
	}
	else
	{
		newval->next = first;
		first->prev = newval;
		newval->prev = NULL;
		first = newval;

		
	}
	size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* newval = new DroneRecord(value);
	if (!first)
	{
		first = newval;
		last = newval;
	}
	else 
	{
		last->next  = newval;
		newval->prev = last;
		newval->next = NULL;
		last = newval;
	}
	size++;
	return true;
	
}

bool DronesManager::remove(unsigned int index) {
	if(index > size)
		return false;
	else if (index == 0)
	{
		return remove_front();
	}
	else if (index == size)
	{
		return remove_back();
	}
	else
	{
		DroneRecord* temp = first;
		DroneRecord* rem = NULL;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		rem = temp;
		temp = temp->next;
		temp->prev = rem->prev;
		temp = rem->prev;
		temp->next = rem->next;
		delete rem;
		rem = NULL;
	}
	size--;
	return true;
}

bool DronesManager::remove_front() {
	if (!first)
		return false;
	else if(!first->next)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else 
	{
		DroneRecord* temp = first->next;
		temp->prev = NULL;
		delete first;
		first = temp;
	}
	size--;
	return true;
}

bool DronesManager::remove_back() {
	if(!first)
		return false;
	else if(!first->next)
	{
		delete first;
		delete last;
		first = NULL;
		last = NULL;
	}
	else
	{
		DroneRecord* temp = last->prev;
		temp->next = NULL;
		delete last;
		last = temp;
	}
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(!first)
		return false;
	else if(index == 0)
	{
		remove_front();
		insert_front(value);
	}
	else if(index-1 > size)
		return false;
	else if(index == size - 1)
	{
		remove_back();
		insert_back(value);
	}
	else
	{
		insert(value, index);
		remove(index + 1);
	}
	return true;
}

bool DronesManager::reverse_list() {
	if(!first)
		return false;
	else if (size == 1)
	{
		return true;
	}
	else 
	{
		DroneRecord* cur = first;
		DroneRecord* temp = NULL;
		while(cur)
		{
			temp = cur->next;
			cur->next = cur->prev;
			cur->prev = temp;
			cur = temp;
		}
		temp = first;
		first = last;
		last = temp;
	}
	return true;
}

