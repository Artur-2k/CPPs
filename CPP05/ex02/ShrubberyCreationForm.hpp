/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:42:55 by fang              #+#    #+#             */
/*   Updated: 2025/02/14 21:33:36 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm &other);
        
        ShrubberyCreationForm(const std::string &target);
        std::string getTarget() const;
        
        void execute(const Bureaucrat &executer);
};

std::ostream& operator<< (std::ostream &os, const ShrubberyCreationForm &SCF);