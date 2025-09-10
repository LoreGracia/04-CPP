/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:29:12 by lgracia-          #+#    #+#             */
/*   Updated: 2025/09/07 13:44:48 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );
void	deleteHorde(int N, Zombie* n);
void	announceHorde(int N, Zombie* n);

int	main()
{
	int	N = 4;
	Zombie *horde = zombieHorde(N, "Zombie");
	announceHorde(N, horde);
	deleteHorde(N, horde);
}
