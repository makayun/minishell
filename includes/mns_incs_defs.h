/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mns_incs_defs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:53:16 by mmakagon          #+#    #+#             */
/*   Updated: 2024/04/24 13:55:50 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNS_INCS_DEFS_H
# define MNS_INCS_DEFS_H

// # include <stdlib.h>
// # include <string.h>
// # include <sys/types.h>
// # include <unistd.h>
// # include <termios.h>
// # include <term.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/param.h>

# define PROMPT "\x1B[36m[minishell] \x1B[35m[ =) ] \x1B[36m~> \x1B[0m"
// the lenght is 42 =)

# define GLOBAL_EXEC        0x0001
# define LOCAL_EXEC         0x0002
# define BUILTIN_EXEC       0x0004
# define IN_OPERATOR        0x0008
# define HERE_DOC           0x0010
# define OUT_OPERATOR       0x0020
# define OUT_APPEND_OPRTR   0x0040
# define COM_CD             0x0080
# define COM_ECHO           0x0100
# define COM_ENV            0x0200
# define COM_EXIT           0x0400
# define COM_EXPORT         0x0800
# define COM_PWD            0x1000
# define COM_UNSET          0x2000

# define META_CHARACTERS "|&;()<>"

# ifdef MACOS
#  include </usr/local/Homebrew/Cellar/readline/8.2.10/include/readline/readline.h>
# endif

#endif
