/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:31 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 17:23:31 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag
{
	public:
		searchable_array_bag(){}
		searchable_array_bag(const searchable_array_bag& org): array_bag(org){}
		searchable_array_bag& operator=(const searchable_array_bag& org)
		{
			if (this != &org)
				array_bag::operator=(org);
			return  *this;
		}
		~searchable_array_bag(){}
		
	bool has(int val) const
	{
		for(int i = 0;i < size; i++)
		{
			if (data[i] == val)
				return true;
		}
		return false;
	}
};