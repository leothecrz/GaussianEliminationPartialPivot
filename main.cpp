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
    float *scaleFactor = new float[n];
    int *order = new int[n];
    float *output = new float[n];

    for(int i=0; i<n; i++)
    {
        output[i] = 0;
        scaleFactor[i] = 0;
        order[i] = i;
        coeffiecientArray[i] = new float[n];

        solveValues[i] = (rand() % 100) + 1;
        for(int j=0; j<n; j++)
            coeffiecientArray[i][j] = (rand() % 100) + 2;

    }
    printMatrix(coeffiecientArray, n,n);


    float xMultiplier, r, rMax, sMax;
    int j=0;
    for(int i=0; i<n; i++)
    {
        sMax = 0;
        for(int j=1; j<n; j++)
            sMax = std::max(sMax,  std::abs(coeffiecientArray[i][j]));
        scaleFactor[i] = sMax;
    }

    for(int k=1; k < n-1; k++)
    {
        
        for(int i=k; i<n; i++)
        {
            r = coeffiecientArray[order[i]][k] / scaleFactor[order[i]];
            if (r > rMax)
            {
                rMax = r;
                j = i;
            }
        }

        int temp = order[j];
        order[j] = order[k];
        order[k] = temp;

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
    printArray(scaleFactor, n);
    

    for(int k =1; k<n-1; k++)
        for(int i =k+1; i<n; i++)
            solveValues[order[i]] = solveValues[order[i]] - (coeffiecientArray[order[k]][k] * solveValues[order[k]]);

    output[n-1] = solveValues[order[n-1]] / coeffiecientArray[order[n-1]][n-1];

    for(int i=n-1; i>1; i--)
    {
        float sum = solveValues[order[i]];
        for(int k=i+1; k<n; i++)
            sum = sum - coeffiecientArray[order[i]][k] * output[k];
        
        output[i] = sum / coeffiecientArray[order[i]][i];

    }    
    
    printArray(output, n);

}

