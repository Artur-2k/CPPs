/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:55 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:56 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS
#define CONTACT_CLASS

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkest_Secret;

    public:
        // Getters
        std::string get_firstName() const;
        std::string get_lastName() const;
        std::string get_nickname() const;
        std::string get_phoneNumber() const;
        std::string get_darkest_Secret() const;

        // Setters
        void set_firstName(const std::string &value);
        void set_lastName(const std::string &value);
        void set_nickname(const std::string &value);
        void set_phoneNumber(const std::string &value);
        void set_darkest_Secret(const std::string &value);

        // Methods
        void displayContact();

        // Constructors
        // default
        Contact();
};

#endif