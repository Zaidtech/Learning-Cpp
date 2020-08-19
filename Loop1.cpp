#include <iostream>
using namespace std;

int main(){

	char choice ;
	bool flag = true;
	while(flag)
	{
		cout << "What you want to convert to ?" << endl;
		cout << "1. For Celcius to Fahrenheit press 1"<< endl<< "2. For Fahrenheit to Celcius press '2'"<<endl <<  "3. Press q to exit "<< endl;
		cin >> choice;

		switch(choice)
		{
			case '1':
			float temp_C;
			cout << "Enter the temp to convert to Fahrenheit: ";
			cin >> temp_C;
			cout << "Temp in Fahrenheit is " << (temp_C*5) / 9 + 18 << endl;// Some doubt about the conversion
			break; 

			case '2':
			float temp_F;
			cout << "Enter the temp to convert to Celcius:  ";
			cin >> temp_F;
			cout << "Temp in Celcius is " << (temp_F*9) / 5 + 18 << endl; // Some doubt about the conversion
			break;
			
			case 'q':
				flag = false;
				break;

			default :
			cout << "Enter a valid choice"<<endl;
			continue;
		}  

    }
    cout << "Thankyou for converting some temps."<< endl;

}    

