/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:59 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 17:23:59 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &bag;
	public:
		set(searchable_bag& b) : bag(b){}
		~set()
		{
			bag.clear();
		}

		void insert(int val)
		{
			if (!bag.has(val))
				bag.insert(val);
		}

		void insert(int *tab, int size)
		{
			for(int i = 0; i < size; i++)
			{
				if (!bag.has(tab[i]))
					bag.insert(tab[i]);
			}
		}

		bool has(int val) const
		{
			return (bag.has(val));
		}

		void print() const 
		{
			bag.print();
		}

		searchable_bag& get_bag() const
		{
			return bag;
		}

		void clear()
		{
			bag.clear();
		}

};