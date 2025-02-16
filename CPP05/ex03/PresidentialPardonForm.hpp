/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:29:37 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 14:00:05 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Includes
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    // Attributes
    std::string _target;

public:
    // Default Constructor
    PresidentialPardonForm();

    // Copy Constructor
    PresidentialPardonForm(const PresidentialPardonForm &other);

    // Destructor
    ~PresidentialPardonForm();

    // Copy Constructor
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    // Param Constructor
    PresidentialPardonForm (const std::string &target);

    // Getter
    std::string getTarget() const;
    // Setter
    void setTarget(std::string value);
    
    void execute(const Bureaucrat &executer) const;

};

std::ostream& operator<< (std::ostream &os, const PresidentialPardonForm &PPF);
