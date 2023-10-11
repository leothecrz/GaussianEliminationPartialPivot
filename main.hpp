#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>

/**
 * @brief This function prompts the user to enter the number of equations they will be inputting.
 * It ensures that a valid positive integer is provided before returning it.
 * 
 * @return int - equation count
 */
int getUserEquationCount();

/**
 * @brief This function allows the user to manually input the coefficients of the equations.
 * It calls getUserEquationCount() to determine the number of equations to input.
 * It validates the input strings to ensure they contain valid numbers.
 * 
 * @return std::vector<std::string> - string vector of user input 
 */
std::vector<std::string> manualRows();

/**
 * @brief This function reads coefficients from a file specified by the user.
 * It prompts the user to enter the file path and then attempts to open and read the file.
 * It checks the validity of the lines read from the file.
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> fromFile();

/**
 * @brief This function prompts the user to choose between manual input or input from a file.
 * It returns the result of either manualRows() or fromFile() based on the user's choice.
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> getUserInput();

/**
 * @brief This function checks if a string contains only numeric characters.
 * 
 * @param str - string to be checked
 * @return true - a positive num
 * @return false - NaN
 */
bool isPureNumber(const std::string str);

/**
 * @brief This function checks if a string represents a negative number.
 * 
 * @param str - string to be checked
 * @return true - a negative num
 * @return false - NaN
 */
bool isNegativeNumber(const std::string str);

/**
 * @brief This function extracts coefficients and constants from the input strings and populates the coefficient matrix and b-matrix.
 * 
 * @param matrix - Coefficient Matrix
 * @param bmatrix - Results Array
 * @param stringArrays - User INPUT VECTOR
 * @return int 
 */
int setupCoeffiecientAndBMatrix(float** matrix, float* bmatrix, std::vector<std::string> stringArrays);

/**
 * @brief This function prints a matrix to the console.
 * 
 * @param matrix 
 * @param rows 
 * @param cols 
 */
void printMatrix(float **matrix, int rows, int cols) ;

/**
 * @brief This function is a template for printing an array.
 * 
 * @tparam T 
 * @param arr 
 * @param cols 
 */
template <class T>
void printArray(T *arr, int cols) ;

/**
 * @brief This function splits a string into a vector of strings based on whitespace.
 * 
 * @param str 
 * @return std::vector<std::string> 
 */
std::vector<std::string> splitString(const std::string& str);

/**
 * @brief This function checks if a string contains ONLY valid numeric values.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool stringIsValid(std::string str);

/**
 * @brief This function performs the Gaussian Elimination method to solve the system of linear equations.
 * 
 * @param matrix 
 * @param bmatrix 
 * @param mLength 
 * @return float* 
 */
float* gaussAndSolve(float** matrix, float* bmatrix, int mLength);

/**
 * @brief This is the main entry point of the program.
 * It gets the user's input or input from a file,
 * sets up the coefficient matrix and b-matrix,
 * solves the system,
 * and then deallocates memory.
 * @param charc 
 * @param charv 
 * @return int 
 */
int main(int charc, char** charv);

