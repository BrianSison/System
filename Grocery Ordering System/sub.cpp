#include<iostream>
#include<ctime>

class Store{
    private:
        std::string username, password;

        std::string* user_name = new std::string[5];
        std::string* user_password = new std::string[5];
        int* user_balance = new int[5];
        int userbalance, stocks, user_input, brand_choice, user_temp;

        std::string Milk_brand[5] = {"BearBrand", "Dairy", "Cow", "Brand X", "Poison"};
        int Milk_stocks[5] = {27, 29, 31, 23, 32};
        int Milk_prize[5] = {12, 11, 10, 23, 12};

        bool logIn;
        
    public:
        Store(){
            default_value();
            user_name[0]="admin";
            user_password[0]="admin";
            user_balance[0] = 99999;
        }
        void default_value(){
            for(int x=0;x<5;x++){
                user_name[x] = "0";
                user_password[x] = "0"; 
                user_balance[x] = 0;
            }
        }
        void display(){
            std::cout << std::endl;
            for(int x=0;x<5;x++){
                std::cout << user_name[x] << " " << user_password[x] <<  " " << user_balance[x] << std::endl;
            } 
            std::cout << std::endl;
        }
        void LogIn(std::string x, std::string y){
            username = x;
            password = y;
        }
        std::string username_return(){
            return username;
        }
        std::string userpassword_return(){
            return password;
        }
        int userbalance_return(){
            return user_balance[userbalance];
        }
        void checker(std::string user, std::string pass){
            for(int x=0;x<5;x++){
                if(user_name[x] == user && user_password[x] == pass){
                    std::cout << "\nLog In successfully";
                    logIn = true;
                    userbalance=x;
                    break;
                }
                else if(user_name[x] == user && user_password[x] != pass){
                    std::cout << "\nInvalid password";
                    break;
                }
            }
        }
        bool user_logIn(){
            return logIn;
        }
        void display_user(){
            std::cout << "\n\nUser Currently Log in: " << username_return();
            std::cout << "\nuser balance: " << userbalance_return() << std::endl;
        }
        void shopping(bool x){
            if(x==true){
                display_items();
            }
            else{
                system("exit");
            }
        }
        void display_items(){
            std::cout << "\n\nItems on sale" << std::endl;
            for(int x=0;x<5;x++){
                std::cout << "-------------------------------------------|";
                std::cout << "\n|" << 1+x <<  ". Brand: " << Milk_brand[x];
                std::cout << "\n|Stocks: " << Milk_stocks[x];
                std::cout << "\n|Prize: " << Milk_prize[x] << std::endl; 
            }
            std::cout << "-------------------------------------------|";

        }
        void receipt_display(){
            std::time_t currentTime = std::time(nullptr);
            std::tm* localTime = std::localtime(&currentTime);
            char timeBuffer[80];
            std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localTime);
         
            std::cout << "\n------- Receipt -------";
            std::cout << "\nMilk Store             Curren time: " << timeBuffer;
            
            std::cout << "\n\n---Milk purchase " << Milk_brand[brand_choice];
            std::cout << "\n-Number of purchase " << user_input;
            std::cout << "\n-------------------------|";
            std::cout << "\n\ntotal amount: " << user_temp;

            std::cout << "\n|-----------------------|";
            std::cout << "\n| Thank you come again! |";
            std::cout << "\n|-----------------------|";
        }
        void purchase(){
            display_user();
            std::cout << "\nWhat would you like to purchase? "; std::cin >> brand_choice;
            if(brand_choice < 1 || brand_choice > 5){
                std::cout << "\n|---------------------------|";
                std::cout << "\n| Invalid Input! Try again! |";
                std::cout << "\n|---------------------------|";
                purchase();
            }


            std::cout << "\nHow much would you like to purchase? "; std::cin >> user_input;
            if(user_input > Milk_stocks[brand_choice-1]){
                std::cout << "\n|------------------------------------|";
                std::cout << "\n| Invalid input! Exceeds the stocks! |";
                std::cout << "\n|------------------------------------|";
                purchase();
            }
            
            Milk_stocks[brand_choice-1] = Milk_stocks[brand_choice-1] - user_input; 
            user_temp = Milk_prize[brand_choice-1] * user_input;
            user_balance[userbalance] -= user_temp;

            std::string receipt;
            std::cout << "\nWould you like a receipt? Y/N: "; std::cin >> receipt;
            if(receipt == "y" || receipt == "Y"){
                receipt_display();
            }
            else{
                std::cout << "\n|-----------------------|";
                std::cout << "\n| Thank you come again! |";
                std::cout << "\n|-----------------------|";
            }
        }

};

int main(){
    Store st;

    std::string username, password;
    std::string name, pass;
    bool x;
    int y;

    std::cout << "\n*************";
    std::cout << "\n| Milk Shop |";
    std::cout << "\n*************";

    std::cout << "\n\n------------------------";
    std::cout << "\n|Username: "; std::cin >> username;
    std::cout << "\n------------------------";
    std::cout << "\n|Password: "; std::cin >> password;
    std::cout << "\n------------------------\n";


    st.LogIn(username, password);
    name = st.username_return();
    pass = st.userpassword_return();
    st.checker(name, pass);
    x = st.user_logIn();
    st.userbalance_return();

    st.shopping(x);
    st.purchase();
    st.display();

}#include<iostream>
#include<ctime>

class Store{
    private:
        std::string username, password;

        std::string* user_name = new std::string[5];
        std::string* user_password = new std::string[5];
        int* user_balance = new int[5];
        int userbalance, stocks, user_input, brand_choice, user_temp;

        std::string Milk_brand[5] = {"BearBrand", "Dairy", "Cow", "Brand X", "Poison"};
        int Milk_stocks[5] = {27, 29, 31, 23, 32};
        int Milk_prize[5] = {12, 11, 10, 23, 12};

        bool logIn;
        
    public:
        Store(){
            default_value();
            user_name[0]="admin";
            user_password[0]="admin";
            user_balance[0] = 99999;
        }
        void default_value(){
            for(int x=0;x<5;x++){
                user_name[x] = "0";
                user_password[x] = "0"; 
                user_balance[x] = 0;
            }
        }
        void display(){
            std::cout << std::endl;
            for(int x=0;x<5;x++){
                std::cout << user_name[x] << " " << user_password[x] <<  " " << user_balance[x] << std::endl;
            } 
            std::cout << std::endl;
        }
        void LogIn(std::string x, std::string y){
            username = x;
            password = y;
        }
        std::string username_return(){
            return username;
        }
        std::string userpassword_return(){
            return password;
        }
        int userbalance_return(){
            return user_balance[userbalance];
        }
        void checker(std::string user, std::string pass){
            for(int x=0;x<5;x++){
                if(user_name[x] == user && user_password[x] == pass){
                    std::cout << "\nLog In successfully";
                    logIn = true;
                    userbalance=x;
                    break;
                }
                else if(user_name[x] == user && user_password[x] != pass){
                    std::cout << "\nInvalid password";
                    break;
                }
            }
        }
        bool user_logIn(){
            return logIn;
        }
        void display_user(){
            std::cout << "\n\nUser Currently Log in: " << username_return();
            std::cout << "\nuser balance: " << userbalance_return() << std::endl;
        }
        void shopping(bool x){
            if(x==true){
                display_items();
            }
            else{
                system("exit");
            }
        }
        void display_items(){
            std::cout << "\n\nItems on sale" << std::endl;
            for(int x=0;x<5;x++){
                std::cout << "-------------------------------------------|";
                std::cout << "\n|" << 1+x <<  ". Brand: " << Milk_brand[x];
                std::cout << "\n|Stocks: " << Milk_stocks[x];
                std::cout << "\n|Prize: " << Milk_prize[x] << std::endl; 
            }
            std::cout << "-------------------------------------------|";

        }
        void receipt_display(){
            std::time_t currentTime = std::time(nullptr);
            std::tm* localTime = std::localtime(&currentTime);
            char timeBuffer[80];
            std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localTime);
         
            std::cout << "\n------- Receipt -------";
            std::cout << "\nMilk Store             Curren time: " << timeBuffer;
            
            std::cout << "\n\n---Milk purchase " << Milk_brand[brand_choice];
            std::cout << "\n-Number of purchase " << user_input;
            std::cout << "\n-------------------------|";
            std::cout << "\n\ntotal amount: " << user_temp;

            std::cout << "\n|-----------------------|";
            std::cout << "\n| Thank you come again! |";
            std::cout << "\n|-----------------------|";
        }
        void purchase(){
            display_user();
            std::cout << "\nWhat would you like to purchase? "; std::cin >> brand_choice;
            if(brand_choice < 1 || brand_choice > 5){
                std::cout << "\n|---------------------------|";
                std::cout << "\n| Invalid Input! Try again! |";
                std::cout << "\n|---------------------------|";
                purchase();
            }


            std::cout << "\nHow much would you like to purchase? "; std::cin >> user_input;
            if(user_input > Milk_stocks[brand_choice-1]){
                std::cout << "\n|------------------------------------|";
                std::cout << "\n| Invalid input! Exceeds the stocks! |";
                std::cout << "\n|------------------------------------|";
                purchase();
            }
            
            Milk_stocks[brand_choice-1] = Milk_stocks[brand_choice-1] - user_input; 
            user_temp = Milk_prize[brand_choice-1] * user_input;
            user_balance[userbalance] -= user_temp;

            std::string receipt;
            std::cout << "\nWould you like a receipt? Y/N: "; std::cin >> receipt;
            if(receipt == "y" || receipt == "Y"){
                receipt_display();
            }
            else{
                std::cout << "\n|-----------------------|";
                std::cout << "\n| Thank you come again! |";
                std::cout << "\n|-----------------------|";
            }
        }

};

int main(){
    Store st;

    std::string username, password;
    std::string name, pass;
    bool x;
    int y;

    std::cout << "\n*************";
    std::cout << "\n| Milk Shop |";
    std::cout << "\n*************";

    std::cout << "\n\n------------------------";
    std::cout << "\n|Username: "; std::cin >> username;
    std::cout << "\n------------------------";
    std::cout << "\n|Password: "; std::cin >> password;
    std::cout << "\n------------------------\n";


    st.LogIn(username, password);
    name = st.username_return();
    pass = st.userpassword_return();
    st.checker(name, pass);
    x = st.user_logIn();
    st.userbalance_return();

    st.shopping(x);
    st.purchase();
    st.display();

}