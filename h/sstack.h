#ifndef STACK_H
#define STACK_H
/*********************************/
#define MAX_SIZE 1000

/***********************************/
#include <iostream>
using namespace std;
#include<string>

typedef struct
{
     string name;
     string type;
}Tag;

typedef struct
{
     string name;
     int LineNumber;
}TagForError;



typedef struct staack
{
    int stack_pointer;
    string name[MAX_SIZE];

}Staack;



typedef enum Status
{
    Ok,
    NotOk,
    Full,
    NotFull,
    Empty,
    NotEmpty
}Status;
/*************************************/

Status Stack_Init(Staack* StackAddress);

Status is_Full(Staack* StackdAress);
Status is_Empty(Staack* StackAddress);

Status Push(Staack* StackAddress, string n);
string Pop(Staack* StackAddress);
string Top(Staack* StackAddress);

Status Stack_Display(Staack* StackAddress);
Status Stack_Size(Staack* StackAddress);
int Size_Of(Staack* StackAddress);
string Element(Staack* StackAddress, int ptr);
bool Search(Staack* StackAddress, string tag);
bool areStringsEqual(const std::string& str1, const std::string& str2);

#endif // STACK_H


