/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:23:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/12 18:04:14 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;
    public:
    Bureaucrat() : _name("unknown"), _grade(0) {};
    Bureaucrat(const Bureaucrat &other) { *this = other; };
    ~Bureaucrat();
    Bureaucrat operator=(const Bureaucrat &other) 
    {
        if (this != &other)
        {
            this->_name = other._name;
            this->_grade = other._grade;
        }
        return *this;
    }
        
    class GradeTooHighException : std::exception
    {
        public:
            virtual const char* what() const throw(){
                return "Grade is Too High";
            }
    };
    
    class GradeTooLowException : std::exception
    {
        public:
            virtual const char* what() const throw(){
                return "Grade is Too Low";
            }
    };
};