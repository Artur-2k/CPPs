/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:29:37 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 14:02:45 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PPForm", 25, 5), _target("unkown") {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Copy Constructor
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        _target = other._target;
        setIsSigned(other.getIsSigned());
    }
    return *this;
}

// Param Constructor
PresidentialPardonForm::PresidentialPardonForm (const std::string &target) : AForm("PPForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat &executer) const
{
    // If sign grade not enough throws a grade exception
    if (!getIsSigned())
        throw IsntSigned();

    if (executer.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::cout << _target << " was pardoned by Zaphod Beeblebrox or wte." << std::endl;
}

// Getter
std::string PresidentialPardonForm::getTarget() const { return _target; }

// Setter
void PresidentialPardonForm::setTarget(std::string value) { _target = value; }

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PPF)
{
    os << "Name: " << PPF.getName() << "\n"
       << "Target: " << PPF.getTarget() << "\n"
       << "Is signed: " << (PPF.getIsSigned() ? "Yes" : "No") << "\n"
       << "Sign Grade: " << PPF.getSignGrade() << "\n"
       << "Execution Grade: " << PPF.getExecGrade() << std::endl;
    return os;
}
