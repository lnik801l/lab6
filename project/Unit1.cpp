//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#include <cmath>
#include "Unit1.h"

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm1 *Form1;


void sort_asc(int arr[], const int size)
{
	for (auto i = 0; i < size - 1; i++) {
		for (auto j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void sort_desc(int arr[], const int size)
{
	for (auto i = 0; i < size - 1; ++i)
	{
		auto smallest_index = i;
		for (auto j = i; j < size + 1; ++j)
		{
			if (arr[j] > arr[smallest_index])
				smallest_index = j;
		}
		swap(arr[i], arr[smallest_index]);
	}
}

short calculate(double a, double b, double c, double &x1, double &x2)
{
	try
	{
		short status = -1;
		const auto disc = b * b - 4 * a * c;
		if (disc == 0) status = 1;
		if (disc > 0) status = 2;
		if (disc < 0) status = 0;

		x1 = (-b + sqrt(disc)) / 2 * a;
		x2 = (-b - sqrt(disc)) / 2 * a;

		if (x1 != x1 || x2 != x2) {
			return -1;
		}

		return status;
	} catch (exception ignored)
	{
		return -1;
	}
}
wchar_t* reverse_str(wchar_t str[], const unsigned int size)
{
	for (auto i = 0u; i < size / 2; i++)
		swap(str[i], str[size - i - 1]);
	return str;
}
System::String process_string(const wchar_t str[], unsigned int length, bool asc)
{
	int arr[100];
	for (auto& i : arr)
	{
		i = 0;
	}

	auto j = 0;
	auto flag = false;
	for (auto i = 0u; i < length; i++) {

		if (str[i] == ',')
			continue;
		if (str[i] == ' ') {
			j++;
			flag = false;
		}
		else {
			if (str[i] == '-') {
				flag = true;
				continue;
			}
			wchar_t s[2];
			s[0] = str[i];
			s[1] = 0;
			if (flag)
				arr[j] = arr[j] * 10 - _wtoi(s);
			else
				arr[j] = arr[j] * 10 + _wtoi(s);
		}
	}
	if (asc)
		sort_asc(arr, j + 1);
	else
		sort_desc(arr, j + 1);

	System::String result = "";

	for (auto i = 0u; i < j + 1; i++) {
		result += arr[i];
		result += " ";
	}

	return result;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::exec_pow(TObject *Sender)
{
	auto number = Form1->Edit1->Text.ToIntDef(1);
	auto rank = Form1->Edit2->Text.ToIntDef(1);
	auto res = pow(number, rank);
	Form1->Label5->Caption = res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::revert_handler(TObject *Sender)
{
   auto str = Form1->Edit3->Text;
   Form1->Label9->Caption = reverse_str(str.c_str(), str.Length());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sort_array(TObject *Sender)
{
	auto str = Form1->Edit4->Text;
	Form1->Label13->Caption = process_string(str.c_str(), str.Length(), Form1->CheckBox1->Checked).c_str();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::exec_function(TObject *Sender)
{
	double x1;
	double x2;

	Form1->Label19->Caption = calculate(Form1->Edit5->Text.ToIntDef(1),
		Form1->Edit6->Text.ToIntDef(1),
		Form1->Edit7->Text.ToIntDef(1),
		x1,x2);
	Form1->Label21->Caption = x1;
	Form1->Label23->Caption = x2;
}
//---------------------------------------------------------------------------
