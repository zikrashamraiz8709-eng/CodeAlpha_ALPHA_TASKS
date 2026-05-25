#include<iostream>
#include<vector>
#include<string>

using namespace std;;

int main()
{
	int crs_no;
	int sem;
	float total_points = 0.0;
	int total_credits = 0;
	
	cout << "\t\t\t\t============================================" << endl;
	cout << "\t\t\t\t||            CGPA CLACULATOR             ||" << endl;
	cout << "\t\t\t\t============================================" << endl;
	
	// Semester Input Validation
	do
	{
	cout << "\nENTER NO OF SEMESTERS : ";
	cin >> sem;

	if (cin.fail() || sem <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "INVALID INPUT! PLEASE ENTER A POSITIVE NUMBER.\n";
	}

	} while (sem <= 0);

	for (int j = 1; j <= sem; j++)
	{
		float sem_points = 0.0;
		int sem_credits = 0;

		cout << "\n============ SEMESTER " << j << " ============\n"<<endl;
		
		do{
		cout << "ENTER NUMBER OF COURSES TAKEN : ";
		cin >> crs_no;

		if (cin.fail() || crs_no <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "\nINVALID INPUT! ENTER A POSITIVE NUMBER.\n";
		}

		} while (crs_no <= 0);

		cout << endl;

		vector<string> c_name(crs_no);
		vector<char> grade(crs_no);
		vector<int> credit_hrs(crs_no);
		vector<float> grade_points(crs_no);

		for (int i = 0; i < crs_no; i++)
		{
			cout << "ENTER THE COURSE " << i + 1 << " NAME : ";
			cin>> c_name[i];

			// Grade Validation
			while (true)
			{
				cout << "ENTER THE GRADE (A, B, C, D, F) : ";
				cin >> grade[i];

				grade[i] = toupper(grade[i]);

				if (grade[i] == 'A' || grade[i] == 'B' || grade[i] == 'C' || grade[i] == 'D' ||grade[i] == 'F')
				{
					break;
				}

				cout << "INVALID GRADE! PLEASE ENTER A, B, C, D, OR F.\n";
			}

			// Credit Hour Validation	
			do
			{
				cout << "ENTER CREDIT HOURS OF THE COURSE : ";
				cin >> credit_hrs[i];

				if (cin.fail() || credit_hrs[i] <= 0)
				{
					cin.clear();
					cin.ignore(1000, '\n');

					cout << "INVALID CREDIT HOURS! ENTER A POSITIVE NUMBER.\n";
				}

			} while (credit_hrs[i] <= 0);
              cout << endl;
			// converting grade into points

			switch (grade[i])
			{
			case 'A':
			
				grade_points[i] = 4.0;
				break;
			
			case 'B':
			
				grade_points[i] = 3.0;
				break;
			
			case 'C':
			
				grade_points[i] = 2.0;
				break;
			
			case 'D':
			
				grade_points[i] = 1.0;
				break;
			
			case 'F':
			
				grade_points[i] = 0.0;
				break;
			
			default:
				grade_points[i] = 0.0;
			}

			sem_points += grade_points[i] * credit_hrs[i];
			sem_credits += credit_hrs[i];

		}
		float sem_gpa = sem_points / sem_credits;

		total_points += sem_points;
		total_credits += sem_credits;

		cout << "\n========== SEMESTER " << j << " RESULT ==========\n";

		for (int i = 0; i < crs_no; i++)
		{
			cout << "\nCOURSE : " << c_name[i] << endl;
			cout << "GRADE : " << grade[i] << endl;
			cout << "CREDIT HOURS : "<< credit_hrs[i] << endl;
		}
		cout << "\nSEMESTER GPA : " << sem_gpa << endl;
	}
	
	float final_cgpa = total_points / total_credits;
	cout << "\n========== FINAL ==========\n";
	cout << "\nFINAL CGPA : " << final_cgpa << endl;

	return 0;
}