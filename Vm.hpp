//
// Created by Matthieu CONTI on 2019-06-15.
//

#ifndef ABSTRACTVMCPP_VM_HPP
# define ABSTRACTVMCPP_VM_HPP

# define ACTIONS_NUMBER 12

# include "AbstractVm.hpp"

class Vm: public VmExceptions {
public:
	Vm();

	Vm( Vm const &src ) { (*this) = src; };

	~Vm();

	Vm &operator=( Vm const &rhs );

	void clear( void );

	// functions Vm

	void push( eOperandType type, std::string const &value );

	IOperand const *pop( void );

	void popNDelete( void );

	void dump( void );

	void ass( eOperandType type, std::string const &value );

	void add( void );

	void sub( void );

	void mul( void );

	void div( void );

	void mod( void );

	void print( void );

	void exit( void );

private:
	std::list<const IOperand *> stack;
};


#endif //ABSTRACTVMCPP_VM_HPP
