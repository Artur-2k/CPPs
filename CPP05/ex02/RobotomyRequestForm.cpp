/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:42:34 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 17:05:08 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRForm", 72, 45) , _target("no target lol") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        _target = other._target;
        setIsSigned(other.getIsSigned());
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RRForm", 72, 45), _target(target) {}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executer) const
{
    // If sign grade not enough throws a grade exception
    if (!getIsSigned()) throw IsntSigned();
    
    if (executer.getGrade() > getExecGrade()) throw GradeTooLowException();

    // TODO actual robotomize learn random i guess
}

std::ostream& operator<< (std::ostream& os, const RobotomyRequestForm &RRForm)
{
    os  << "Name: " << RRForm.getName() << "\n"
    << "Target: " << RRForm.getTarget() << "\n"
    << "Is signed: " << (RRForm.getIsSigned() ? "Yes" : "No") << "\n"
    << "Sign Grade: " << RRForm.getSignGrade() << "\n"
    << "Execution Grade: " << RRForm.getExecGrade() << std::endl;
    return os;
}