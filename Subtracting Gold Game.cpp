// Program:(GAME 3)-a two-player mathematical subtraction game It is played by two people with a
// pile of gold between them.The players take turns removing gold from the pile
// always removing a non-zero square number of coins. 
// NAME:YOUSSIF MOHAMED YOUSSIF MOHAMED ----- ID: 20230513 ----- Section: Registration is pending for section assignment.
// Version: 17.0
// Date: 2 March

#include<iostream>
using namespace std;

void tokens(int gold)
{
	
	cout << "current gold---->" << gold << endl;

}
int player_move(int players)
{
	int move;
	
	cout << "player number: " << players << "\n enter the number of gold you want to remove----> ";
	cin >> move;
	return move;


}
bool gold_num(int n)
{
	int i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
		{
			return true;
		}
		i++;

	}
	return false;
}
void game_3()
{
	cout << "---------------------------------------------------" << endl;
	cout <<"Welcome To Subtracting Gold Game"  << endl;
	
	cout <<"RULES!" << endl;
	cout <<"BEFORE WE START, THERE IS IMPORTANT RULE YOU NEED TO KNOW" << endl;
	cout <<"YOU NEED TO CHOOSE PERFECT SQUARE NUMBERS ONLY"  << endl;
	cout <<"like: [1,4,9,16,......]"  << endl;
	cout <<"NOW ENJOY THE GAME" << endl;
	cout << "---------------------------------------------------" << endl;

	int pile_of_gold;
	cout << "enter the number of gold you want to subtract------> ";
	cin >> pile_of_gold;


	if (pile_of_gold <= 0)
	{
		cout << "ERROR!!, please enter vaild number "<<endl;
		return;
	}
	int gold = pile_of_gold;
	int current_player = 1;


	while (gold > 0)
	{
		tokens(gold);
		int player_movement = player_move(current_player);
		if (1 <= player_movement && player_movement <= gold && gold_num(player_movement)) 
		{
			gold -= player_movement;
			current_player = 3 - current_player;
		}
		else
		{

			cout << "WRONG NUMBER USED!, please enter a valid square number" << endl;
		}
	}
	cout << "Game Over! Player " << 3 - current_player << " Wins" << endl;

}
int main()
{
	game_3();
	return 0;
}
