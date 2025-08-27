/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:22 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 19:29:07 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2{

    private : 
        int x,y;
    public :
        vect2() : x(0), y(0){};
        vect2(int x, int y) : x(x), y(y){};
        vect2(const vect2& v)
        {
            x = v.x;
            y = v.y;
        }
        vect2& operator=(const vect2 &v)
        {
            if (*this != v)
            {
                x = v.x;
                y = v.y;
            }
            return (*this);
        } 
        ~vect2(){};
        
        friend std::ostream& operator<<(std::ostream &COUT, const vect2& v)
        {
            COUT << "{" << v[0] << ", " << v[1] << "}";
            return COUT;
        }

        int& operator[](int i)
        {
            return (i == 0 ? x : y);
        }

        int operator[](int i) const
        {
            return (i == 0 ? x : y);
        }

        bool operator==(const vect2& v)
        {
            return (x == v.x && y == v.y);
        }

        bool operator!=(const vect2& v)
        {
            return !(*this == v);
        }

        vect2 operator++(int)
        {
            vect2 tmp = *this;
            x += 1;
            y += 1;
            return tmp;
        }

        vect2& operator++()
        {
            x += 1;
            y += 1;
            return *this;
        }

        vect2 operator--(int)
        {
            vect2 tmp = *this;
            x -= 1;
            y -= 1;
            return tmp;
        }
    
        vect2& operator--()
        {
            x -= 1;
            y -= 1;
            return *this;
        }

        vect2& operator+=(const vect2& v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        vect2& operator-=(const vect2& v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        vect2& operator*=(int n)
        {
            x *= n;
            y *= n;
            return *this;
        }
         vect2 operator+(const vect2& v) const
         {
            return vect2(x + v.x, y +v.y);
         }

         vect2 operator-(const vect2& v) const
         {
            return vect2(x - v.x, y - v.y);
         }

         vect2 operator*(int n) const
         {
            return vect2(x * n, y * n);
         }

         friend vect2 operator*(int n, const vect2 &v)
         {
            return vect2(v.x * n, v.y * n);
         }

         vect2 operator-()
         {
            return vect2(-x, -y);
         }
};