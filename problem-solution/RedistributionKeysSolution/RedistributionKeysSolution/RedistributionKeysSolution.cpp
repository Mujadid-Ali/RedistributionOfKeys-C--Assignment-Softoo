// RedistributionKeysSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

void printVector(std::vector<int> vec)
{
    std::cout << "\n Vector: {";
    for (auto ele : vec)
    {
        std::cout << ele << ", ";
    }
    std::cout << "}\n";
};
int main() {
    int MaxPasswords = 1000;
    std::vector<int> passVec = { 257, 1226, 852, 3117, 0, 1006, 991, 217, 1154, 1180 };
    printVector(passVec);
    int keyindex = 0;
    for (int i = 0; i < passVec.size(); i++)
    {
        int currentValue = passVec.at(i);
        int keyIndexvalue = passVec.at(keyindex);
        if (currentValue <= 1000)
        {
            if (passVec.at(keyindex) == MaxPasswords)
            {
                keyindex++;
            }
            //printVector(passVec);
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
                std::cout << "\nMove " << diff << " from key " << i << " to key " << keyindex << "\n";
            }
            else
            {
                while (diff > 0)
                {
                    if (remaingdiff > 0)
                    {
                        passVec.at(i) = passVec.at(i) - remaingdiff;
                        passVec.at(keyindex) = passVec.at(keyindex) + remaingdiff;
                        std::cout << "\nMove " << remaingdiff << " from key " << i << " to key " << keyindex << "\n";
                        diff -= remaingdiff;
                        //std::cout << "\ndiff: " << diff;
                        //std::cout << "\nremaindiff: " << remaingdiff;
                    }
                    keyindex++;
                    if (i != keyindex)
                    {

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
                        std::cout << "\nMove " << diff << " from key " << i << " to key " << keyindex << "\n";
                        diff -= remaingdiff;
                    }

                }
            }
        }
        //printVector(passVec);
    }
    printVector(passVec);
    return 0;
}