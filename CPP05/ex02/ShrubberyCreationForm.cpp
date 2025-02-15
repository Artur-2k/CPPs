/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:48:14 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 17:03:27 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
// s: sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("dumbo") {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), 145, 137) {} 
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        setIsSigned(other.getIsSigned());
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

std::string ShrubberyCreationForm::getTarget() const{ return _target; }

// Checks if it is needed to sign and if so signs and then tries to execute.
// Throws exceptions if anything fails
void ShrubberyCreationForm::execute(const Bureaucrat &executer) const
{
    // If sign grade not enough throws a grade exception
    if (!getIsSigned()) throw IsntSigned();
        
    if (executer.getGrade() > getExecGrade()) throw GradeTooLowException();

    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile) throw std::runtime_error("Error opening output file");
    
    outFile << "ASCII trees\nlol you really thougt id waste time looking at ascii trees online?" << std::endl;
    
    outFile.close();
}

std::ostream& operator<< (std::ostream &os, const ShrubberyCreationForm &SCF)
{
    os  << "Name: " << SCF.getName() << "\n"
    << "Target: " << SCF.getTarget() << "\n"
    << "Is signed: " << (SCF.getIsSigned() ? "Yes" : "No") << "\n"
    << "Sign Grade: " << SCF.getSignGrade() << "\n"
    << "Execution Grade: " << SCF.getExecGrade() << std::endl;
    return os;
}