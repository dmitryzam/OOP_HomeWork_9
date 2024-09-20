#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<exception>
#include<initializer_list>

class Hospital {
private:
	std::vector<std::string> patients;	// вектор пациентов больницы
	int capacity;	// вместимость больницы
public:
	Hospital() : capacity(0){}
	Hospital(int capacity) {
		this->capacity = capacity;
	}
	Hospital(const Hospital& other) {
		this->capacity = other.capacity;
		this->patients = other.patients;
	}			
	Hospital(const std::initializer_list<std::string>& list) : Hospital(list.size()) {
		//capacity = 100;	// можно по умолчанию, вместо инициализации capacity от list.size()
		for (auto& el : list) {
			patients.push_back(el);
		}
	}	
	// метод добавляющий пациента:
	void put(const std::string& name) {
		if (patients.size() >= capacity)
			throw std::exception("Patients is overflow!");
		patients.push_back(name);
	}
	//метод, принимающий индекс пациента и удаляющий его из вектора:
	void discharge(int index) {
		if(patients.size() == 0)
			throw std::exception("You haven't patients!");
		if (index < 0 || index > patients.size())
			throw std::exception("Index is wrong!");
		std::vector<std::string>::iterator it = patients.begin();
		std::vector<std::string> tmp;
		while (it != (patients.begin() + index - 1)) {
			tmp.push_back(*it);
			++it;
		}
		//std::advance(it, index + 1);
		it = patients.begin() + index;
		while (it != patients.end()) {
			tmp.push_back(*it);
			++it;
		}
		patients = tmp;
	}
	
	// метод, принимающий строку с именем и возвращающий позицию данного пациента в векторе:
	int find(const std::string& name) {
		int position = 0;
		std::vector<std::string>::iterator it = patients.begin();
		for (auto& it : patients) {
			++position;
			if (it == name)
				return position;
		}
		throw std::exception("Do not found name!");
	}
	// метод, возвращающий строку, состоящую из всех имен из вектора, разделенных запятой:
	std::string report()const {
		std::string tmp;		
		for (auto it = patients.cbegin(); it != patients.cend(); ++it) {
			tmp += *it;
			if(it != patients.cend() - 1)
				tmp += ", ";
		}
		return tmp;
	}
	// метод вывода в консоль:
	void print()const {
		std::cout << "Кол-во поциентов - " << patients.size() << " в больнице.\n";
		std::cout << "Макс. кол-во поциентов - " << capacity << " в больнице.\n";
		if (patients.size() > 0) {
			std::vector<std::string>::const_iterator it = patients.begin();
			for (auto& it : patients)
				std::cout << "Пациент: " << it << '\n';
		}
	}	
};

