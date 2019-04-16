#include <iostream>
#include <string>
using namespace std;

string account_number;
int menu_option;
int withdraw_option;
float deposit_amount;
char welcome_option;
float balance_amount = 5000000;

// Function declarations
void Welcome();
void ShowMenu();
void CheckBalance();
void Withdraw();
void Deposit();
void Eject();

/*
Responsible: Vuong Van Thang
Desciption: To check whether the string inputs is numberic or not
Result: Return True if it is, otherwise return False
*/
inline bool isNumber(std::string sValue)
{
	for (auto& var : sValue)
	{
		if (var < '0' || var > '9')
		{
			return false;
		}
	}
	return true;
}

/*
Responsible: Vuong Van Thang
Desciption: To change the numeric to desired money format.
		    E.x: input: float x = 5000000 -> return string as 5.000.000
Result: return the string as desired format
*/
std::string MoneyFormat(const float& fValue)
{
	std::string m_sValue = std::to_string(fValue);
	unsigned int length = m_sValue.size() - 7;
	m_sValue.resize(length);	

	if (length <= 3) return m_sValue;
	//
	for (unsigned int i = 1; (3*i) < length; ++i)
	{
		m_sValue.insert(length -(3*i), ".");
	}	
	return m_sValue;

}

int main()
{
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "--Vui long dua the ATM vao--" << endl;
	system("pause");
	//your code here
	// Code updated
	Welcome();

	system("pause");
	return 0;
}

// Hien thi thong diep welcome va
// yeu cau nguoi dung nhap vao tai khoan giao dich
void Welcome() {

	system("cls");
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "Da nhan duoc the, vui long nhap tai khoan giao dich:" << endl;

	cin >> account_number;
	//your code here
	// Code updated
	cout << "Tai Khoan: " << account_number << endl;
	cout << "Ban co muon nhap lai tai khoan khong? (y/n): ";
	cin >> welcome_option;

	system("cls");


	while (1) {
		if (welcome_option != 'n' && welcome_option != 'y') {
			//your code here
			// code updated
			cout << "Vui long chi nhap 'y' hoặc 'n'" << endl;
			cout << "Ban co muon nhap lai tai khoan khong (y/n): ";
			cin >> welcome_option;
			continue;
		}
		if (welcome_option == 'y') {
			//your code here
			cout << "So tai khoan da nhap: " << account_number << endl;
			cout << "Vui long nhap lai" << endl;
			cout << "Tai khoan: ";
			cin >> account_number;
			break;
		}
		else {
			//your code here
			break;
		}
	}

	ShowMenu();
}

// Hien thi menu voi 4 chuc nang
void ShowMenu() {
	do {
		system("cls");
		//your code here
		cout << "Menu" << endl;
		cout << " 1. Tra cuu so du " << endl;
		cout << " 2. Rut tien " << endl;
		cout << " 3. Nap tien " << endl;
		cout << " 4. Ngung giao dich " << endl;
		cout << "Vui long chon Menu (tu 1 toi 4)" << endl;

		cin >> menu_option;
	} while (menu_option < 1 || menu_option>4);

	switch (menu_option) {
	case 1:
		CheckBalance();
		break;
	case 2:
		Withdraw();
		break;
	case 3:
		Deposit();
		break;
	case 4:
		Eject();
	}
}

// Tra cuu so du
void CheckBalance()
{
	system("cls");
	//your code here
	cout << "Tai khoan: " << account_number << endl;
	/*std::cout.precision(0);
	cout << std::fixed  << "So du: " << balance_amount << endl;*/
	cout << MoneyFormat(balance_amount) << " VND"  << endl;

	system("pause");
	ShowMenu();
}

// Rut tien trong tai khoan
void Withdraw()
{
	system("cls");
	do {
		cout << "--RUT TIEN--" << endl;
		//your code here
		cout << "\\n Vui long chon so tien de rut\n\n" << endl;
		cout << "1. 50.000 (Nam muoi nghin dong)" << endl;
		cout << "2. 100.000 (Mot tram nghin dong)" << endl;
		cout << "3. 200.000 (Hai tram nghin dong)" << endl;
		cout << "4. 500.000 (Nam tram nghin dong)" << endl;
		cout << "5. 1.000.000 (Mot trieu dong)" << endl;
		cout << "6. 2.000.000 (Hai trieu dong)" << endl;
		// Starting advanced implementation
		cout << "7. Nhap so khac" << endl;
		// Ending advanced implementation
		cout << "8. Thoat ve man hinh chinh" << endl;

		cin >> withdraw_option;
		cout << endl;
	} while (withdraw_option < 1 || withdraw_option> 7);


	int withdraw_amount = 0; // So tien muon rut
	std::string s_withdraw_amount;

	switch (withdraw_option) {
	case 1:
		//your code here
		withdraw_amount = 50000;
		break;
	case 2:
		//your code here
		withdraw_amount = 100000;
		break;
	case 3:
		//your code here
		withdraw_amount = 200000;
		break;
	case 4:
		//your code here
		withdraw_amount = 500000;
		break;
	case 5:
		//your code here
		withdraw_amount = 1000000;
		break;
	case 6:
		//your code here
		withdraw_amount = 2000000;
		break;
	case 7:
		// Starting advanced implementation	
		cout << "Moi nhap so tien can rut, la boi so cua 50,000: ";
		do
		{			
			cin >> s_withdraw_amount;
			if (isNumber(s_withdraw_amount))
			{
				withdraw_amount = std::stof(s_withdraw_amount);
				if (withdraw_amount % 50000 == 0)
				{
					break;
				}
				else
				{
					cout << "So tien nhap vao phai la boi so cua 50,000" << endl;
					cout << "Moi nhap lai: ";
				}
				
			}
		} while (true);
		
		cout << endl;
		break;

		// Ending advanced implementation

	case 8:
		cout << "\nVe man hinh chinh..." << endl;
		system("pause");
		ShowMenu();
		return;
	}
	if (balance_amount < withdraw_amount) {
		//your code here
		cout << "So du nho hon " << withdraw_amount << ", khong the thuc hien giao dich" << endl;
		std::cout.precision(0);
		cout << std::fixed << "So du hien tai trong tai khoan: " << MoneyFormat(balance_amount) << " VND" << endl;
		cout << "\nAn phim bat ky de tro ve man hinh chinh..." << endl;
		system("pause");
		ShowMenu();
		return;
	}
	else {
		//your code here
		balance_amount -= withdraw_amount;
		cout << "Rut " << MoneyFormat(withdraw_amount) << " VND tu:" << endl;
		cout << "So tai khoan: " << account_number << endl;
		std::cout.precision(0);
		cout << std::fixed << "So du hien tai: " << MoneyFormat(balance_amount) << " VND" << endl;
		cout << "Vui long nhan lai the ATM va kiem tra tien truoc khi di" << endl;
		system("pause");
		ShowMenu();
	}	
}


// Nap tien vao tai khoan
void Deposit()
{
	system("cls");
	cout << "Nap tien" << endl;
	//your code here
	do
	{		
		cin >> deposit_amount;
		if (deposit_amount == 0)
		{
			cout << "So tien khong duoc bang 0 VND" << endl;
			cout << "Nap tien" << endl;
		}

	} while (deposit_amount <= 0);
	

	balance_amount += deposit_amount;

	std::cout.precision(0);
	cout << std::fixed << "\nSo du hien tai: " << MoneyFormat(balance_amount) << " VND" << endl;
	cout << endl;
	system("pause");
	ShowMenu();
}

// Ngung giao dich
void Eject()
{
	system("cls");
	cout << "--ATM C++--" << endl;
	cout << "\nKet thuc..." << endl;
	cout << "\nVui long nhan the va tien o khe cam" << endl;
	cout << "\nCam on quy khach da su dung dich vu tai ATM C++" << endl;
}



