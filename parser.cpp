//
// Created by matthieu CONTI on 12/11/2019.
//

# include "AbstractVm.hpp"

int 	instruction(std::string line) {
	int i = 0;
	std::smatch sm;
	std::array<std::regex, 12>	reg = {
			std::regex("^push (.*)$"),
			std::regex("^pop$"),
			std::regex("^dump$"),
			std::regex("^assert (.*)$"),
			std::regex("^add$"),
			std::regex("^sub$"),
			std::regex("^mul$"),
			std::regex("^div$"),
			std::regex("^mod$"),
			std::regex("^print$"),
			std::regex("^exit$"),
			std::regex("^;(.*)$")
	};

	for (unsigned int i = 0; i < 12; ++i) {
		if (std::regex_match(line, sm, reg[i]))
			std::cout << i << " " << sm[1] << std::endl;
	}
}

void	parseLine(Vm &vm, std::string const &line) {
	std::cout << line <<std::endl;
	instruction(line);

}

void	parseFile(Vm &vm, std::string const &file_name) {
	std::fstream	stream;
	std::string		str;

	stream.open(file_name);
	while (std::getline(stream, str)) {
		parseLine(vm, str);
	}
	stream.close();
}

void	parseInput(Vm &vm) {
	std::string	str;

	while (std::getline(std::cin, str)) {
		parseLine(vm, str);
	}
}
