//
// Created by Matthieu CONTI on 11/4/19.
//

#include "AbstractVm.hpp"

int		main(int ac, char **av) {

	Vm vm;

	if (ac == 1)
		parseInput(vm);
	else {
		for (int i = 1; i < ac; ++i) {
			parseFile(vm, av[i]);
		}
	}
	return (0);
}
