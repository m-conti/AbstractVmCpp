#include <utility>

//
// Created by Matthieu CONTI on 2019-06-15.
//

#ifndef ABSTRACTVMCPP_TOPERAND_HPP
# define ABSTRACTVMCPP_TOPERAND_HPP

# include "IOperand.hpp"
# include "Vm.hpp"
# include "Factory.hpp"
# include <string>

class Factory;


class Operand : public IOperand {
public:
	static Factory* const	factory;
};

template<typename T>
class TOperand : public Operand {
public:
	explicit TOperand<T>( T value, eOperandType const &type );
	~TOperand<T>() override = default;

	T const cast( std::string const &value, eOperandType type ) const;

	int getPrecision() const override;
	eOperandType getType() const override;
	eOperandType getGreaterPrecision(IOperand const &rhs) const;

	IOperand const *operator+( IOperand const &rhs ) const override;
	IOperand const *operator-( IOperand const &rhs ) const override;
	IOperand const *operator*( IOperand const &rhs ) const override;
	IOperand const *operator/( IOperand const &rhs ) const override;
	IOperand const *operator%( IOperand const &rhs ) const override;

	std::string const &toString() const override;;

	T getValue();

private:
	TOperand<T>() : _value( 0 ), _type( eOperandType::Int32 ), _str( "0" ) {};
	eOperandType const		_type;
	T const					_value;
	std::string				_str;
};



template<typename T>
TOperand<T>::TOperand( T value, eOperandType const &type ) : _value( value ), _type( type ) {
	this->_str = std::to_string(value);
}

template<typename T>
T const TOperand<T>::cast( std::string const &value, eOperandType type ) const {
	switch ( type ) {
		case eOperandType::Int8:
		case eOperandType::Int16:
		case eOperandType::Int32:
			return std::stoi( value );
		case eOperandType::Float:
			return std::stof( value );
		case eOperandType::Double:
			return std::stod( value );
	}
}

template<typename T>
int TOperand<T>::getPrecision() const { return (static_cast<int>(_type)); }

template<typename T>
eOperandType TOperand<T>::getType() const { return (_type); }

template<typename T>
eOperandType TOperand<T>::getGreaterPrecision( IOperand const &rhs ) const {
	if (this->getPrecision() > rhs.getPrecision()) {
		return ( this->getType() );
	}
	else {
		return ( rhs.getType() );
	}
}

template<typename T>
IOperand const *TOperand<T>::operator+( IOperand const &rhs ) const {
	eOperandType	precision = this->getGreaterPrecision(rhs);
	std::string		value = std::to_string(this->cast( this->toString(), precision) + this->cast( rhs.toString(), precision));

	return ( this->factory->createOperand(precision, value) );
}

template<typename T>
IOperand const *TOperand<T>::operator-( IOperand const &rhs ) const {
	eOperandType	precision = this->getGreaterPrecision(rhs);
	std::string		value = std::to_string(this->cast( this->toString(), precision) - this->cast( rhs.toString(), precision));

	return ( this->factory->createOperand(precision, value) );
}

template<typename T>
IOperand const *TOperand<T>::operator*( IOperand const &rhs ) const {
	eOperandType	precision = this->getGreaterPrecision(rhs);
	std::string		value = std::to_string(this->cast( this->toString(), precision) * this->cast( rhs.toString(), precision));

	return ( this->factory->createOperand(precision, value) );
}

template<typename T>
IOperand const *TOperand<T>::operator/( IOperand const &rhs ) const {
	eOperandType	precision = this->getGreaterPrecision(rhs);
	std::string		value = std::to_string(this->cast( this->toString(), precision) / this->cast( rhs.toString(), precision));

	return ( this->factory->createOperand(precision, value) );
}

template<typename T>
IOperand const *TOperand<T>::operator%( IOperand const &rhs ) const {
	eOperandType	precision = this->getGreaterPrecision(rhs);
	std::string		value = std::to_string(this->cast( this->toString(), precision) % this->cast( rhs.toString(), precision));

	return ( this->factory->createOperand(precision, value) );
}

template<typename T>
std::string const &TOperand<T>::toString() const {
	return (_str);
}

template<typename T>
T TOperand<T>::getValue() {
	return (_value);
}




#endif //ABSTRACTVMCPP_TOPERAND_HPP
