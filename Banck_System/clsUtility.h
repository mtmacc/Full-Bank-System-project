#pragma once
#include<iostream>
#include <time.h>
#include"clsDate.h"
#include"clsString.h"
using namespace std;
class clsUtility
{

public:
	enum CharType { SLetter = 1, CLetter, Digit, SChar, Mix };
	static void Srand()
	{ 
		srand(time(0));
	}

    // Rand Number Founction 

	static int RandFunction(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}

    //Rand Char Founction

   static char RandomChar(CharType type)
    {
        if (type == CharType::SLetter)
        {
            return char(RandFunction(97, 122));
        }
        else if (type == CharType::CLetter)
        {
            return char(RandFunction(65, 90));
        }
        else if (type == CharType::SChar)
        {
            return char(RandFunction(33, 47));
        }
        else if (type == CharType::Digit)
        {
            return char(RandFunction(48, 57));
        }
        else if (type == CharType::Mix)
        {
            return RandomChar((CharType)RandFunction(1, 3));
        }
        return '\0';
    }

   // Generte Random Word Founction

   static string GenerteWord(CharType type, int length)
   {
       string keyWord = "";
       for (int i = 1; i <= length; i++)
       {
           keyWord += RandomChar(type);
       }
       return keyWord;
   }

   // Generate Key Founction

   static string GenerateKey(CharType type)
   {
       string key = "";
       for (int i = 1; i <= 4; i++)
       {
           key += GenerteWord(type, 4);
           if (i < 4)
           {
               key += " - ";
           }
       }
       return key;
   }

   // Generate Keys Founction 

   static void Generatekeys(int keysnum,CharType type)
   {
       for (int i = 1; i <= keysnum; i++)
       {
           cout << "Key [" << i << "] : " << GenerateKey(type) << endl;
       }
   }
   template<typename T>
   static void Swap(T& x, T& y)
   {
       T temp = x;
       x = y;
       y = temp;
   }

   //// Swap Int Founction 

   //static void Swap(int& x, int& y)
   //{
   //    int temp = x;
   //    x = y;
   //    y = temp;
   //}

   //// Swap Double Numbers Founction 

   //static void Swap(double& x, double& y)
   //{
   //    double temp = x;
   //    x = y;
   //    y = temp;
   //}



   //static void Swap(string& x, string& y)
   //{
   //    string temp = x;
   //    x = y;
   //    y = temp;
   //}

   //// Swap Date Founction 

   //static void Swap(clsDate& x, clsDate& y)
   //{
   //    clsDate temp = x;
   //    x = y;
   //    y = temp;
   //}

   //Shuffle int Array Founction 

   static void ShuffleArray(int arr[], int arrLength) 
   {
       for (int i = 0; i < arrLength; i++) 
       {
           Swap(arr[RandFunction(0, arrLength - 1)], arr[RandFunction(0, arrLength - 1)]);
       }
   }

   //Shuffle String Array Founction 

   static void ShuffleArray(string arr[], int arrLength)
   {
       for (int i = 0; i < arrLength; i++)
       {
           Swap(arr[RandFunction(0, arrLength - 1)], arr[RandFunction(0, arrLength - 1)]);
       }
   }

   //Fill Array With Random Number Function

   static void FillArrayWithRandomNumber(int nums[], int arraylength,int from,int to)
   {
       for (int i = 0; i < arraylength; i++)
       {
           nums[i] = RandFunction(from, to);
       }
   }

   //Fill Array With Random Number Words

   static void FillArrayWithRandomWords(string Words[], int arraylength,CharType type,int wordLength)
   {
       for (int i = 0; i < arraylength; i++)
       {
           Words[i] = GenerteWord(type, wordLength);
       }
   }

   //Fill Array With Random Keys Function

   static void FillArrayWithRandomKeys(string Words[], int arraylength, CharType type)
   {
       for (int i = 0; i < arraylength; i++)
       {
           Words[i] = GenerateKey(type);
       }
   }

   // Taps Function

   static string Taps(int Number)
   {
       string taps = "";
       for (int i = 0; i < Number; i++)
       {
           taps += "\t";
       }
       return taps;
   }

   //Encryption Text Function 

   static string EncryptText(string text,int encrptionKey)
   {
       string result = "";
       for (int i = 0; i < text.length(); i++)
       {
           result += char(text[i] + encrptionKey);
       }
       return result;
   }

   //Decryption Text Function 

   static string DecryptText(string text, int encrptionKey)
   {
       string result = "";
       for (int i = 0; i < text.length(); i++)
       {
           result += char(text[i] - encrptionKey);
       }
       return result;
   }
};


