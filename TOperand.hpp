#include <utility>

//
// Created by Matthieu CONTI on 2019-06-15.
//

#ifndef ABSTRACTVMCPP_TOPERAND_HPP
# define ABSTRACTVMCPP_TOPERAND_HPP

# include "AbstractVm.hpp"


IOperand const *createOperand(eOperandType type, std::string const &value);

template<typename T>
class TOperand : public IOperand, public OperdandException {
public:
	explicit TOperand<T>(T value, eOperandType const &type);
	explicit TOperand<T>(std::string value, eOperandType const &type);

	~TOperand<T>() override = default;

	T const cast(std::string const &value, eOperandType type) const;

	int getPrecision() const override;

	eOperandType getType() const override;

	eOperandType getGreaterPrecision(IOperand const &rhs) const;

	IOperand const *operator+(IOperand const &rhs) const override;

	IOperand const *operator-(IOperand const &rhs) const override;

	IOperand const *operator*(IOperand const &rhs) const override;

	IOperand const *operator/(IOperand const &rhs) const override;

	IOperand const *operator%(IOperand const &rhs) const override;

	std::string const &toString() const override;

	T getValue() const;

private:
	TOperand<T>() : _value(0), _type(eOperandType::Int32), _str("0") {};
	eOperandType const	_type;
	T					_value;
	std::string			_str;
};

template<typename T>
TOperand<T>::TOperand(T value, eOperandType const &type) : _value(value), _type(type) {
	_str = std::to_string(value);
}


template<typename T>
TOperand<T>::TOperand(std::string value, eOperandType const &type) : _type(type) {
	std::numeric_limits<T>	limit;
	double number	=	std::stod( value );

	if (number > limit.max())
		throw (OperdandException::OverflowException());
	if (number < limit.min())
		throw (OperdandException::UnderflowException());
	_value = static_cast<T>(number);
	_str = std::to_string(_value);
}

template<typename T>
T const TOperand<T>::cast(std::string const &value, eOperandType type) const {
	switch (type) {
		case eOperandType::Int8:
		case eOperandType::Int16:
		case eOperandType::Int32:
			return std::stoi(value);
		case eOperandType::Float:
			return std::stof(value);
		case eOperandType::Double:
			return std::stod(value);
	}
}

template<typename T>
int TOperand<T>::getPrecision() const { return (static_cast<int>(_type)); }

template<typename T>
eOperandType TOperand<T>::getType() const { return (_type); }

template<typename T>
eOperandType TOperand<T>::getGreaterPrecision(IOperand const &rhs) const {
	if (getPrecision() > rhs.getPrecision()) {
		return (getType());
	} else {
		return (rhs.getType());
	}
}

template<typename T>
IOperand const *TOperand<T>::operator+(IOperand const &rhs) const {
	eOperandType precision = getGreaterPrecision(rhs);
	double first_operand = static_cast<double>(cast(toString(), precision));
	double second_operand = static_cast<double>(cast(rhs.toString(), precision));

	std::string value = std::to_string(first_operand + second_operand);

	return (createOperand(precision, value));
}

template<typename T>
IOperand const *TOperand<T>::operator-(IOperand const &rhs) const {
	eOperandType precision = getGreaterPrecision(rhs);
	double first_operand = static_cast<double>(cast(toString(), precision));
	double second_operand = static_cast<double>(cast(rhs.toString(), precision));

	std::string value = std::to_string(first_operand - second_operand);

	return (createOperand(precision, value));
}

template<typename T>
IOperand const *TOperand<T>::operator*(IOperand const &rhs) const {
	eOperandType precision = getGreaterPrecision(rhs);
	double first_operand = static_cast<double>(cast(toString(), precision));
	double second_operand = static_cast<double>(cast(rhs.toString(), precision));

	std::string value = std::to_string(first_operand * second_operand);

	return (createOperand(precision, value));
}

template<typename T>
IOperand const *TOperand<T>::operator/(IOperand const &rhs) const {
	eOperandType precision = getGreaterPrecision(rhs);
	double first_operand = static_cast<double>(cast(toString(), precision));
	double second_operand = static_cast<double>(cast(rhs.toString(), precision));

	if (!second_operand) {
		throw NullDenominatorException();
	}
	std::string value = std::to_string(first_operand / second_operand);


	return (createOperand(precision, value));
}

template<typename T>
IOperand const *TOperand<T>::operator%(IOperand const &rhs) const {
	eOperandType precision = getGreaterPrecision(rhs);
	double first_operand = static_cast<double>(cast(toString(), precision));
	double second_operand = static_cast<double>(cast(rhs.toString(), precision));

	if (!second_operand) {
		throw NullDenominatorException();
	}
	std::string value = std::to_string(std::fmod(first_operand, second_operand));

	return (createOperand(precision, value));
	return nullptr;
}


template<typename T>
std::string const &TOperand<T>::toString() const {
	return (_str);
}

template<typename T>
T TOperand<T>::getValue() const {
	return (_value);
}


#endif //ABSTRACTVMCPP_TOPERAND_HPP
