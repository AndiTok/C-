/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:08:47 by atok              #+#    #+#             */
/*   Updated: 2023/08/15 17:08:47 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Fixed abso(Fixed input)
// {
// 	if (input < 0)
// 		return input * -1;
// 	else 
// 		return input;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed areaABC = abso((a.get_x()*(b.get_y() - c.get_y())) +
// 						(b.get_x()*(c.get_y() - a.get_y())) +
// 						(c.get_x()*(a.get_y() - b.get_y())))/2;

//     Fixed areaPBC = abso((point.get_x()*(b.get_y() - c.get_y())) +
// 						(b.get_x()*(c.get_y() - point.get_y())) +
// 						(c.get_x()*(point.get_y() - b.get_y())))/2;

//     Fixed areaPCA = abso((point.get_x()*(c.get_y() - a.get_y())) +
// 						(c.get_x()*(a.get_y() - point.get_y())) +
// 						(a.get_x()*(point.get_y() - c.get_y())))/2;

//     Fixed areaPAB = abso((point.get_x()*(a.get_y() - b.get_y())) +
// 						(a.get_x()*(b.get_y() - point.get_y())) +
// 						(b.get_x()*(point.get_y() - a.get_y())))/2;

// 	std::cout << "ABC :" << areaABC << "\n";
// 	std::cout << "--------\n";
// 	std::cout << "PBC :" << areaPBC << "\n";
// 	std::cout << "PCA :" << areaPCA << "\n";
// 	std::cout << "PAB :" << areaPAB << "\n";
// 	std::cout << "--------\n";

//     Fixed totalArea = areaPBC + areaPCA + areaPAB;

// 	std::cout << "Total P :" <<totalArea << "\n";
// 	std::cout << "--------\n";

//     return totalArea == areaABC;
	
// 	// if divide by 2 all need to divide by 2 to get actual triangle area FYI
// 	// The formula for area of triangle formula in coordinate geometry/cartasien plane
// }

float abso(float input) //cant use abs() becase math header in fixed.hpp has abs() which we can't use
{
	if (input < 0)
		return input * -1;
	else 
		return input;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = abso((a.get_x().toFloat()*(b.get_y().toFloat() - c.get_y().toFloat())) +
						(b.get_x().toFloat()*(c.get_y().toFloat() - a.get_y().toFloat())) +
						(c.get_x().toFloat()*(a.get_y().toFloat() - b.get_y().toFloat())))/2;

    float areaPBC = abso((point.get_x().toFloat()*(b.get_y().toFloat() - c.get_y().toFloat())) +
						(b.get_x().toFloat()*(c.get_y().toFloat() - point.get_y().toFloat())) +
						(c.get_x().toFloat()*(point.get_y().toFloat() - b.get_y().toFloat())))/2;

    float areaPCA = abso((point.get_x().toFloat()*(c.get_y().toFloat() - a.get_y().toFloat())) +
						(c.get_x().toFloat()*(a.get_y().toFloat() - point.get_y().toFloat())) +
						(a.get_x().toFloat()*(point.get_y().toFloat() - c.get_y().toFloat())))/2;

    float areaPAB = abso((point.get_x().toFloat()*(a.get_y().toFloat() - b.get_y().toFloat())) +
						(a.get_x().toFloat()*(b.get_y().toFloat() - point.get_y().toFloat())) +
						(b.get_x().toFloat()*(point.get_y().toFloat() - a.get_y().toFloat())))/2;

	std::cout << "ABC :" << areaABC << "\n";
	std::cout << "--------\n";
	std::cout << "PBC :" << areaPBC << "\n";
	std::cout << "PCA :" << areaPCA << "\n";
	std::cout << "PAB :" << areaPAB << "\n";
	std::cout << "--------\n";

    float totalArea = areaPBC + areaPCA + areaPAB;

	std::cout << "Total P :" <<totalArea << "\n";
	std::cout << "--------\n";

    return totalArea == areaABC;
	
	// if divide by 2 all need to divide by 2 to get actual triangle area FYI
	// The formula for area of triangle formula in coordinate geometry/cartasien plane
}

/* 		    | x1  y1  1| | a b |
area =  1/2 | x2  y2  1| | c d |
		    | x3  y3  1| | e f |

		1/2	|(ad + cf + ed) - (ed + cb + af)|

area =  1/2 | x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3 |

area =  1/2 | x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1*y3 |

area =  1/2 | x1(y2-y3) + x2(y3-y1) + x3(y1-2) |

OR

		    | (x1 - x2) (x1 - x3) |  | a  b
area =  1/2 |		   X		  |  | cross multiply
		    | (y1 - y2) (y1 - y3) |  | c  d
		    
area =  1/2 | (x1 - x2) * (y1 - y3) | | a * d |
		    | (y1 - y2) * (x1 - x3) | | c * b |

area =  1/2 | (x1 - x2) * (y1 - y3) | - | (y1 - y2) * (x1 - x3) | |ad - bc| */
