#pragma warning(disable : 4996)
#include <iostream>
#include <string>

using namespace std;

int Count(const string str)
{
	if (str.length() < 4)
		return -1;
	else
	{
		int k = 0;
		size_t pos = 0;

		while ((pos = str.find(str[pos + 2], pos)) != -1)
		{
			pos++;
			if (str[pos + 1] == str[pos + 2])
			{
				k++;
				break;
			}
			return k;
		}
	}
}

string Change(string& str)
{
	size_t pos = 0;
	while ((pos = str.find(str[pos + 2], pos)) != -1)
	{
		if (str[pos + 2] == str[pos + 3])
		{
			str.replace(pos, 4, "**");
		}
		return str;
	}
}

int main()
{
	string str;

	cout << "Enter String:" << endl;
	getline(cin, str);

	if (Count(str) == -1)
		cerr << "Enter more characters" << endl;
	else
	{
		if (Count(str) == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		cout << endl;
		cout << "String conteined " << Count(str) << " groups of ' '" << endl;

		string dest = Change(str);

		cout << "Modified string (param): " << str << endl;
		cout << "Modified string (result): " << dest << endl;
	}

	return 0;
}