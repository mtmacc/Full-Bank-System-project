
#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));

    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;

    }

    static  vector <clsCurrency> _LoadCurrencysDataFromFile()
    {

        vector <clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vCurrencys.push_back(Currency);
            }

            MyFile.close();

        }

        return vCurrencys;

    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;



            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrencyDataToFile(_vCurrencys);

    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:

    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    static vector <clsCurrency> GetAllUSDRates()
    {

        return _LoadCurrencysDataFromFile();

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }


    static   clsCurrency FindByCode(string CurrencyCode)
    {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();

    }

    static   clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();

    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());

    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }
    

     double CalcCurrencyToUSD(double amount)
    {
         return amount / this->Rate();
    }
     double CalcCurrencyFromUSD(double amount)
     {
         return amount * this->Rate();;
     }
};















//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsInputValidate.h"	
//#include "clsString.h"
//class clsCurrency
//{
//private:
//	enum Mode{ EmptyMode = 0, UpdateMode = 1};
//	Mode _Mode;
//	string _CurrencyCountryName;
//	string _CurrencyCode;
//	string _CurrencyName;
//	double _CurrencyRate;
//
//
//	static clsCurrency _ConvertLineToCurrencyData(string Line, string Seperator = "#//#")
//	{
//		vector<string> vCurrencyData = clsString::Split(Line, Seperator);
//		return clsCurrency(Mode::UpdateMode,vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
//	}
//	static vector<clsCurrency> _LoadCurrencies()
//	{
//		vector<clsCurrency> vCurrencies;
//		string Line;
//		ifstream MyFile;
//		MyFile.open("Currencies.txt", ios::in);
//
//		if (MyFile.is_open())
//		{
//			while (getline(MyFile, Line))
//			{
//				vCurrencies.push_back(_ConvertLineToCurrencyData(Line));
//			}
//			MyFile.close();
//		}
//		return vCurrencies;
//	}
//
//	static clsCurrency _getEmptyCurrencyObject()
//	{
//		return clsCurrency(Mode::EmptyMode,"", "", "", 0);
//	}
//public:
//	clsCurrency(Mode mode, string CurrencyCountryName, string CurrencyCode, string CurrencyName, double CurrencyRate)
//	{
//		_Mode = mode;
//		_CurrencyCode = CurrencyCode;
//		_CurrencyCountryName = CurrencyCountryName;
//		_CurrencyName = CurrencyName;
//		_CurrencyRate = CurrencyRate;
//	}
//	bool IsEmpty() { return _Mode == Mode::EmptyMode; }
//	string CurrencyCountryName() { return _CurrencyCountryName; }
//	string CurrencyCode() { return _CurrencyCode; }
//	string CurrencyName() { return _CurrencyName; }
//	void setCurrencyRate(double CurrencyRate) { _CurrencyRate = CurrencyRate; }
//	double getCurrencyRate() { return _CurrencyRate; }
//	_declspec(property(get = getCurrencyRate, put = setCurrencyRate)) double CurrencyRate;
//
//	static clsCurrency Find(string CurrencyCode)
//	{
//		vector<clsCurrency> vCurrencies = _LoadCurrencies();
//		for (clsCurrency Currency : vCurrencies)
//		{
//			if (Currency.CurrencyCode() == clsString::UpperAllString(CurrencyCode)
//				|| Currency.CurrencyCountryName() == clsString::UpperAllString(CurrencyCode))
//			{
//				return Currency;
//			}
//		}
//		return _getEmptyCurrencyObject();
//	}
//
//	static vector<clsCurrency> GetCurrenciesList()
//	{
//		return _LoadCurrencies();
//	}
//	static bool IsCurrencyExist(string CurrencyCode)
//	{
//		clsCurrency Currency = clsCurrency::Find(CurrencyCode);
//		return !Currency.IsEmpty();
//	}
//};
//







