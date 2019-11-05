//
// Created by Matthieu CONTI on 2019-06-15.
//

#ifndef ABSTRACTVMCPP_VM_HPP
# define ABSTRACTVMCPP_VM_HPP

# include "Factory.hpp"
# include "TOperand.hpp"
# include "Errors.hpp"
# include <list>
# include <iostream>

class Vm: public VmExceptions {
public:
	Vm();

	Vm( Vm const &src ) { (*this) = src; };

	~Vm();

	Vm &operator=( Vm const &rhs );

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
