#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include<string>
using namespace std;
/************************************************************************/
void open(string Block);
void close(string Block );
/************************************************************************/

bool areStringsEqual(const std::string& str1, const std::string& str2) {
    return str1 == str2;
}
/************************************************************************/
Staack stackofblocks;
Staack st1;

Tag tag[1000];
int counter=0;
int main()
{



   string filePath = "input.txt";
  ifstream inputFile(filePath);

        // File is open, proceed to read its content
        // Read and print each line in the file
        stringstream buffer;
        buffer << inputFile.rdbuf();

        string fileContents = buffer.str();
/************************************************************/
//tags type
Stack_Init(&st1);
string Block;
int y;
  for (int x=0  ;x<fileContents.length(); x++)
    {
       if (fileContents[x]=='<')
         {      y=1;
                 while (fileContents[x+y]!='>')
                  {
                    Block=Block+fileContents[x+y];
                        y++;
                   }
                     y=1;

                    Push(&st1,Block);
                    Block.clear();
        }

    }

    for (int i =0; i < Size_Of(&st1) ; i++)
    {
        if(Element(&st1,i)[0]!='/')
        {
            if(("/"+Element(&st1,i)) == Element(&st1,i+1))
            {
                //cout<<Element(&st1,i)<<" is a data\n";
                tag[counter].name= Element(&st1,i);
                tag[counter].type= "data";
                counter++;

            }
            else
            {
                string OpenElement=st1.name[i+1];
                string CloseElement="/"+st1.name[i+1];

                     for (int j = 1+i; j<Size_Of(&st1); j++)
                     {
                           if(Element(&st1,j)!=CloseElement)
                                 continue;
                           else if((Element(&st1,j+1)==OpenElement))
                                {
                                    //cout<<Element(&st1,i)<<" is a list\n";
                                    tag[counter].name= Element(&st1,i);
                                    tag[counter].type= "list";
                                    counter++;

                                    break;
                                }
                              else
                                {
                                    //cout<<Element(&st1,i)<<" is an object\n";
                                    tag[counter].name= Element(&st1,i);
                                    tag[counter].type= "object";
                                    counter++;
                                    break;
                                }


                     }
            }

        }

    }
    Block.clear();

/**********************************************************************************************************/

//loop on tags to detect lists which have 1 object
for(int i =0; i<counter ; i++)
{
    if(tag[i].type=="list")
        {
              for(int j =0; j<counter ; j++)
               {
                if((tag[j].name==tag[i].name) &&tag[j].type=="object")
                {
                    tag[j].type="list";
                }
               }
        }
}

/***********************************************************/
Stack_Init(&stackofblocks);
cout<<"{\n";
  for (int x=0  ;x<fileContents.length(); x++)
    {
       if (fileContents[x]=='<'&& fileContents[x+1]!='/') //openning tag
         {    y=1;
             while (fileContents[x+y]!='>')
                  {
                    Block=Block+fileContents[x+y];
                        y++;
                   }
                    //cout<<Block<<"\n";

                    cout<<"\"";
                    cout<<Block;
                    x=x+Block.length()+1;
                    open(Block);
                    Block.clear();

        }
        else if(fileContents[x]=='<'&& fileContents[x+1]=='/')//closing tag
        {    y=2;
            while (fileContents[x+y]!='>')
                  {
                    Block=Block+fileContents[x+y];
                        y++;
                   }
                   x=x+Block.length()+2;
                    close(Block);
                    Block.clear();

        }

        else
        {
          cout<<fileContents[x];

        }

   }
   cout<<"}";
//cout<<"********************************************************************************************************************\n";
//
//for(int i=0; i<counter; i++)
//{
//    cout<<"name of tag :"<<tag[i].name<<"\n";
//    cout<<"type of tag :"<<tag[i].type<<"\n";
//    cout<<"********\n";
//}
    return 0;
}

void open(string Block)
{
    int flag =0;
    int Cout =0;
    for( int i=0 ; i<counter ; i++)
        {
            if(Block==tag[i].name)
            {   flag =1;
                Cout=i;
                break;
            }
        }

    if (flag)
    {

      if(areStringsEqual(tag[Cout].type , "data") )
        {
            cout << "\": \"";
         //  JSON=JSON+": \"";

        }
      else if(areStringsEqual(tag[Cout].type , "list"))
        {
               cout << "\": [";
            // JSON=JSON+": [";
        }
      else if(areStringsEqual(tag[Cout].type , "object"))
        {
             cout <<"\": {";
            //JSON=JSON+ ": {";
        }


    }
     else
    {
        cout<<"ERROR NOT FOUND";
    }
}
void close(string Block)
{
    int flag =0;
    int Cout =0;
    for(int i=0 ;i<counter ; i++)
        {
            if(Block==tag[i].name)
            {   flag =1;
                Cout=i;
                break;
            }

        }

    if (flag)
    {

      if(areStringsEqual(tag[Cout].type , "data"))
      {
          cout << "\" ,";
          //JSON=JSON+"\",";

      }
      else if(areStringsEqual(tag[Cout].type , "list"))
        {
          cout << "],";
//          JSON=JSON+"],";

        }
      else if(areStringsEqual(tag[Cout].type , "object"))
        {
            cout << "},";
            //JSON=JSON+"},";

        }

    }
     else
    {
        cout<<"ERROR NOT FOUND";
    }
}

