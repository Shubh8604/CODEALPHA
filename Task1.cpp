#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int random;
	int guess;
	int tries = 0;
	srand(time(0));
	random=rand()%100+1;
	cout<<"Welcome To Number Guessing Game : "<<endl;
	cout<<endl;
	do
	{
		cout<<"Enter A Number Between 1 To 100"<<endl;
		cin>>guess;
		tries++;

		if(guess>random)
		{
			cout<<"The Number Guess Is Too High"<<endl;
		}
		else if(guess<random)
		{
			cout<<"The Number Guess Is Too Low"<<endl;
		}
		else
		{
			cout<<"Congratulations!! You Have Guessed The Number In "<< tries << " Chances"<<endl;
		}
	}
	while(guess!=random);

		return 0;
}