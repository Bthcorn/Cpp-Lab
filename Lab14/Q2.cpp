#include <iostream>
#include <vector>
#include <cmath>

int mySqrt(double x) {
    if (x==0) return 0;
    double left = 1;
    double right = x/2 + 1;
    double res;

    while (left <= right) {
        int mid = left + ((right-left)/2);
        if (mid<=x/mid){
            left = mid+1;
            res=mid;
        }
        else {
            right=mid-1;
        }
    }

    return res;
}

double Max(std::vector<int> numbers)
{
    int max = numbers[0];
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

double Min(std::vector<int> numbers)
{
    int min = numbers[0];
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    return min;
}

double Mean(std::vector<int> numbers)
{
    double sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum / numbers.size();
}

double Median(std::vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] > numbers[j])
            {
                std::swap(numbers[i], numbers[j]);
            }
        }
    }
    if (numbers.size() % 2 == 0)
    {
        return (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]) / 2;
    }
    else
    {
        return numbers[numbers.size() / 2];
    }
}

double StandardDeviation(std::vector<int> numbers)
{
    double mean = Mean(numbers);
    double sumOfSquares = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sumOfSquares += (numbers[i] - mean) * (numbers[i] - mean);
    }
    return sqrt(sumOfSquares / numbers.size());
}

int main()
{
    std::vector<int> numbers;
    float mean;
    float median;
    float max;
    float min;
    float sd;
    // enter number and end with character
    std::cout << "Enter numbers: ";
    int number;
    while (std::cin >> number)
    {
        numbers.push_back(number);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] > numbers[j])
            {
                std::swap(numbers[i], numbers[j]);
            }
        }
    }

    mean = Mean(numbers);
    median = Median(numbers);
    max = Max(numbers);
    min = Min(numbers);
    sd = StandardDeviation(numbers);
    
    // set two precision by multiplying by 100 and dividing by 100 convert to 2 decimal places
    // mean = (int)(mean * 100);
    mean = (float)((int)(mean * 100)) / 100;
    median = (float)((int)(median * 100)) / 100;
    sd = (int)(sd * 100);
    sd = (float)sd / 100;
    max = (int)(max * 100);
    max = (float)max / 100;
    min = (int)(min * 100);
    min = (float)min / 100;

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Standard Deviation: " << sd << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    return 0;
}