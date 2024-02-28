#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "parser.h"

//node struct to define applicant
struct Node 
{
    Applicant data;
    Node* left;
    Node* right;
};

//bst class implementation with functions
class BST 
{
    private:
    Node* root;

    Node* insertHelper(Node* node, const Applicant& applicant) //helper function to be used simply in actual insert function
    {
        if(node == nullptr) 
        {
            return new Node{applicant, nullptr, nullptr};
        }
        if(applicant.chanceOfAdmit <= node->data.chanceOfAdmit) 
        {
            node->left = insertHelper(node->left, applicant); //recursive call to insert in left tree
        } 
        else 
        {
            node->right = insertHelper(node->right, applicant); //recursive call to insert in right tree
        }
        return node;
    }

    void traverseHelper(Node* node) //helper function to be used simply in actual traverse function
    {
        if (node == nullptr) 
        {
            return;
        }
        traverseHelper(node->left); //recursive call to traverse left of tree
        //printApplicantDetails(node->data))
        traverseHelper(node->right); //recursive call to traverse right of tree
    }

    void getTopNApplicantsHelper(Node* node, int N, vector<Applicant>& topNApplicants) //function to get top N number of applicants; to be used simply in actual function
    {
        if(node == nullptr || topNApplicants.size() >= N) 
        {
            return;
        }
        getTopNApplicantsHelper(node->right, N, topNApplicants); //recursive call to traverse and search right of tree
        if(topNApplicants.size() < N) 
        {
            topNApplicants.push_back(node->data);
        }
        getTopNApplicantsHelper(node->left, N, topNApplicants); //recursive call to traverse and search left of tree
    }

    void findApplicantsAboveThresholdHelper(Node* node, double threshold, unordered_map<int, Applicant>& applicantMap) //function to find applicants above specific threshold; to be used simply in actual function
    {
        if(node == nullptr) 
        {
            return;
        }
        findApplicantsAboveThresholdHelper(node->right, threshold, applicantMap); //recursive call to traverse and search right of tree
        if(node->data.chanceOfAdmit > threshold) 
        {
            printApplicantDetails(applicantMap[node->data.serialNo]);
        }
        findApplicantsAboveThresholdHelper(node->left, threshold, applicantMap); //recursive call to traverse and search left of tree
    }

    public:
    BST() : root(nullptr) {} //defauly constructor

    //function to insert applicant into bst
    void insert(const Applicant& applicant) 
    {
        root = insertHelper(root, applicant);
    }

    //function to traverse bst in-order
    void traverse() 
    {
        traverseHelper(root);
    }

    //function to get top N number of applicants
    void getTopNApplicants(int N, unordered_map<int, Applicant>& applicantMap) 
    {
        vector<Applicant> topNApplicants;
        getTopNApplicantsHelper(root, N, topNApplicants);
        for (const auto& applicant : topNApplicants) 
        {
            printApplicantDetails(applicantMap[applicant.serialNo]);
        }
    }

    //function to find applicants above certain threshold
    void findApplicantsAboveThreshold(double threshold, unordered_map<int, Applicant>& applicantMap) 
    {
        findApplicantsAboveThresholdHelper(root, threshold, applicantMap);
    }

    //function to print applicant details to console
    void printApplicantDetails(const Applicant& applicant) 
    {
        cout << "Serial No.: " << applicant.serialNo << endl;
        cout << "GRE Score: " << applicant.greScore << endl;
        cout << "TOEFL Score: " << applicant.toeflScore << endl;
        cout << "University Rating: " << applicant.universityRating << endl;
        cout << "SOP: " << applicant.sop << endl;
        cout << "LOR: " << applicant.lor << endl;
        cout << "CGPA: " << applicant.cgpa << endl;
        cout << "Research: " << applicant.research << endl;
        cout << "Chance of Admit: " << applicant.chanceOfAdmit << endl;
        cout << "-------------------------" << endl;
    }
};

#endif

