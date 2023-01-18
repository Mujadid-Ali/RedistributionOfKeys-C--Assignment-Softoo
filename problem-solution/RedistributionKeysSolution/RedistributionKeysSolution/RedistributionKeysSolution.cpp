// RedistributionKeysSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>

#define FILE_NAME "data.csv"
int DESIRED_PASSWORD_PER_KEYS = 0;
int TOLARANCE_IN_PERCENTAGE = 0;
int TOLARANCE_VALUE = 0;

void printVector(std::vector<int>& vec)
{
    //std::cout << "{";
    int key = 0;
    std::cout << "Key \t Current Number of Passwords" << '\n';
    for (auto ele : vec)
    {
        std::cout << key << " \t " << ele << "\n";
        key++;
    }
    std::cout << "\n";
};
int vectSum(std::vector<int>& vec)
{
    int Sum = 0;
    for (auto ele : vec)
    {
        Sum += ele;
    }
    return Sum;
}
void printInitialInfo(std::vector<int>& vec)
{
    //taking tolarance value from user
    std::cout << "Enter Tolarance(%): ";
    std::cin >> TOLARANCE_IN_PERCENTAGE;

    if (TOLARANCE_IN_PERCENTAGE < 0 || TOLARANCE_IN_PERCENTAGE > 100)
    {
        std::cout << "\nYou have entered wrong value the correct value is (0-100).";
        TOLARANCE_IN_PERCENTAGE = 0;
        std::cout << "Using Tolarance default value: " << TOLARANCE_IN_PERCENTAGE;
    }

    TOLARANCE_VALUE = (TOLARANCE_IN_PERCENTAGE * DESIRED_PASSWORD_PER_KEYS) / 100;

    std::cout << "\n\n---------------------------------------------------------\n\n";
    printVector(vec);
    std::cout << "Total Passwords: " << vectSum(vec) << "\n";
    std::cout << "Total Desired Passwords: " << DESIRED_PASSWORD_PER_KEYS * vec.size() << "\n";
    std::cout << "Total Keys: " << vec.size() << "\n";
    std::cout << "Desired Passowrd Per Key: " << DESIRED_PASSWORD_PER_KEYS << "\n";
    std::cout << "Tolarance: " << TOLARANCE_IN_PERCENTAGE << "%" << "\n";
    std::cout << "Acceptable Passwords per keys: " << DESIRED_PASSWORD_PER_KEYS - TOLARANCE_VALUE << "-" << DESIRED_PASSWORD_PER_KEYS + TOLARANCE_VALUE << "\n";
    std::cout << "Moves: " << "\n";
    //std::cout << "\n\n---------------------------------------------------------\n\n";
};

std::vector<int> balanceVector(std::vector<int>& passVec)
{
    int MaxPasswords = DESIRED_PASSWORD_PER_KEYS + TOLARANCE_VALUE;
    int numOfMoves = 1;
    int keyindex = 0;
    for (int i = 0; i < passVec.size(); i++)
    {
        if (keyindex >= passVec.size())
        {
            std::cout << "The Total Number of passwords are greater than allowed password so program cannot balance more keys!\n\n";
            return passVec;
        }
        if (passVec.at(i) <= MaxPasswords)
        {
            if (passVec.at(keyindex) == MaxPasswords)
            {
                keyindex++;
            }
            continue;
        }
        else
        {
            int diff = passVec.at(i) - MaxPasswords;
            int remaingdiff = MaxPasswords - passVec.at(keyindex);
            if (diff < remaingdiff)
            {
                passVec.at(i) = passVec.at(i) - diff;
                passVec.at(keyindex) = passVec.at(keyindex) + diff;
                std::cout << "\n\t" << numOfMoves <<". Move " << diff << " from key " << i << " to key " << keyindex << "\n";
                numOfMoves++;
            }
            else
            {
                while (diff > 0)
                {
                    if (remaingdiff > 0)
                    {
                        passVec.at(i) = passVec.at(i) - remaingdiff;
                        passVec.at(keyindex) = passVec.at(keyindex) + remaingdiff;
                        std::cout << "\n\t" << numOfMoves << ". Move " << remaingdiff << " from key " << i << " to key " << keyindex << "\n\n";
                        diff -= remaingdiff;
                        numOfMoves++;
                        //std::cout << "\ndiff: " << diff;
                        //std::cout << "\nremaindiff: " << remaingdiff;
                    }
                    keyindex++;
                    if (i != keyindex)
                    {
                        if (keyindex >= passVec.size())
                        {
                            std::cout << "The Total Number of passwords are greater than allowed password so program cannot balance more keys!\n\n";
                            return passVec;
                        }
                        remaingdiff = MaxPasswords - passVec.at(keyindex);
                    }
                    else
                    {
                        remaingdiff = 0;
                    }
                    if (diff < remaingdiff)
                    {
                        passVec.at(i) = passVec.at(i) - diff;
                        passVec.at(keyindex) = passVec.at(keyindex) + diff;
                        std::cout << "\n\t" << numOfMoves << ". Move " << diff << " from key " << i << " to key " << keyindex << "\n";
                        diff -= remaingdiff;
                        numOfMoves++;
                    }

                }
            }
        }
        //printVector(passVec);
    }
    std::cout << "\n";
    return passVec;
}

std::vector<int> readDataFromCSVFile(std::string fileName)
{
    std::vector<int> passVec;
    std::ifstream file;
    std::string line;
    
    // Open an existing file
    file.open(fileName);
    /*while (!file.eof()) {
        file >> line;
        std::cout << line << " \n";
    }*/
    if (!file.is_open())
    {
        std::cout << "File:" << fileName << " is not open.";
        return passVec;
    }
    std::getline(file, line); // skip the first line
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;
        int index = 1;
        while (std::getline(iss, token, ','))
        {
            if (index == 3)
            {
                DESIRED_PASSWORD_PER_KEYS = std::stoi(token.c_str());
            }
            // process each token
            if (index % 2 == 0)
            {
                passVec.push_back(std::stoi(token.c_str()));
            }
            //std::cout << token << " \n";
            index++;
        }
        std::cout << std::endl;
    }
    //printVector(passVec);
    return passVec;
}

int main() {
    
    //std::vector<int> pass = readDataFromCSVFile("data.csv");
    std::vector<int> passVec = readDataFromCSVFile(FILE_NAME);//{ 257, 1226, 852, 3117, 0, 1006, 991, 217, 1154, 1180 };
    printInitialInfo(passVec);
    passVec = balanceVector(passVec);
    printVector(passVec);
    std::cout << "\n\n---------------------------------------------------------\n\n";
    return 0;
}