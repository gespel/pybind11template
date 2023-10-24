#include <iostream>
#include <pybind11/pybind11.h>

class Add {
public: 
	Add(int a, int b) : a(a), b(b) {

	}
	void printAdd() {
		std::cout << a+b << std::endl;
	}
	int add() {
		return a+b;
	}	
private:
	int a = 0;
	int b = 0;
};

namespace py = pybind11;

PYBIND11_MODULE(addmod, m) {
	py::class_<Add>(m, "Add")
		.def(py::init<int, int>())
		.def("printAdd", &Add::printAdd)
		.def("add", &Add::add);
}

