/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:42:37 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 16:51:55 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        
    public: 
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator= (const RobotomyRequestForm &other);

        RobotomyRequestForm(const std::string &target);
        std::string getTarget() const;
        
        void execute(const Bureaucrat &executer) const;
}; 

std::ostream& operator<< (std::ostream& os, const RobotomyRequestForm &RRForm);