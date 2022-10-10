#include <iostream>
using namespace std;
//create function that calculates inflation rate
float calculateInflationRate (float oldCPI, float newCPI)
{
	//call getCPIvalues function??
        float inflationRate;
        inflationRate = ((newCPI - oldCPI)/ oldCPI) * 100;
        return (inflationRate);
}

//make function to take average 
float averageInflRate (float & runningTotalVal, float counterNum)
{
        float average;
        average = runningTotalVal / counterNum;
        return (average);
}

//build get CPI values function
void getCPIvalues (float& oldCPIval, float& newCPIval) {
	do {
		cin >> oldCPIval >> newCPIval;

        	if ((oldCPIval <= 0) || (newCPIval <= 0))
        	{
                	cout << "Error: CPI values must be greater than 0" << endl;
        	}
	} while ((oldCPIval <= 0) || (newCPIval <= 0));
}

//make a swap function
void swap_values (float& num1, float& num2) {
	float temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

//sort array function
void sort_array(float array[], int size) {
	float maxNum;
	int i; 
	for (maxNum = size - 1; maxNum > 0; maxNum--) 
	{
		for (i = 0; i < maxNum; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_values(array[i], array[i + 1]);
			}
		}
	}
}

void print_array(float arrayVals[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arrayVals[i] << endl;
	}
}

//findMedianRate function (calculate median using sort_array)
float findMedianRate(float sortedArray[], int numOfElements) {
	float median;
	//call sort_array function
	sort_array(sortedArray, numOfElements);

	float arrayIndex1;
        float arrayIndex2;

	if (numOfElements % 2 == 0) {
		//even number
		arrayIndex2 = sortedArray[numOfElements / 2];
		arrayIndex1 = sortedArray[numOfElements / 2 - 1];
	       	median = ((arrayIndex1 + arrayIndex2) /2);
	}
	else if (numOfElements % 2 != 0) {
		//odd number
		median = sortedArray[numOfElements / 2 ];
	}
	return (median);
}

//begin main function
int main()
{
	float oldConsumerIndex;
        float newConsumerIndex;
        float inflRate;
        float inflRateAvg;
        float runningTotal;
        char userInput;
        int counter;
        float inflRateArray[20];
	float medianRate;

        runningTotal = 0.0;
        counter = 0;
        do {
		counter++;
                cout << "Enter the old and new consumer price indices: ";
                getCPIvalues(oldConsumerIndex, newConsumerIndex);

                // call calculate inflation rate function
                inflRate = calculateInflationRate(oldConsumerIndex, newConsumerIndex);

                cout << "Inflation rate is " << inflRate << endl;

                if ((oldConsumerIndex > 0 && newConsumerIndex > 0))
                {
                	cout << "Try again? (y or n): ";
                	cin >> userInput;
                }
                runningTotal += inflRate;

		// store calculated inflation rates in an array
		inflRateArray[counter - 1] = inflRate;
		for (int i = 0; i < counter; i++) {
		}
		
           } while ((userInput == 'y') && (userInput != 'n'));

	// find average inflation rate
           runningTotal = runningTotal;
           if (userInput == 'n') {
                   inflRateAvg = averageInflRate(runningTotal, counter);
                   cout << "Average rate is " << inflRateAvg << endl;
           }

	//call sort_array function
	sort_array(inflRateArray, counter);

	//call findMedian
        medianRate = findMedianRate(inflRateArray, counter);
        cout << "Median rate is " << medianRate << endl;

    return 0;
}
