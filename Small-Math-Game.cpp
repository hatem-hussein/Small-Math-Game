#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>











using namespace std;

enum endifficulty
{
	easy = 1 , mid = 2 , hard = 3  ,Mix
};

enum enOperation
{
	add = 1, subtract = 2, multiply = 3, divide = 4 , mix =5
};
enum encorrectNot
{
	Correct = 1 , Wrong =2
};
struct stinfo
{
	int number;
	int number2;
	int  result;
	int userResult;
	endifficulty diff;
	enOperation oper;
	string stOper;
	encorrectNot check_result;

};
struct allinfo
{
	short correct_C = 0;
	short mistakes_C = 0;



};

string readstring(string ask)
{
	string word = "";
	do
	{
		cout << ask;
		cin >> word;

	} while (word != "y" && word != "n");
	return word;


}
void reset_system()
{
	system("cls");
	system("color 0F");

}
bool askusertorepate()
{
	string y_n = "";
	y_n = readstring("Do You Want to reapet ? y/n\n");
	if (y_n == "y")
	{
		return true;
	}
	return false;
}

int readnumber_fromTO(string ask , int from, int to)
{
	int number = 0;
	do
	{
		cout << ask << endl;
		cin >> number;
		cout << endl;
	} while (number <from || number > to);
	return number;
}
int random_number(int from, int to)
{
	int randomnumber = 0;

	randomnumber = rand() % (to - from + 1) + from;

	return randomnumber;
}
short HowMany_quistion(string ask)
{
	int number = 0;
	do {
		cout << ask << endl;
		cin >> number;
		
		cout << endl;

	} while (number < 0 || number > 10);

	return number;
}

endifficulty read_Diff()
{

	stinfo info;
	info.diff = endifficulty(readnumber_fromTO("Enter Difficulty Level [ 1 ] easy , [ 2 ]Mid , [ 3 ] Hard , [ 4 ] Mix", 1, 4));
	return info.diff;
}
enOperation read_Operation()
{
	stinfo info;
	info.oper = enOperation(readnumber_fromTO("Enter Operation [ 1 ] Addition , [ 2 ] Subtract , [ 3 ] Multiply , [ 4 ] Divide , [ 5 ] Mix ",  1, 5));
	return info.oper;
}
encorrectNot check_result(int result, int correct)
{
	if (result == correct)
	{
		return encorrectNot::Correct;
	}
	else
	{
		return encorrectNot::Wrong;
	}
}

int  generate_number(endifficulty level)
{
	switch (level)
	{
	case(endifficulty::easy):
	{
		return random_number(1, 10);
	}
	case(endifficulty::mid):
	{
		return random_number(20, 100);
	}
	case(endifficulty::hard):
	{
		return random_number(50, 500);
	}
	case(endifficulty::Mix):
	{
		return generate_number(endifficulty(random_number(1, 5)));
	
	}
	}
}
string generate_oper(enOperation oper)
{
	switch (oper)
	{
	case(enOperation::add):
	{
		return " + ";
	}break;
	case(enOperation::divide):
	{
		return  " / ";

	}break;
	case(enOperation::multiply):
	{
		return  " * ";


	}break;
	case(enOperation::subtract):
	{
		return  " - ";


	}break;
	
	case(enOperation::mix):
	{
		return generate_oper(enOperation(random_number(1, 5)));
	}
	
	
	

	
	}
}
int generate_result(enOperation oper , int number , int number2)
{
	
	switch (oper)
	{
	case(enOperation::add):
	{
		return number + number2;
	}break;
	case(enOperation::divide):
	{
		return number / number2;

	}break;
	case(enOperation::multiply):
	{
		return number * number2;

	}break;
	case(enOperation::subtract):
	{
		return number - number2;

	}break;
	}
	



}

void read_question(stinfo &quiz)
{
	quiz.diff = read_Diff();
	quiz.oper = read_Operation();
	quiz.stOper = generate_oper(quiz.oper);
	quiz.number = generate_number(quiz.diff);
	quiz.number2 = generate_number(quiz.diff);
	quiz.result = generate_result(quiz.oper, quiz.number, quiz.number2);
	
}
void print_question(stinfo& quiz)
{
	cout << quiz.number << quiz.stOper << quiz.number2;
	cout << endl;
}
encorrectNot read_result(stinfo &quiz)
{
	quiz.userResult;
	cout << "Enter An Answer\n";
	cin >> quiz.userResult;;

	return (check_result(quiz.userResult , quiz.result));
	
		
	
	
}
void print_Yresult(stinfo& quiz)
{
	switch (read_result(quiz))
	{
	case(encorrectNot::Correct):
	{
		cout << "Correct Answer\n";
		system("color 2F");
	}break;
	case(encorrectNot::Wrong):
	{
		cout << "Wrong Answer\n";
		system("color 4F");
	}break;
	}
	



}
void read_FinalResult(stinfo &quiz , allinfo &info)
{
	if ((check_result(quiz.userResult, quiz.result)) == encorrectNot::Correct)
	{
		info.correct_C++;
	}
	else
	{
		info.mistakes_C++;
	}
}
void print_FinalResult(stinfo& quiz, allinfo& info)
{
	cout << "\n\n____________________ Final Results  _______________\n";
	cout << "Correct  : " << info.correct_C << endl;
	cout << "Mistakes : " << info.mistakes_C << endl;


}
void Full_question(stinfo &quiz ,allinfo &allinfo )
{
	do
	{
		reset_system();
		int lop_Length = HowMany_quistion("How Many Question Do You Want");
		for (int i = 1; i <= lop_Length; i++)
		{
			read_question(quiz);
			print_question(quiz);
			cout << endl;

			print_Yresult(quiz);
			read_FinalResult(quiz, allinfo);
		}

		print_FinalResult(quiz, allinfo);
	} while (askusertorepate());
}




int main()
{
	srand(unsigned(time(NULL)));
	stinfo quiz;
	allinfo final_info;
	;
	
	
	
	Full_question(quiz , final_info);
	
	
	
	
}