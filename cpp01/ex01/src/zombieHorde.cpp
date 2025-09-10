/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:29:15 by lgracia-          #+#    #+#             */
/*   Updated: 2025/09/07 13:46:26 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	void* array = ::operator new(sizeof(Zombie) * N);
	Zombie* n = static_cast<Zombie*>(array);
	for (int i = 0; i < N; i++)
		new(&n[i]) Zombie(name + (char)('0' + i));
	return (n);
}

void	announceHorde(int N, Zombie* n)
{
	for (int i = 0; i < N; i++)
		n[i].announce();
}

void	deleteHorde(int N, Zombie* n)
{
	for (int i = 0; i < N; i++)
		n[i].~Zombie();
	::operator delete (n);
}
