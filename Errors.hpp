//
// Created by Matthieu CONTI on 11/5/19.
//

#ifndef ABSTRACTVMCPP_ERRORS_HPP
# define ABSTRACTVMCPP_ERRORS_HPP

# include "TOperand.hpp"
# include "Vm.hpp"

class VmExceptions {
public:
	class EmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Instruction on an empty stack.");
		}
	};

	class PopEmptyStackException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Instruction pop on an empty stack.");
		}
	};

	class OperandMissingException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("The stack is composed of strictly less that two values when an arithmetic instruction is executed.");
		}
	};

};

class ParserExceptions {
	class SyntacticErrorException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("The assembly program includes one or several lexical errors or syntactic errors.");
		}
	};

	class UnknownInstructionException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("An instruction is unknown.");
		}
	};
};

class OperdandException {
	class OverflowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Overflow on a value.");
		}
	};

	class UnderflowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Underflow on a value.");
		}
	};

	class NullDenominatorException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Division/modulo by 0.");
		}
	};
};

class NoExitException : public std::exception {
public:
	virtual const char *what() const throw() {
		return ("The program doesn’t have an exit instruction.");
	}
};

class FailAssertException : public std::exception {
public:
	virtual const char *what() const throw() {
		return ("An assert instruction is not true.");
	}
};

#endif //ABSTRACTVMCPP_ERRORS_HPP
