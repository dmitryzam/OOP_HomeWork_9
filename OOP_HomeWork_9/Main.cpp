#include<iostream>
#include"Hospital.hpp"

int main() {
	setlocale(LC_ALL, "RU");
	
	try {
		Hospital hospital(5);
		hospital.put("Tom Smith");
		hospital.put("Bilbo Begginse");
		hospital.put("Tom Hardy");
		hospital.put("Lady Gaga");
		hospital.put("Sarah Connor");
		//hospital.put("Tom Hanks");	// проверка переполнения пациентов

		//hospital.print();
		std::cout << "Patients list: " << hospital.report() << std::endl;
		std::cout << "Number of Tom Hardy - " << hospital.find("Tom Hardy") << std::endl;
		//std::cout << "Number of Tom Harley - " << hospital.find("Tom Harley") << std::endl; // проверка при введении неправильного имени

		std::cout << "Delete Tom Hardy:\n";
		hospital.discharge(3);
		//hospital.print();
		std::cout << "Patients list: " << hospital.report() << std::endl;

		std::cout << "##########################\n";
		Hospital h1 { "Tom Hanks", "Sarah Connor", "Tom Harley" };
		std::cout << "Patients list: " << h1.report() << std::endl;
		std::cout << "Number of Tom Hanks - " << h1.find("Tom Hanks") << std::endl;
		std::cout << "Delete Tom Hanks:\n";
		h1.discharge(1);
		std::cout << "Patients list: " << h1.report() << std::endl;
		std::cout << "Add John Watson for patients list\n";
		h1.put("John Watson");
		std::cout << "Patients list: " << h1.report() << std::endl;

		//h1.print();
		std::cout << "##########################\n";
		Hospital h2(h1);
		std::cout << "Patients list: " << h2.report() << std::endl;
		//h2.put("Gollum"); // Gollumу тут не место! (проверка переполнения)
	}
	catch (const std::exception& ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}	

	return 0;
}