/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapEngineVersion
*/

#ifndef KAPENGINEVERSION_HPP_
#define KAPENGINEVERSION_HPP_

//define KapEngine version
/**
 * @brief KapEngine major version
 * @return int value
*/
#define KAPENGINE_VERSION_MAJOR 1
/**
 * @brief KapEngine minor version
 * @return int value
*/
#define KAPENGINE_VERSION_MINOR 215
/**
 * @brief KapEngine version
 * @return string value
 */
#define KAPENGINE_VERSION "1.2.15"


#define IS_KAPENGINE_VERSION(x, y) (KAPENGINE_VERSION_MAJOR != x)? false : (KAPENGINE_VERSION_MINOR != y)? false : true
#define IS_MAX_KAPENGINE_VERSION(x, y) (KAPENGINE_VERSION_MAJOR < x)? true : (KAPENGINE_VERSION_MAJOR > x)? false : (KAPENGINE_VERSION_MINOR <= y)? true : false
#define IS_MIN_KAPENGINE_VERSION(x, y) (KAPENGINE_VERSION_MAJOR < x)? false : (KAPENGINE_VERSION_MAJOR > x)? true : (KAPENGINE_VERSION_MINOR < y)? false : true


#endif /* !KAPENGINEVERSION_HPP_ */
