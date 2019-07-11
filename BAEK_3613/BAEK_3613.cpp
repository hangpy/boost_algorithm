#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string S;

int main()
{
	cin >> S;

	bool isCapital = false;
	/*bool isCpp = false;*/
	// 0: JAVA, 1: C++, 2: Error
	int judge = 0;

	for (int i = 0; i < S.size(); i++)
	{
		if ((i == 0 && (S[i] < 91 || S[i] == '_')) ||
			(i == S.size() - 1 && S[i] == '_'))
		{
			judge = 2;
			break;
		}
		if (S[i] == '_' && S[i + 1] == '_')
		{
			judge = 2;
			break;
		}
		if (S[i] == '_') judge = 1;
		if (S[i] < 91) isCapital = true;
		if (judge == 1 && isCapital == true)
		{
			judge = 2; 
			break;
		}
	}

	

	if (judge == 0)
	{
		// Java -> Cpp
		string cpp_s;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] < 91)
			{
				cpp_s += '_';
				cpp_s += (S[i] + 'a' - 'A');
			}
			else cpp_s += S[i];
			
		}
		cout << cpp_s << endl;
	}
	else if (judge == 1)
	{
		// Cpp -> Java
		string java_s;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '_') java_s += (S[++i] - ('a' - 'A'));
			else java_s += S[i];
		}
		cout << java_s << endl;
	}
	else cout << "Error!" << endl;

	/*if (judge == 0) cout << "JAVA";
	else if (judge == 1) cout << "CPP";
	else cout << "Error!";*/

    return 0;
}

