/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:26:46 by tpandya           #+#    #+#             */
/*   Updated: 2025/09/06 16:26:52 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// --- ANSI reset and style codes --- //
# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define UNDERLINE "\033[4m"

/*
* RED:       Error/critical warnings
* GREEN:     Prompt/success messages
* YELLOW:    warnings/debug
* BLUE:      info messages
* MAGENTA:   Execution debug
* CYAN:      FD, Parsing and Tokenization Debug
*/
// --- Text colors --- //
# define RED     "\033[31m"    
# define GREEN   "\033[32m"   
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

#endif // COLORS_H
