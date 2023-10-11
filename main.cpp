
#include "main.hpp"

int getUserEquationCount()
{
    int stringnum = 0;
    std::string input;
    do{
    do
    {
        std::cout << "How many equations will you be inputing?" << std::endl;
        std::getline(std::cin, input);
        std::cout << std::endl;
    } 
    while( !isPureNumber(input) );
    stringnum = stoi(input);
    }
    while(stringnum < 1);
    
    return stringnum;
}

std::vector<std::string> manualRows()
{
    std::vector<std::string> stringArray;

    int rows = getUserEquationCount();

    for(int i=0; i<rows; i++)
    {
        std::cout << "\n >";
        std::string in;
        std::getline(std::cin, in, '\n');
        if(!stringIsValid(in))
        {
            std::cout << "INVALID INPUT!!";
            i--;
            continue;
        }
        stringArray.push_back(in);
    }

    return stringArray;
}

std::vector<std::string> fromFile()
{

    std::vector<std::string> stringArray;
    std::string input;
    std::cout << "Enter file path:" << std::endl;
    std::getline(std::cin, input, '\n');

    std::ifstream inputFile(input);
    if( !inputFile.is_open() )
    {
        std::cout << "Failed To open file: " << input << std::endl;
        exit(1);
    }

    std::string activeString;
    int i = 0;
    while(inputFile.peek() != EOF)
    {
        std::getline(inputFile, activeString);
        if(!stringIsValid(activeString))
        {
            std::cout << "invalid line at line#: " << i+1 << std::endl;
            exit(1);
        }
        stringArray.push_back(activeString);
        i++;
    }
    inputFile.close();
    
    return stringArray;
}

std::vector<std::string> getUserInput()
{
    int val = -1;
    std::string input;
    do
    {
        do
        {
            std::cout << "Would you like to either:" << std::endl;
            std::cout << "0) Manualy Enter Row Coefficient" << std::endl;
            std::cout << "1) Give the path for a formatted text file." << std::endl;
            std::getline(std::cin, input);
        }
        while(!isPureNumber(input) || input.length() > 1);
        val = stoi(input);
    } while(val != 0 && val != 1);
    
    if(val == 0)
        return manualRows();
    else
        return fromFile();
}

bool isPureNumber(const std::string str)
{
    for(int i = 0; i < str.length(); i++ )
    {
        char c = str.at(i);
        if(c < 48 || c >57)
            return false;
    }
        
    return true;
}

bool isNegativeNumber(const std::string str)
{
    if(str.empty())
        return false;
    return (str[0] == '-') && (str.find_first_not_of("1234567890", 1) == std::string::npos);
}

int setupCoeffiecientAndBMatrix(float** matrix, float* bmatrix, std::vector<std::string> stringArrays)
{
    int matrixLength = splitString( stringArrays.at(0) ) .size() - 1; 

    for(int i=0; i<stringArrays.size(); i++)
    {
        matrix[i] = new float[matrixLength];

        std::string active = stringArrays[i] ;
        std::vector<std::string> activeSplitString = splitString( active );

        for(int j=0; j<matrixLength; j++)
        {
            if(isPureNumber(activeSplitString[j]) || isNegativeNumber(activeSplitString[j]))
                matrix[i][j] = stof(activeSplitString[j]);
            else
                exit(1); // ERROR
        }
        if(isPureNumber(activeSplitString[matrixLength]) || isNegativeNumber(activeSplitString[matrixLength]) )
            bmatrix[i] = stof( activeSplitString[matrixLength] );
        else
            exit(1); // ERROR
    }
    return matrixLength;
}

void printMatrix(float **matrix, int rows, int cols) 
{
    std::cout << "Matrix: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            std::cout << matrix[i][j] << " | ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}
template <class T>
void printArray(T *arr, int cols) 
{
    std::cout << "ARRAY: " << "\n";
    for (int j = 0; j < cols; j++) 
        std::cout << arr[j] << " | ";
    std::cout << std::endl;
}

std::vector<std::string> splitString(const std::string& str)
{
    std::istringstream stream(str);
    std::vector<std::string> splits;

    do
    {
        std::string active;
        stream >> active;
        if(active != "")
            splits.push_back(active);
    } 
    while (stream);
    
    return splits;
}

bool stringIsValid(std::string str)
{
    std::vector<std::string> parts = splitString(str);
    for (int i = 0; i < parts.size(); i++)
        if( !(isPureNumber(parts[i]) || isNegativeNumber(parts[i])) )
            return false;   
    return true;
}

float* gaussAndSolve(float** matrix, float* bmatrix, int mLength)
{
    float xMultiplier = 0;
    float r = 0;
    float rMax = 0;
    float sMax = 0;
    int n = mLength;

    float *scaleFactor = new float[n];
    float *output = new float[n];
    int *order = new int[n];

    for(int i=0; i<n; i++)
    {
        output[i] = 0;
        scaleFactor[i] = 0;
        order[i] = i;
    }

    std::cout << "\n" << " --Initial Coefficients and B-Array-- " << "\n";
    printMatrix(matrix, n,n);
    printArray<float>(bmatrix, n);
    std::cout << std::endl;

    int j=0;
    for(int i=0; i<n; i++)
    {
        sMax = 0;
        for(int z=0; z<n; z++)
            sMax = std::max( sMax,  std::abs(matrix[i][z]) );
        scaleFactor[i] = sMax;
    }
    std::cout << "\n" << " -- Scale Factors -- " << "\n";
    printArray<float>(scaleFactor, n);
    std::cout << std::endl;

    for(int k=0; k < n-1; k++)
    {
        rMax = 0;
        for(int i=k; i<n; i++)
        {
            r =  std::abs(matrix[ order[i] ][k] / scaleFactor[order[i]]);

            std::cout << "Scale Ratio of Equation#" << order[i]+1 << " : " << r << "\n";

            if (r >= rMax)
            {
                rMax = r;
                j = i;
            }
        }

        int temp = order[j];
        int temp2 = order[k];
        order[j] = order[k];
        order[k] = temp;

        std::cout << "Using EQ#" << order[k] + 1 << " Has Ratio: " << rMax << " \n";
        std::cout << std::endl;

        for(int i=k+1; i<n; i++)
        {
            xMultiplier = matrix[ order[i] ][k] / matrix[ order[k] ][k];
            
            matrix[ order[i] ][k] = xMultiplier;
            // It is assumed that matrix[order[i]][k] will be zeroed out by equation subtraction. So calculations are skiped.

            for(j=k+1; j<n; j++)
                matrix[ order[i] ][j] = matrix[ order[i] ][j] - (xMultiplier * matrix[ order[k] ][j]);
        }

        std::cout << "Matrix during step k=" << k << "\n";
        printMatrix(matrix, n,n);
        std::cout << "ORDER ";
        printArray<int>(order, n);
        std::cout << std::endl;

    }

    // BMatrix
    for(int k=0; k<n-1; k++)
        for(int i=k+1; i<n; i++)
            bmatrix[order[i]] = bmatrix[order[i]] - (matrix[order[i]][k] * bmatrix[order[k]]);

    output[n-1] = bmatrix[order[n-1]] / matrix[order[n-1]][n-1];

    for(int i=n-1; i>=0; i--)
    {
        float sum = bmatrix[order[i]];
        for(int k=i+1; k<n; k++)
            sum = sum - matrix[order[i]][k] * output[k];
        
        output[i] = sum / matrix[order[i]][i];
    }    
    
    std::cout << " -- Xn values -- " << "\n";
    for(int i=0; i<n; i++)
        std::cout << "Xn" << i+1 << " : " << output[i] << "\n";

    delete scaleFactor;
    delete order;
    return output;
}

int main(int charc, char** charv)
{
    //int equationCount = getUserEquationCount();
    std::vector<std::string>  returnVals =  getUserInput();
    int equationCount = returnVals.size();

    float **coeffiecientMatrix = new float* [equationCount];
    float *solveValues = new float[equationCount];
    int matrixLength = setupCoeffiecientAndBMatrix(coeffiecientMatrix, solveValues, returnVals);
    float* outputs = gaussAndSolve(coeffiecientMatrix, solveValues, equationCount);

    for(int i=0; i<equationCount; i++)
        delete coeffiecientMatrix[i];
    delete coeffiecientMatrix;
    delete solveValues;
    delete outputs;
}

