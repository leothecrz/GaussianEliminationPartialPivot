#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * @brief Function to print a 2D matrix
 * 
 * @param matrix 
 * @param rows 
 * @param cols 
 */
void printMatrix(float **matrix, int rows, int cols) ;

/**
 * @brief Function to print a 1D array of floats
 * 
 * @param arr 
 * @param cols 
 */
void printArray(float *arr, int cols) ;

/**
 * @brief Function to print a 1D array of integers
 * 
 * @param arr 
 * @param cols 
 */
void printArray(int *arr, int cols) ;

/**
 * @brief Function to check if a string contains only digits
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isPureNumber(const std::string str) ;

/**
 * @brief Function to check if a string represents a negative number
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isNegativeNumber(const std::string str) ;

/**
 * @brief Function to get the number of equations from the user
 * 
 * @return int 
 */
int getUserEquationCount() ; 

/**
 * @brief Function to validate a string (not implemented)

 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool stringIsValid(std::string str) ;

/**
 * @brief Function to get row coefficients manually from the user
 * 
 * @param rows 
 * @return std::vector<std::string> 
 */
std::vector<std::string> manualRows(int rows) ; 

/**
 * @brief Function to get row coefficients from a file

 * 
 * @param rows 
 * @return std::vector<std::string> 
 */
std::vector<std::string> fromFile(int rows) ;

/**
 * @brief Function to get user input for row coefficients
 * 
 * @param eCount 
 * @return std::vector<std::string> 
 */
std::vector<std::string> getUserInput(int eCount) ;

/**
 * @brief Function to split a string into a vector of substrings
 * 
 * @param str 
 * @return std::vector<std::string> 
 */
std::vector<std::string> splitString(const std::string& str) ;

/**
 * @brief Function to set up coefficient and B matrices from string data
 * 
 * @param matrix 
 * @param bmatrix 
 * @param stringArrays 
 * @return int 
 */
int setupCoeffiecientAndBMatrix(float** matrix, float* bmatrix, std::vector<std::string> stringArrays) ;

/**
 * @brief Function to perform Gaussian elimination and solve the system
 * 
 * @param matrix 
 * @param bmatrix 
 * @param mLength 
 * @return float* 
 */
float* gaussAndSolve(float** matrix, float* bmatrix, int mLength) ;