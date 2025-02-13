/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:41 by fang              #+#    #+#             */
/*   Updated: 2025/02/13 20:38:09 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm() : _name("unkown"),
            _isSigned(false),
            _signGrade(75),
            _execGrade(25) {}
            
            
AForm::AForm(const AForm &other) : _name(other._name),
                            _isSigned(other._isSigned), 
                            _signGrade(other._signGrade), 
                            _execGrade(other._execGrade) {}

                            
AForm::~AForm() {}


AForm& AForm::operator= (const AForm &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name),
                                                                               _isSigned(false),
                                                                               _signGrade(signGrade),
                                                                               _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}


const std::string& AForm::getName() const { return _name; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }
bool AForm::getIsSigned() const { return _isSigned; }

void AForm::setIsSigned(bool value) { _isSigned = value; }


void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (_signGrade < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (_isSigned)
        throw AlreadySigned();
    setIsSigned(true);
}

std::ostream& operator<< (std::ostream& os, const AForm &form)
{
    os  << "Name: " << form.getName() << "\n"
        << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
        << "Sign Grade: " << form.getSignGrade() << "\n"
        << "Execution Grade: " << form.getExecGrade() << std::endl;
    return os;
}