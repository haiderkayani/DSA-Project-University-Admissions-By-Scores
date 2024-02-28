#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//define struct for admission data
struct Applicant
{
    int serialNo;
    int greScore;
    int toeflScore;
    int universityRating;
    int sop;
    int lor;
    float cgpa;
    int research;
    float chanceOfAdmit;
};

//function to parse CSV file and return vector of Admission structs
vector<Applicant> parseCSV(string fileName) 
{
    vector<Applicant> applicants;
    string line;
    ifstream file(fileName);

    //skip first line 
    getline(file, line);

    while (getline(file, line)) 
    {
        vector<std::string> row;
        string cell;
        istringstream lineStream(line);

        while (getline(lineStream, cell, ',')) 
        {
            row.push_back(cell);
        }

        Applicant applicant;
        applicant.serialNo = stoi(row[0]);
        applicant.greScore = stoi(row[1]);
        applicant.toeflScore = stoi(row[2]);
        applicant.universityRating = stoi(row[3]);
        applicant.sop = stod(row[4]);
        applicant.lor = stod(row[5]);
        applicant.cgpa = stod(row[6]);
        applicant.research = stoi(row[7]);
        applicant.chanceOfAdmit = stod(row[8]);
        applicants.push_back(applicant);
    }
    return applicants;
}

#endif  

