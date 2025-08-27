/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:24:14 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 19:28:21 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>

class bigint{
    public:

    std::deque<int> numbers;
    bigint() : numbers(1) {}
    bigint(size_t n)
    {
        while (n)
        {
            numbers.push_front((n % 10));
            n /= 10;
        }
        if (numbers.empty())
            numbers.push_front(0);
    }
    bigint(const bigint& org) : numbers(org.numbers){}
    bigint& operator=(const bigint& org)
    {
        numbers = org.numbers;
        return (*this);
    }

    bigint operator+(const bigint& bg) const
    {
        return add(bg);
    }

    bigint operator-(const bigint& org) const
    {
        (void) org;
        return bigint(0);
    }

    bigint& operator+=(const bigint& bg)
    {
        *this = add(bg);
        return *this;
    }

    bigint operator++(int)
    {
        bigint tmp = *this;
        *this = add(bigint(1));
        return tmp;
    }

    bigint& operator++()
    {
        *this = add (bigint(1));
        return (*this);
    }

    bool operator==(const bigint& bg)
    {
        return (numbers == bg.numbers);
    }

    bool operator!=(const bigint& bg)
    {
        return !(*this == bg);
    }

    bool operator<(const bigint& bg)
    {
        if (numbers.size() != bg.numbers.size())
            return (numbers.size() < bg.numbers.size());
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] != bg.numbers[i])
                return (numbers[i] < bg.numbers[i]);
        }
        return false;
    }

    bool operator>(const bigint& bg)
    {
        return !(*this < bg || *this == bg);
    }

    bool operator<=(const bigint& bg)
    {
        return !(*this > bg);
    }

    bool operator>=(const bigint& bg)
    {
        return !(*this < bg);
    }

    bigint operator<<(int lshf) const
    {
        bigint tmp = *this;
        if (numbers.size() == 1 && numbers[0] == 0)
            return tmp;
        for (int i = 0 ; i < lshf; i++)
            tmp.numbers.push_back(0);
        return tmp;
    }

    bigint operator>>(int rshf) const
    {
        bigint tmp = *this;
        if (numbers.size() == 1 && numbers[0] == 0)
            return tmp;
        for (int i = 0; i < rshf; i++)
        {
            if (!tmp.numbers.empty())
                tmp.numbers.pop_back();
            else
                return bigint(0);
        }
        return tmp;
    }

        bigint operator<<(const bigint& lshf) const
    {
        bigint tmp = *this;
        if (numbers.size() == 1 && numbers[0] == 0)
            return tmp;
        for (bigint i = 0 ; i < lshf; i++)
            tmp.numbers.push_back(0);
        return tmp;
    }

        bigint operator>>(const bigint& rshf) const
    {
        bigint tmp = *this;
        if (numbers.size() == 1 && numbers[0] == 0)
            return tmp;
        for (bigint i = 0; i < rshf; i++)
        {
            if (!tmp.numbers.empty())
                tmp.numbers.pop_back();
            else
                return bigint(0);
        }
        return tmp;
    }

        bigint& operator<<=(int lshf)
    {
        if (numbers.size() == 1 && numbers[0] == 0)
            return *this;
        for (int i = 0 ; i < lshf; i++)
            numbers.push_back(0);
        return *this;
    }

        bigint& operator>>=(int rshf)
    {
        if (numbers.size() == 1 && numbers[0] == 0)
            return *(this);
        for (int i = 0; i < rshf; i++)
        {
            if (!numbers.empty())
                numbers.pop_back();
            else
            {
                numbers.push_front(0);
                return *this;
            }
        }
        return *this;
    }

            bigint& operator<<=(const bigint& lshf)
    {
        if (numbers.size() == 1 && numbers[0] == 0)
            return *this;
        for (bigint i = 0 ; i < lshf; i++)
            numbers.push_back(0);
        return *this;
    }

            bigint& operator>>=(const bigint& rshf)
    {
        if (numbers.size() == 1 && numbers[0] == 0)
            return *(this);
        for (bigint i = 0; i < rshf; i++)
        {
            if (!numbers.empty())
                numbers.pop_back();
            else
            {
                numbers.push_front(0);
                return *this;
            }
        }
        return *this;
    }

private :
    bigint add (const bigint& other) const
    {
        bool other_is_larger = (numbers.size() < other.numbers.size());

        const bigint& smaller = (other_is_larger ? *this : other);
        bigint larger = (other_is_larger ? other : *this);

        size_t offset = larger.numbers.size() - smaller.numbers.size();

        for (int ix = (smaller.numbers.size() - 1); ix >= 0; ix--)
        {
            size_t j = ix + offset;
            int digit = smaller.numbers[ix];
            larger.numbers[j] += digit;

            while (larger.numbers[j] > 9)
            {
                larger.numbers[j] -= 10;
                if (j == 0)
                {
                    larger.numbers.push_front(1);
                    offset++;
                }
                else {
                    --j;
                    larger.numbers[j] += 1;
                }
            }
        }
        return larger;
    }

    friend std::ostream& operator<<(std::ostream& COUT, const bigint& bg)
    {
        for (size_t i = 0; i < bg.numbers.size(); i++)
            COUT << bg.numbers[i] ;
        return COUT;
    }
};