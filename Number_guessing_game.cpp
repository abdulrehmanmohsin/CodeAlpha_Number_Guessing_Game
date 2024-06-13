#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void game(int random) {
	int user=0, count = 0;
	cout << "You have 9 try left one digit will be revealed after 3 tries \n";
	cout << "Guess a number between 0 to 1000 ";
	while (random != user || count!=9) {
		cin >> user;
		if (user < random) {
			cout << "Guess is too low \n";
			count++;
		}
		else if (user > random) {
			cout << "Guess is too high \n";
			count++;
		}
		else {
			count++;
			cout << "You guessed it right in " << count << " attempts\n";
			break;
		}
		if (count % 3 == 0) {
			int n = count/3,mod=1;
			for (int i = 0;i < n;i++) {
				mod *= 10;
			}
			cout << "Your hint is ";
			if ((random / 100) % 10 != 0) {
				if (n == 1) {
					cout << "**" << random % mod<<" ";
				}
				else if (n == 2) {
					cout << "*" << random % mod<<" ";
				}
			}
			else {
				if (n == 1) {
					cout << "**" << random % mod << " ";
				}
				else if (n == 2) {
					cout << "0*" << random % 10 << " ";
				}
				else{
					cout << "You have no more try left \n";
					cout << "Right answer is " << random<<endl;
				}
			}
		}
	}
}
int main() {
	int choice=1;
	srand(time(0));
	while (choice != 0) {
		cout << "Enter 0 for exit and any other to play game ";
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			system("cls");
			game(rand()%1000);
		}
	}
	system("pause");
}