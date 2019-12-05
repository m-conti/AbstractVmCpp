//
// Created by matthieu CONTI on 12/11/2019.
//

# include "parser.hpp"


eOperandType	castToEOperandType(std::string cast) {
	std::array<std::string, OPERAND_NUMBER> operands = {
			"int8",
			"int16",
			"int32",
			"float",
			"double",
	};
	std::array<std::string, OPERAND_NUMBER>::iterator	start = operands.begin();
	std::array<std::string, OPERAND_NUMBER>::iterator	end = operands.end();
	int		op = std::find(start, end, cast) - start;

	if (op >= OPERAND_NUMBER)
		throw ParserExceptions::UnknownOperandTypeException();

	return (static_cast<eOperandType>(op));
}

void			launchAction(Vm &vm, uint8_t	action, std::string value) {
	std::smatch	sm;

	std::regex_match(value, sm, std::regex("^ (.*)\\((.*)\\)$"));
	if (!sm.size())
		throw ParserExceptions::SyntacticErrorException();

	if (action)
		vm.ass(castToEOperandType(sm[1]), sm[2]);
	else
		vm.push(castToEOperandType(sm[1]), sm[2]);
}

bool			launchAction(Vm &vm, uint8_t	action) {
	std::array<void (Vm::*)(void), (ACTIONS_NUMBER - 3)>	actions = {
		&Vm::popNDelete,
		&Vm::dump,
		&Vm::add,
		&Vm::sub,
		&Vm::mul,
		&Vm::div,
		&Vm::mod,
		&Vm::print,
	};

	if (action >= 10)
		return (action == 10);
	else if (action > 3)
		--action;
	--action;

	(vm.*actions[action])();
	return (false);
}

bool			launchInstruction(Vm &vm, std::string const &line) {
	bool error = true;
	std::smatch sm;
	std::array<std::regex, ACTIONS_NUMBER>	reg = {
			std::regex("^push(.*)$"),
			std::regex("^pop$"),
			std::regex("^dump$"),
			std::regex("^assert(.*)$"),
			std::regex("^add$"),
			std::regex("^sub$"),
			std::regex("^mul$"),
			std::regex("^div$"),
			std::regex("^mod$"),
			std::regex("^print$"),
			std::regex("^exit$"),
			std::regex("^;.*$")
	};

	for (uint8_t i = 0; i < 12; ++i) {
		std::regex_match(line, sm, reg[i]);
		if (sm.size()) {
			if (sm.size() > 1)
				launchAction(vm, i, sm[1]);
			else
				if (launchAction(vm, i))
					return true;
			error = false;
			break;
		}
	}
	if (error)
		throw ParserExceptions::UnknownInstructionException();
	return (false);
}

void 				parseStream(Vm &vm, std::iostream &stream) {
	std::string		str;
	int				i = 0;
	bool			exit;

	while (std::getline(stream, str)) {
		++i;
		if (!str[0])
			continue ;
		try {
			exit = launchInstruction(vm, str);
			if (exit)
				break ;
		}
		catch (std::exception const &e) {
			std::cout << "Error, line " << i << " : " << e.what() << std::endl;
		}
	}
	if (!exit)
		throw NoExitException();
}

void				parseFile(Vm &vm, std::string const &file_name) {
	std::fstream	stream;

	stream.open(file_name, std::fstream::in);
	if (!stream.is_open()) {
		throw FileErrorException();
	}
	parseStream(vm, stream);
	stream.close();
}

void				parseInput(Vm &vm) {
	std::stringstream stream;
	std::string	str;

	while (std::getline(std::cin, str)) {
		stream << str;
		stream << std::endl;
		if (str == ";;")
			break ;
	}
	std::cout << stream.str() << std::endl;
	parseStream(vm, stream);
}
