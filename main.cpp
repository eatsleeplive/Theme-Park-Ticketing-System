#include <iostream>
#include <iomanip>
using namespace std;

void title() {
    cout << "\n\t|------------------------------------------------------|";
    cout << "\n\t|\tW A T E R   S P L A S H   T H E M E   P A R K   |";
    cout << "\n\t|------------------------------------------------------|";
}

void displayOutput(char ticket_type, int quantity1, int quantity2, int quantity3, 
float customerAmount, float userBalance) {
    cout << "\t----------------------R E C E I P T   P U R C H A S E----------------------" << endl;
    cout << "\tTicket Type                                  : " << ticket_type << endl;
    cout << "\tQuantity of children                         : " << quantity1 << endl;
    cout << "\tQuantity of adults                           : " << quantity2 << endl;
    cout << "\tQuantity of disabled person                  : " << quantity3 << endl;
    cout << "\tAmount payment                               : " << setprecision(2) << customerAmount << endl;
    cout << "\tBalance amount                               : " << setprecision(2) << userBalance << endl;
    cout << "\t------------------------------------------------------------------" << endl;
}

float calcSum(float price_1, float price_2, float price_3) 
{
    return price_1 + price_2 + price_3;
}

float calcMemberPrice(float total) 
{
    return total * 0.9;
}

float calcBalance(float amount, float finalPrice) 
{
    return amount - finalPrice;
}

void ticket(int* countCust, float* sum, float* avrg) 
{
    char ticket_Type, membership;
    int quantity1, quantity2, quantity3;
    float customerAmount, userBalance, price_1, price_2, price_3, total;

    //Prompt the user to enter the day they want to come
    cout << endl;
    cout << "\t[ 0 - Wednesday -- 1 - Thursday -- 2 - Friday -- 3 - Saturday -- 4 - Sunday ]" << endl;
    int dayChoice;
    cout << "\n\tEnter the day you want to come : ";
    cin >> dayChoice;

    //Update the countCust array based on the day chosen by the user
    countCust[dayChoice]++;

    cout << "\tEnter ticket type [F- Fast lane/N- Normal lane] : ";
    cin >> ticket_type;

    cout << fixed << showpoint;
    if(ticket_type == 'F' || ticket_type == 'f') 
    {
        cout << "\tEnter the quantity of children : ";
        cin >> quantity1;
        
        cout << "\tEnter the quantity of adults : ";
        cin >> quantity2;

        cout << "\tEnter the quantity of disabled persons : ";
        cin >> quantity3;

        price_1 = quantity1 * 55.00;
        price_2 = quantity2 * 55.00;
        price_3 = quantity3 * 55.00;

        total = calcSum(price_1, price_2, price_3);

        cout << "\tDo you have a membership? [Y-Yes/N-No] : ";
        cin >> membership;

        if(membership == 'Y' || membership == 'y') 
        {
            total = calcMembershipPrice(total);
        }
        cout << "\tTotal : RM" << setprecision(2) << total << endl;

        do 
        {
            cout << "\tEnter amount : RM";
            cin >> customerAmount;
            cout << endl;

            if(customerAmount < total) 
            {
                cout << "\tInsufficient amount." << endl;
            }
        } while (customerAmount < total);

        userBalance = calcBalance(customerAmount, total);
        displayOutput(ticket_type, quantity1, quantity2, quantity3, customerAmount, userBalance);

        sum[dayChoice] += total;
        avrg[dayChoice] = sum[dayChoice] / countCust[dayChoice];
    }
    else if(ticket_type == 'N' || ticket_type == 'n') 
    {
        cout << "\tEnter the quantity of children : ";
        cin >> quantity1;

        cout << "\tEnter the quantity of adults : ";
        cin >> quantity2;

        cout << "\tEnter the quantity of disabled persons : ";
        cin >> quantity3;

        price_1 = quantity1 * 45.00;
        price_2 = quantity2 * 60.00;
        price_3 = quantity3 * 35.00;

        total = calcSum(price_1, price_2, price_3);

        cout << "\tDo you have a membership? [Y-Yes/N-No] : ";
        cin >> membership;

        if(membership == 'Y' || membership == 'y') {
            total = calcMembershipPrice(total);
        }
        cout << "\tTotal : RM" << setprecision(2) << total << endl;

        do {
            cout << "\tEnter amount : RM";
            cin >> customerAmount;
            cout << endl;

            if(customerAmount < total) {
                cout << "\tInsufficient amount." << endl;
            }
        } while (customerAmount < total);

        userBalance = calcBalance(customerAmount, total);
        displayOutput(ticket_type, quantity1, quantity2, quantity3, customerAmount, userBalance);

        sum[dayChoice] += total;
        avrg[dayChoice] = sum[dayChoice] / countCust[dayChoice];
    }
}

void displayHighestCustomer(int* countCust) {
    int daysOpen = 5;
    int custMax = 0;
    int day = 0;

    for(int counter = 0; counter < daysOpen; counter++) {
        if(countCust[counter] > custMax) {
            custMax = countCust[counter];
            day = counter;
        }
    }

    cout << "\n\t------------------------------------------" << endl;
    cout << "\tDay with the highest number of customers : ";
    switch(day) {
        case 0:
            cout << "Wednesday";
            break;

        case 1:
            cout << "Thursday";
            break;
        
        case 2:
            cout << "Friday";
            break;

        case 3:
            cout << "Saturday";
            break;
        
        case 04:
            cout << "Sunday";
            break;

        default:
            cout << "Unknown";
            break;
    }
    cout << " (" << custMax << " customers)" << endl;
    cout << "\n\t------------------------------------------" << endl;
}

int main() {
    const int daysOpen = 5;
    int countCust[daysOpen] = {0};
    float sum[daysOpen] = {0.0};
    float avrg[daysOpen] = {0.0};

    for(int i = 0; i < 50000; i++) {
        title();
        ticket(countCust, sum, avrg);

        char customerResponse;
        if(i < 49999) {
            cout << "\n\t\t\t\tContinue for another customer? [Y/N] : ";
            cin >> customerResponse;
            if(customerResponse != 'Y' && customerResponse != 'y') 
                break;
        }
    }
    cout << "\n\t------------------------------------" << endl;

    //calculate and display the average sales for each day
    for(int counter = 0; counter < daysOpen; counter++) {
        if(countCust[counter] > 0) {
            avrg[counter] = sum[counter] / countCust[counter];
        }
    }
    cout << "\n\tAverage sales for each day" << endl;
    cout << "\t----------------------------------------------" << endl;

    for(int counter = 0; counter < daysOpen; counter++) {
        cout << "\t";
        switch(counter) {
            case 0:
            cout << "Wednesday";
            break;

        case 1:
            cout << "Thursday";
            break;
        
        case 2:
            cout << "Friday";
            break;

        case 3:
            cout << "Saturday";
            break;
        
        case 04:
            cout << "Sunday";
            break;

        default:
            cout << "Unknown";
            break;
        }
        cout << ": RM " << setprecision(2) << avrg[counter] << endl;
    }

    //call the new function to display the day with highes number of customers
    displayHighestCustomers(countCust);

    return 0;
}

