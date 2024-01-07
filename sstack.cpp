#include <stdio.h>
#include <stdlib.h>

#include "sstack.h"



/****************************************************/
Status Stack_Init(Staack* StackAddress)
{
    Status stvalue = NotOk;
    if(NULL !=StackAddress)
        {
         StackAddress->stack_pointer=-1;

         stvalue =Ok;
        }
    else
        {
        cout<<"The Stack Was not been Intialized \n";
        }

    return stvalue;
}

/*****************************************************/
Status is_Full(Staack* StackAddress)
{
        Status stvalue;
 if(NULL !=StackAddress)
        {
             if (MAX_SIZE==(StackAddress->stack_pointer+1))
             {
                 stvalue =Full;
             }
             else
             {
                 stvalue =NotFull;
             }
        }
    else
        {
        cout<<"The Stack Was not been Intialized\n";
        }
        return stvalue;
}
/*************************************************/
Status is_Empty(Staack* StackAddress)
{
    Status stvalue;
      if(NULL !=StackAddress)
        {
             if (-1==StackAddress->stack_pointer)
             {
                 stvalue =Empty;
             }
             else
             {
                 stvalue =NotEmpty;
             }
        }
      else
        {
        cout<<"The Stack Was not been Intialized\n";
        }

    return stvalue;
}
/**************************************************/

Status Push(Staack* StackAddress, string n)
{
    Status stvalue;

     if(NULL !=StackAddress)
     {
        if(Full==is_Full(StackAddress))
            {
                stvalue= Full;
                cout<<"stack is full, fialled to Push "<< n<<" \n";
            }
        else
        {
            stvalue=Ok;
            (StackAddress->stack_pointer)++;
            StackAddress->name[StackAddress->stack_pointer]=n;
            //cout<<n<<" is pushed successfully\n";
        }


     }
     else
     {
        stvalue=NotOk;
     }
     return stvalue;
}
/*************************************************/
//Status Push2(Staack* StackAddress, int ln,string n)
//{
//    Status stvalue;
//
//     if(NULL !=StackAddress)
//     {
//        if(Full==is_Full(StackAddress))
//            {
//                stvalue= Full;
//                cout<<"stack is full, fialled to Push "<< n<<" \n";
//            }
//        else
//        {
//            stvalue=Ok;
//            (StackAddress->stack_pointer)++;
//            StackAddress->name[StackAddress->stack_pointer]=n;
//
//            //cout<<n<<" is pushed successfully\n";
//        }
//
//
//     }
//     else
//     {
//        stvalue=NotOk;
//     }
//     return stvalue;
//}
/**************************************************/
string Pop(Staack* StackAddress)
{
    string n;

     if((NULL !=StackAddress ))
     {
        if(Empty==is_Empty(StackAddress))
            {
                cout<<"stack is Empty, fialled to pop  \n";
            }
        else
        {

           n = StackAddress->name[StackAddress->stack_pointer];
            StackAddress->name[StackAddress->stack_pointer]="";
            (StackAddress->stack_pointer)--;
         //   cout<<n<<" is popped successfully\n";
        }


     }
     else
     {
      cout<<"Wrong address of stack";

     }
     return n;
}
/**************************************************/
string Top(Staack* StackAddress)
{
    string n;
    if (NULL != StackAddress)
    {
        if (Empty== is_Empty(StackAddress))
        {
            cout << "Stack is empty. Failed to retrieve top element.\n";
        }
        else
        {
            n = StackAddress->name[StackAddress->stack_pointer];
        }
    }
    else
    {
        cout << "Wrong address of stack.\n";
    }
    return n;
}
/**************************************************/
Status Stack_Display(Staack* StackAddress)
{
    Status stvalue;
    if(NULL !=StackAddress)
        {
            stvalue=Ok;
                for(int counter =0; counter<=StackAddress->stack_pointer ; counter++)
                {
                    cout<<StackAddress->name[counter]<<"\n";
                }
        }

    else
    {
       cout<<"Wrong address of stack";

    }
    return stvalue;

}
/**************************************************/
Status Stack_Size(Staack* StackAddress)
{
    Status stvalue;
    if(NULL !=StackAddress)
        {
            if(Empty==is_Empty(StackAddress))
            {
                stvalue=Empty;
                printf("Stack Size is 0");
            }
            else
            {
                 stvalue=Ok;
                 cout<<"Stack Size is" << (((StackAddress->stack_pointer)+1)*4)<<"Bytes";
                 cout<<"Stack Size has "<< ((StackAddress->stack_pointer)+1) <<"Elements";
            }


        }

    else
    {
         stvalue=NotOk;
    }
    return stvalue;

}

/****************************************************/
int Size_Of(Staack* StackAddress)
{
 return  ((StackAddress->stack_pointer)+1);
}

/****************************************************/
string Element(Staack* StackAddress, int ptr)
{
    return StackAddress->name[ptr];
}
/*****************************************************/
bool areStringsEqual(const std::string& str1, const std::string& str2) {
    return str1 == str2;
}
/****************************************************/
bool Search(Staack* StackAddress, string tag)
{
    bool ret= false;
    for(int i =0 ; i <= StackAddress->stack_pointer ; i++)
          {
             if(areStringsEqual(Element(StackAddress, i), tag))
             {
                ret=true;
             }
             else
                continue;
          }
  return ret;
}
/*********************************************************/





