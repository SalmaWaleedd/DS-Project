#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "sstack.h"


using namespace std;

int Error(string fileContents, TagForError* returnedTag);
TagForError* createDynamicArray(int size);
string XML_TO_JSON(string fileContents);
string open(string Block);
string close(string Block);

int CounterOfTag=0;
Tag tag[1000];

string JsonFormat;
int lineCounter=1;


string ReadXml(string filePath) {

    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        return "error";
    }
    // Read the file content into a stringstream
    stringstream buffer;
    buffer << inputFile.rdbuf();

    // Close the file
    inputFile.close();

    // Extract the content from the stringstream
    string fileContent = buffer.str();

    // Display the content (you can remove this in your final code)
    return fileContent;
}
string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    std::string content;

    if (file.is_open()) {
        // Read the entire file content into the string
        content.assign((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

        // Close the file
        file.close();
    } else {
        // The file failed to open
        std::cerr << "Error opening file: " << filename << std::endl;
    }

    return content;
}

int main()
{
  string filePath ="example.xml";


    string fileContents = ReadXml(filePath);

    //JsonFormat=XML_TO_JSON(fileContents);

    //cout<<JsonFormat;
    string filename = "input.txt";
    string fileContent = readFileToString(filename);


    /*****************************TRYING TO CORRECT************************************************************/

    for (int x=0  ; x<fileContents.length(); x++)

    /*****************************************************************************************/

    return 0;
}


TagForError* createDynamicArray(int size) {
    TagForError* dynamicArray = new TagForError[size];
    return dynamicArray;
}
int Error(string fileContents, TagForError* returnedTag)
{

    string Block;
    Staack ErrorStack;
    int y=1;
    int m=2;
    int ff;
    bool Vir=true;
    //int lineCounter=1;
    TagForError tagE[1000];
    int CounterErrorTags=0;


    int indexOfTag=0;
    /******************************/
    Stack_Init(&ErrorStack);
    /****************************/
    for (int x=0  ; x<fileContents.length(); x++)
    {
        ff=1;
        if(fileContents[x]=='\n')
            lineCounter++;

        if (fileContents[x]=='<' && fileContents[x+1]!='/')
        {

            while (fileContents[x+y]!='>')
            {
                Block=Block+fileContents[x+y];
                y++;
            }

            y=1;

            Push(&ErrorStack,Block);

            tagE[indexOfTag].name=Block;
            tagE[indexOfTag].LineNumber=lineCounter;
            indexOfTag++;

            Block.clear();


        }
        else if (fileContents[x]=='<' && fileContents[x+1]=='/')
        {
            while (fileContents[x+m]!='>')
            {
                Block=Block+fileContents[x+m];
                m++;
            }

            m=2;
            while(ff)
            {
                if( areStringsEqual(Block, Top(&ErrorStack)))
                {

                    for (int i=indexOfTag-1; i>=0 ; i--)
                    {
                        if(Top(&ErrorStack)== tagE[i].name)
                        {
                            tagE[i].name=" ";
                            break;
                        }
                    }

                    Pop(&ErrorStack);
                    ff=0;

                }
                else
                {
                    Vir=false;
                    if(Search(&ErrorStack,Block))
                    {
                        for (int i=0; i<indexOfTag ; i++)
                        {
                            if(Top(&ErrorStack)== tagE[i].name)
                            {
                                //cout<<"closing of "<<Top(&ErrorStack)<<" in line "<<tagE[i].LineNumber<<" is missing\n";

                                returnedTag[CounterErrorTags].name="Closing Tag";
                                returnedTag[CounterErrorTags].LineNumber=tagE[i].LineNumber;
                                CounterErrorTags++;
                                tagE[i].name=" ";
                                break;
                            }
                        }
                        Pop(&ErrorStack);

                    }
                    else if(!(Search(&ErrorStack,Block)))
                    {

                       // cout<<"openning of "<<Block<<" in line "<<lineCounter<<" is missing\n";

                                returnedTag[CounterErrorTags].name="openning Tag";
                                returnedTag[CounterErrorTags].LineNumber=lineCounter;
                                CounterErrorTags++;
                        ff=0;

                    }
                }

            }


            Block.clear();
        }
    }

    if(Vir &&(Empty==is_Empty(&ErrorStack)))
        cout<<"There is no errors"<<endl;
    else if(Empty==is_Empty(&ErrorStack))
        cout<<"There is no other errorssssss"<<endl;
    else if(NotEmpty==is_Empty(&ErrorStack))
    {
        cout << "closing tag of " <<Top(&ErrorStack)<< "is missing in line "<<(1+lineCounter) << endl;

        returnedTag[CounterErrorTags].name="Closing Tag";
        returnedTag[CounterErrorTags].LineNumber=(1+lineCounter);
        CounterErrorTags++;
        Pop(&ErrorStack);
        cout<<"There is no other errors"<<endl;

    }

    return CounterErrorTags;
}

/*****************************************************************************************************
****************************************************************************************************
***************************************************************************************************
***************************************************************************************************/
string open(string Block)
{
    string Ret;
    int flag =0;
    int Cout =0;
    for( int i=0 ; i<CounterOfTag ; i++)
    {
        if(Block==tag[i].name)
        {
            flag =1;
            Cout=i;
            break;
        }
    }

    if (flag)
    {

        if(areStringsEqual(tag[Cout].type, "data") )
        {
            //cout << "\": \"";
             //JSON=JSON+": \"";
             Ret="\": \"";;

        }
        else if(areStringsEqual(tag[Cout].type, "list"))
        {
            //cout << "\": [";
             //JSON=JSON+": [";
             Ret="\": [";
        }
        else if(areStringsEqual(tag[Cout].type, "object"))
        {
            //cout <<"\": {";
            //JSON=JSON+ ": {";
            Ret="\": {";
        }


    }
    else
    {
        cout<<"ERROR NOT FOUND";
    }
    return Ret;
}
string close(string Block)
{
    string Ret;
    int flag =0;
    int Cout =0;
    for(int i=0 ; i<CounterOfTag ; i++)
    {
        if(Block==tag[i].name)
        {
            flag =1;
            Cout=i;
            break;
        }

    }

    if (flag)
    {

        if(areStringsEqual(tag[Cout].type, "data"))
        {
            //cout <<"\",";
            Ret="\" ,";
            //JSON=JSON+"\",";

        }
        else if(areStringsEqual(tag[Cout].type, "list"))
        {
//            cout << "],";
         // JSON=JSON+"],";
          Ret= "],";

        }
        else if(areStringsEqual(tag[Cout].type, "object"))
        {
//            cout << "},";
            //JSON=JSON+"},";
            Ret="},";

        }

    }
    else
    {
        cout<<"ERROR NOT FOUND";
    }

    return Ret;
}

/*****************************************************************************************************
****************************************************************************************************
***************************************************************************************************
***************************************************************************************************/

string XML_TO_JSON(string fileContents)
{
    //tags type
    string JSON;
    Staack st1;
    Staack stackofblocks;
    int y=1;
    string Block;
    //Tag tag[1000];

    Stack_Init(&st1);
    Stack_Init(&stackofblocks);

//push all tags to a stack st1
    for (int x=0  ; x<fileContents.length(); x++)
    {
        if (fileContents[x]=='<')
        {

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
    /****************************************/
//detect data and object and list types
    for (int i =0; i < Size_Of(&st1) ; i++)
    {
        if(Element(&st1,i)[0]!='/')
        {
            if(("/"+Element(&st1,i)) == Element(&st1,i+1))
            {
                //cout<<Element(&st1,i)<<" is a data\n";
                tag[CounterOfTag].name= Element(&st1,i);
                tag[CounterOfTag].type= "data";
                CounterOfTag++;

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
                        tag[CounterOfTag].name= Element(&st1,i);
                        tag[CounterOfTag].type= "list";
                        CounterOfTag++;

                        break;
                    }
                    else
                    {
                        //cout<<Element(&st1,i)<<" is an object\n";
                        tag[CounterOfTag].name= Element(&st1,i);
                        tag[CounterOfTag].type= "object";
                        CounterOfTag++;
                        break;
                    }
                }
            }

        }

    }
    Block.clear();

    /*******************************************************************************/

//loop on tags to detect lists which have 1 object
    for(int i =0; i<CounterOfTag ; i++)
    {
        if(tag[i].type=="list")
        {
            for(int j =0; j<CounterOfTag ; j++)
            {
                if((tag[j].name==tag[i].name) &&tag[j].type=="object")
                {
                    tag[j].type="list";
                }
            }
        }
    }

    /*************************************************************************/
//Print JSon Format
   // cout<<"{\n";
    JSON="{\n";
    for (int x=0  ; x<fileContents.length(); x++)
    {
        if (fileContents[x]=='<'&& fileContents[x+1]!='/') //openning tag
        {
            y=1;
            while (fileContents[x+y]!='>')
            {
                Block=Block+fileContents[x+y];
                y++;
            }

            //cout<<"\"";
            JSON=JSON+"\""+Block;
            //cout<<Block;
            x=x+Block.length()+1;
            JSON=JSON + open(Block);
            Block.clear();

        }
        else if(fileContents[x]=='<'&& fileContents[x+1]=='/')//closing tag
        {
            y=2;
            while (fileContents[x+y]!='>')
            {
                Block=Block+fileContents[x+y];
                y++;
            }
            x=x+Block.length()+2;
            JSON=JSON + close(Block);
            Block.clear();

        }

        else
        {
            //cout<<fileContents[x];
            JSON=JSON+fileContents[x];

        }

    }
    //cout<<"}";
    JSON=JSON+"\n}";


    return JSON;
}
