# RedistributionOfKeys-C--Assignment-Softoo

## Prerequists

- MS Visual Studio 2022

## How to run the program
The solution is developed in MS Visual Studio 2022. Its project solution is placed at */problem-solution/RedistributionKeysSolution*. if you have installed MS visual studio in your system you can run and test the program by performing following steps. 

- Go to */problem-solution/RedistributionKeysSolution/* path and double click on **RedistributionKeysSolution.sln**.
- First we need to provide input data. The program takes csv file as an input. the file input data csv file path should be *problem-solution/RedistributionKeysSolution/RedistributionKeysSolution*. I have already provided two test data files **data.csv** and **data1.csv**.
    - data.csv: contains the test data provided in **Assignment-C-Encryption.docx** file. 
    - data1.csv: contains the data which contains 66 more passwords for first 7 keys. 
by default the program usese **data.csv** file. 
- When program is open in MS Visual Studio then build and run the program. you can run the quickly by clicking on *Local Windows Debugger* button at middle top. 
- When program runs it will ask you to enter the tolarance value. Enter tolarance value and press ENTER.
- The Program will runs automatically and prints the expected output. 
- if you want to test the additonal 66 values data set just change the file name **data.csv** to **data1.csv** at line 10 in file **RedistributionKeysSolution.cpp**.
- if you want to test custom data then update the already present data files accordingly or provide a new file and update its name as above.