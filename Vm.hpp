//
// Created by Matthieu CONTI on 2019-06-15.
//

#ifndef ABSTRACTVMCPP_VM_HPP
# define ABSTRACTVMCPP_VM_HPP

# include "Factory.hpp"

class Vm {
public:
	Vm();
	Vm( Vm const & src ) { (*this) = src; };
	~Vm();
	Vm &	operator=( Vm const & rhs );

};


#endif //ABSTRACTVMCPP_VM_HPP
