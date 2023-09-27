#include <iostream>

void printMatrix(float **matrix, int rows, int cols) 
{
    std::cout << "Matrix: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void printArray(float *arr, int cols) 
{
    std::cout << "ARRAY: " << "\n";
    for (int j = 0; j < cols; j++) 
        std::cout << arr[j] << " ";
    std::cout << std::endl;
}

int main(int charc, char** charv){

    int n = 5;
    float **coeffiecientArray = new float*[n];
    float *solveValues = new float[n];
    for(int i=0; i<n; i++)
    {
        coeffiecientArray[i] = new float[n];
        solveValues[i] = (rand() % 100) + 1;
        for(int j=0; j<n; j++)
            coeffiecientArray[i][j] = (rand() % 100) + 2;
    }
    printMatrix(coeffiecientArray, n,n);

    float xMultiplier;
    for(int k=1; k < n-1; k++)
    {
        for(int i=k+1; i<n; i++)
        {
            xMultiplier = coeffiecientArray[i][k] / coeffiecientArray[k][k];
            coeffiecientArray[i][k] = xMultiplier;

            for(int j=k+1; j<n; j++)
                coeffiecientArray[i][j] = coeffiecientArray[i][j] - (xMultiplier * coeffiecientArray[k][j]);
            
            solveValues[i] = solveValues[i] - (solveValues[k] * xMultiplier);
        }
    }


    printMatrix(coeffiecientArray, n,n);
    printArray(solveValues, n);

}

