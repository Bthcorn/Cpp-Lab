#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Mapper 
{
public:
    std::string filename;
    std::vector<std::string> words;
    std::vector<int> counts;

    Mapper(std::string filename) : filename(filename) {

    }
    void map() 
    {
        std::fstream file(filename);
        std::string word;
        while (file >> word)
        {
            // auto it = std::find(words.begin(), words.end(), word);
            // if (it != words.end())
            // {
            //     counts[it - words.begin()]++;
            // }
            // else
            // {
                words.push_back(word);
                counts.push_back(1);
            // }
        }
        file.flush();
        file.close();

    }

    void sort()
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i] > words[j])
                {
                    std::swap(words[i], words[j]);
                    std::swap(counts[i], counts[j]);
                }
            }
        }
    }

    void print();
};

class Reducer
{   
public:
    std::vector<std::string> words;
    std::vector<int> counts;

    Reducer(std::vector<std::string> words, std::vector<int> counts) : words(words), counts(counts) {}

    void reduce()
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i] == words[j])
                {
                    counts[i] += counts[j];
                    words.erase(words.begin() + j);
                    counts.erase(counts.begin() + j);
                }
            }
        }
    }

    void sort()
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (counts[i] < counts[j])
                {
                    std::swap(words[i], words[j]);
                    std::swap(counts[i], counts[j]);
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < words.size(); i++)
        {
            std::cout << words[i] << " " << counts[i] << std::endl;
        }
    }
};

void checkFile(std::string filename)
{
    if (!std::fstream(filename).is_open())
    {
        std::cout << "File not found!" << std::endl;
        std::cout << "Input the filename again: ";
        std::cin >> filename;
        checkFile(filename);
    }
}

void writeToFile(std::string filename, std::vector<std::string> words, std::vector<int> counts)
{
    std::fstream file(filename, std::ios::out);
    for (int i = 0; i < words.size(); i++)
    {
        file << words[i] << " " << counts[i] << std::endl;
    }
    file.close();
}

int main()
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    // handle the file
    if (std::fstream(filename).is_open())
    {
        Mapper mapper(filename);
        mapper.map();
        mapper.sort();
        Reducer reducer(mapper.words, mapper.counts);
        reducer.reduce();
        reducer.sort();
        reducer.print();
        std::string output = filename.substr(0, filename.find('.')) + "_mr.txt";
        writeToFile(output, reducer.words, reducer.counts);
    }
    else
    {
        std::cout << "File not found!" << std::endl;
    }
    return 0;
}