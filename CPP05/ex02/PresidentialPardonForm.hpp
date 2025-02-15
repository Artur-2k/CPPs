/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:29:37 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 22:57:26 by fang             ###   ########.fr       */
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
    
    virtual void execute(const Bureaucrat &executer) const = 0;

};

std::ostream& operator<< (std::ostream &os, const PresidentialPardonForm &PPF);
