#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
int id = 0;
struct admin_data
{
    string name;
    string a_pass;
    int count;
};
struct member_data
{
    int member_id;
    char name[50];
    char sex;
    string contact;
    string service_type;
    string preferred_timing;
    double monthly_fee;
};
member_data members[50];
void save_member()
{
    int n;
    members[id].member_id = id + 1;
    cout << "Enter your Name:";
    cin >> members[id].name;
    cin.ignore();
    cout
        << "Enter your Gender:";
    cin >> members[id].sex;
    cout << "Enter your contact:";
    cin >> members[id].contact;
again_service:
    cout << "Select service type\n1.Gym lonely(400 birr)\n2.Gym + Aerobic(800 birr)\n3.Gym + Yoga(800 birr)\n";
    cin >> n;
    switch (n)
    {
    case 1:
        members[id].service_type = "Gym lonely";
        members[id].monthly_fee = 400;
        break;
    case 2:
        members[id].service_type = "Gym + Aerobic";
        members[id].monthly_fee = 800;
        break;
    case 3:
        members[id].service_type = "Gym + Yoga";
        members[id].monthly_fee = 800;
        break;
    default:
        cout << "Invalid";
        goto again_service;
        break;
    }
again_time:
    cout << "please select your preferred timings\n";
    cout << "1.Morining\n2.Evening\n";
    cin >> n;
    switch (n)
    {
    case 1:
        members[id].preferred_timing = "Moring";
        break;
    case 2:
        members[id].preferred_timing = "Evening";
        break;
    default:
        cout << "Invalid";
        goto again_time;
        break;
    }
    system("cls");
    cout << "***********\n";
    cout << "Your Profile data:";
    cout << "\n***********\n";
    cout << endl
         << "member ID: " << members[id].member_id;
    cout << endl
         << "Name: " << members[id].name;
    cout << endl
         << "Gender: " << members[id].sex;
    cout << endl
         << "category: " << members[id].service_type;
    cout << endl
         << "fee: " << members[id].monthly_fee;
    cout << endl
         << "contact: " << members[id].contact;
    cout << endl
         << "timings: " << members[id].preferred_timing;
    cout << "\n\nthe member has been succesfully added......\n";
    id += 1;
}

void delete_member()
{
    int m;
    cout << "Please Enter The member ID:";
    cin >> m;
    for (int i = 0; i <= id; i++)
    {
        if (members[i].member_id == m)
        {
            members[i].member_id = '\0';
            // members[i].name = '\0';
            members[i].sex = '\0';
            members[i].service_type = '\0';
            members[i].preferred_timing = '\0';
            members[i].monthly_fee = '\0';
            members[i].contact = '\0';
            break;
        }
    }
    cout << endl
         << endl
         << "\tRecord Deleted...\n";
}

void edit_member()
{
    system("cls");
    int m, n;
    cout
        << "Please Enter The member ID: ";
    cin >> m;
    for (int i = 0; i <= id; i++)
    {
        if (members[i].member_id == m)
        {
            cout << "***********\n";
            cout << "Original data:";
            cout << "\n***********\n";
            cout << endl
                 << "member ID: " << members[i].member_id;
            cout << endl
                 << "Name: " << members[i].name;
            cout << endl
                 << "Gender: " << members[i].sex;
            cout << endl
                 << "category: " << members[i].service_type;
            cout << endl
                 << "fee: " << members[i].monthly_fee;
            cout << endl
                 << "contact: " << members[i].contact;
            cout << endl
                 << "timings: " << members[i].preferred_timing;
                 cout << "\n\n";
            cout << "Please Enter your Updates:\n";
            cout << "Enter your Name:";
            cin >> members[i].name;
            cout << "Enter your Gender:";
            cin >> members[i].sex;
            cout << "Enter your contact:";
            cin >> members[i].contact;
        again_sservice:
            cout << "Select service type\n1.Gym lonely(400 birr)\n2.Gym + Aerobic(800 birr)\n3.Gym + Yoga(800 birr)\n";
            cin >> n;
            switch (n)
            {
            case 1:
                members[i].service_type = "Gym lonely";
                members[i].monthly_fee = 400;
                break;
            case 2:
                members[i].service_type = "Gym + Aerobic";
                members[i].monthly_fee = 800;
                break;
            case 3:
                members[i].service_type = "Gym + Yoga";
                members[i].monthly_fee = 800;
                break;
            default:
                cout << "Invalid";
                goto again_sservice;
                break;
            }
        aagain_time:
            cout << "please select your preferred timings\n";
            cout << "1.Morining\n2.Evening\n";
            cin >> n;
            switch (n)
            {
            case 1:
                members[i].preferred_timing = "Moring";
                break;
            case 2:
                members[i].preferred_timing = "Evening";
                break;
            default:
                cout << "Invalid";
                goto aagain_time;
                break;
            }
            cout << "\n\n\tRecord Successfully Updated...\n";
            break;
            }
    }
}
void user_service()
{
    for (;;)
    {
        int m;
        cout << "\n***********\n";
        cout << "\t1.Join gym\n\t2.Quit gym\n\t3.Edit your profile\n\t4.Enterance Menu\n\t5.EXIT!";
        cout << "\n***********\n";
        cout << endl
             << endl
             << "\tenter your choice:";
        cin >> m;
        if (m == 1)
        {
            system("cls");
            save_member();
        }
        else if (m == 2)
        {
            system("cls");
            delete_member();
            break;
        }
        else if (m == 3)
        {
            system("cls");
            edit_member();
            break;
        }
        else if (m == 4)
        {
            break;
        }
        else
        {
            exit(0);
        }
        /*
        switch (m)
        {
        case 1:
            system("cls");
            save_member();
            break;
        case 2:
            system("cls");
            delete_member();
            break;
            case 3:
            system("cls");
            edit_member();
            break;

        case 4:
            break;

        case 5:
            exit(0);
        }*/
    }
}
void show_all()
{
    cout << "ID\tName\t\tSex\t\tContact\t\tService\t\t\tFee\t\tTiming" << endl;
    for (int i = 0; i <= id; i++)
    {
        if (members[i].member_id != '\0')
        {

            cout << members[i].member_id << "\t" << members[i].name << "\t\t" << members[i].sex << "\t\t" << members[i].contact << "\t\t" << members[i].service_type << "\t\t" << members[i].monthly_fee << "\t\t" << members[i].preferred_timing << endl;
        }
    }
}
void display_record(int num)
{
    int i = num - 1;
    cout << "ID\tName\t\tSex\t\tContact\t\tService\t\t\tFee\t\tTiming" << endl;
    cout << members[i].member_id << "\t" << members[i].name << "\t\t" << members[i].sex << "\t\t" << members[i].contact << "\t\t" << members[i].service_type << "\t\t" << members[i].monthly_fee << "\t\t" << members[i].preferred_timing << "\n\n\n";
}
bool admin_login(admin_data admin)
{
    string name1;
    char ch;
    if (admin.count == 0)
    {
    name_again:
        cout << "Enter  pass_name:";
        cin >> name1;
        if (admin.name != name1)
        {
            cout << "INCORRECT\n";
            goto name_again;
        }
    Apass_again:
        cout << "Enter Apass(password):";
        cin >> name1;
        if (admin.a_pass != name1)
        {
                cout << "INCORRECT\n";
            goto Apass_again;
        }
        cout << "Do you went to change Pass_name and Apass(password) y/n :";
        cin >> ch;
        if (ch == 'y')
        {
            cout << "Enter new pass_name:";
            cin >> admin.name;
            cout << "Enter new Apass(password):";
            cin >> admin.a_pass;
        }
        admin.count += 1;
    }
    else
    {
    nname_again:
        cout << "Enter  pass_name:";
        cin >> name1;
        if (admin.name != name1)
        {
            cout << "INCORRECT\n";
            goto nname_again;
        }
    AApass_again:
        cout << "Enter Apass(password):";
        cin >> name1;
        if (admin.a_pass != name1)
        {
            cout << "INCORRECT\n";
            goto AApass_again;
        }
    }
    return true;
}
void Admin_service()
{
    for (;;)
    {
        int option;
        cout << "***********";
        cout << "\n\t1.CREATE MEMBER";
        cout << "\n\t2.DISPLAY ALL RECORDS";
        cout << "\n\t3.SEARCH FOR A PARTICULAR RECORD ";
        cout << "\n\t4.EDIT MEMBER DETAILS";
        cout << "\n\t5.DELETE MEMBER";
        cout << "\n\t6.GO BACK TO MAIN MENU";
        cout << "\n\t7.EXIT!";
        cout << "\n**********";

        cout << "\n\n\tSelect Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            save_member();
            break;

        case 2:
            system("cls");
            show_all();
            break;

        case 3:
            int num;
            system("cls");
            cout << "Please Enter The member ID: ";
            cin >> num;
            display_record(num);
            break;

        case 4:
            edit_member();
            break;

        case 5:
            delete_member();
            break;

        case 6:
            system("cls");
            break;
        case 7:
            cout << "GOOD BY";
            exit(0);
            break;
        }
    }
}

int main()
{
    system("cls");
    int i, n, m;
    string name, code;
Enterance:
    cout << "***********\n";
    cout << "Fitness Center (gym) management system" << endl;
    cout << "\n**********";
    cout
        << endl
        << "SELECT MODE" << endl
        << "1.User" << endl
        << "2.Admin" << endl
        << "3.Guidelines" << endl;
    cin >> i;

    if (i == 1)
    {
        cout << endl
             << "you're in user mode" << endl;
        user_service();
        goto Enterance;
    }
    else if (i == 2)
    {
        admin_data admin;
        admin.name = "Admin3040";
        admin.a_pass = "1234";
        admin.count = 0;
        if (admin_login(admin))
        {
            system("cls");
            cout << endl
                 << "you're in Admin mode" << endl;
            Admin_service();
        }
    }
    else
    {

        fstream guide;
        guide.open("guidelines.txt", ios::in);
        if (guide.is_open())
        {
            string line;
            while (getline(guide, line))
            {
                cout << line << endl;
            }
            guide.close();
        }
    }

    return 0;
}
