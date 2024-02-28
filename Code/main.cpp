#include "structure.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

//main function
int main() 
{
    string fileName = "admissionsdata.csv";

    //parse CSV file to get list of applicants
    vector<Applicant> applicants = parseCSV(fileName);

    //create hash table to store applicant details
    unordered_map<int, Applicant> applicantMap;
    for (const auto& applicant : applicants) 
    {
        applicantMap[applicant.serialNo] = applicant;
    }

    //create bst and populate it with applicants based on chance of admit
    BST bst;
    for (const auto& applicant : applicants) 
    {
        bst.insert(applicant);
    }

    //example 1: get top N number of applicants
    int N = 5;
    bst.getTopNApplicants(N, applicantMap);

    //example 2: search by attribute like GRE score
    int targetGRE = 300;
    bool found = false;

    for (const auto& applicant : applicants) 
    {
        if (applicant.greScore == targetGRE) 
        {
            bst.printApplicantDetails(applicant);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Applicant with GRE Score " << targetGRE << " not found." << endl;
    }

    //example 3: applicants above certain threshold
    double threshold = 0.8;
    bst.findApplicantsAboveThreshold(threshold, applicantMap);

    return 0;
}