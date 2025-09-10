/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:18:10 by lgracia-          #+#    #+#             */
/*   Updated: 2025/09/06 17:21:47 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " was shot down" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraaiiiiiiinnnzzzZ..." << std::endl;
}
