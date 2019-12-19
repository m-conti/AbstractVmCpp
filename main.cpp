//
// Created by Matthieu CONTI on 11/4/19.
//

#include "AbstractVm.hpp"

int		main(int ac, char **av) {

	Vm vm;

	if (ac == 1) {
		try {
			parseInput(vm);
		}
		catch (std::exception const &e) {
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	else {
		for (int i = 1; i < ac; ++i) {
			try {
				parseFile(vm, av[i]);
			}
			catch (std::exception const &e) {
				std::cout << "Error : " << e.what() << std::endl;
			}
			vm.clear();
		}
	}

	return (0);
}
