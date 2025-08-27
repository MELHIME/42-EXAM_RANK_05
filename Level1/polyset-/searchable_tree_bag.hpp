/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:40 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 17:23:40 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp" 

class searchable_tree_bag : public searchable_bag, public tree_bag
{
	public:
	searchable_tree_bag(){};
	searchable_tree_bag(const searchable_tree_bag& org) : tree_bag(org){};
	searchable_tree_bag& operator=(const searchable_tree_bag& org)
	{
		if (this != &org)
		{
			tree_bag::operator=(org);
		}
		return *this;
	}
	~searchable_tree_bag(){}

	bool has(int val) const
	{
		node *now = tree;
		while(now)
		{
			if(now->value == val)
				return true;
			else if (val > now->value)
				now = now->r;
			else
			 	now = now->l;
		}
		return false;
	}
};