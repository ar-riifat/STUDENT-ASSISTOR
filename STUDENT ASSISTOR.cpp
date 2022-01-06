#include <bits/stdc++.h>
using namespace std;
map<string, string> passwrd;

void userdata()
{
    fstream file;
    file.open("Info.txt", ios :: in);

    if (file)
    {
        string username, password;
        while (file >> username)
        {
            file >> passwrd[username];
        }
    }
    file.close();
}

string Genpass()
{
    string pass = " ";
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@#$%&*!?";
    cout << "How long you want the password to be (4-70): ";
    int len, i;
    cin >> len;
    for (i = 0; i < len; i++)
    {
        pass += characters[rand() % characters.size()];
    }
    cout<<pass<<endl;
    system("pause");
    return pass;
}

void StudentInfo()
{
    system("cls");
    string data;
    fstream file;

    file.open("Student.txt", ios::app);

    cout << "Student Name: ";
    cin.ignore();
    getline(cin, data);
    file << "Name: " << data << endl;

    cout << "Assignment date: ";

    getline(cin, data);
    file << "Assignment date: " << data << endl;

    cout << "Exam date: ";

    getline(cin, data);
    file << "Exam date: " << data << endl;

    file.close();
}

void SignUp()
{
    system("Cls");
    string Username, Password;
    cout << "Enter Username: ";
    cin >> Username;
    cout << "1.Get random password: ";
    cout << "2.Enter new one: ";
    int op;
    cin >> op;
    if (op == 1)
    {
        Password = Genpass();
        StudentInfo();
    }
    else

    {
        cout << "Enter Password: ";
        cin >> Password;
    }
    fstream file;
    file.open("Info.txt", ios::app);

    if (file)
    {
        file << Username << " " << Password << endl;
    }
    file.close();
}

void logIn()
{
    system("Cls");
    string Username ,Password;
    cout <<"Enter Username: ";
    cin >> Username;
    if(passwrd.find(Username) == passwrd.end())
    {
        cout<<"Username doesn't exist! Please register."<< endl;
        system("pause");
        SignUp();
        return;
    }
    cout << "Enter Password: ";
    cin >> Password;

    if (passwrd[Username]== Password)
    {
        cout << "Login Success!!" << endl;
        return;
    }
    else
    {
        cout << "Wrong Password!!Try Again."<< endl;
        logIn();
    }
}

int RockPaperScissor(char you, char comp)
{
    system("Cls");
    if (you == comp)
    {
        return 0;
    }

    if (you == 'r' && comp == 'p')
    {
        return -1;
    }
    else if (you == 'p' && comp == 'r')
    {
        return 1;
    }

    else if (you == 's' && comp == 'r')
    {
        return -1;
    }
    else if (you == 'r' && comp == 's')
    {
        return 1;
    }

    else if (you == 'p' && comp == 's')
    {
        return -1;
    }
    else if (you == 's' && comp == 'p')
    {
        return 1;
    }
}

int main()
{
    int num;
    do
    {
        system("Cls");
        cout << "Welcome to the project" << endl;
        cout << "1.Sign up" << endl;
        cout << "2.Sign in" << endl;
        cout << "3.Play Game" << endl;
        cout << "4.Exit" << endl;
        cout << "Choose your option: ";
        cin >> num;

        switch (num)
        {
        case 1:
            userdata();
            StudentInfo();
            SignUp();
            break;

        case 2:
            logIn();
            break;

        case 3:
            {

            char you, comp;
            srand(time(0));
            int n;
            int number = rand() % 100 + 1;
            int result;
            do
            {
                cout << endl
                     << "Do you want to play the game?" << endl;
                cout << "Press 1: Yes" << endl;
                cout << "Press 2: No" << endl
                     << endl;
                cin >> n;

                switch (n)
                {
                case 1:
                    if (number <= 33)
                    {
                        comp = 'r';
                    }
                    else if (number > 33 && number < 66)
                    {
                        comp = 'p';
                    }
                    else
                    {
                        comp = 's';
                    }
                    result = RockPaperScissor(you, comp);
                    system("cls");
                    cout << "Welcome To The Game!!" << endl;
                    cout << endl
                         << "Enter 'r' for Rock, 'p' for Paper and 's' for Scissor" << endl;
                    cin >> you;

                    if (result == 0)
                    {
                        cout << endl
                             << "Game Draw" << endl;
                    }
                    else if (result == 1)
                    {
                        cout << endl
                             << "You Win This Round!!" << endl;
                    }
                    else
                    {
                        cout << endl
                             << "You Lose This Round!!" << endl;
                    }
                    cout << endl
                         << "You choose " << you << " and computer choose " << comp << endl;

                    break;
                case 2:
                    cout << "See you next time" << endl;
                    break;
                }
            } while (n != 2);
        }
        case 4:
            cout << "Program terminated" << endl;
            break;
        }

    } while (num != 4);

    return 0;
}
