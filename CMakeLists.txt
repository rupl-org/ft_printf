cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf ft_printf.h ft_utilities.c ft_parsing.c ft_printf.c ft_parsing_conversion.c ft_conversion_c.c ft_conversion_s.c)
