#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &nickname,vector<int> &score, vector<char> &mygrade)
{    
    ifstream source;
    source.open(filename); 
    string havetext;
    while (getline(source,havetext))
    {
    const char * cStr  = havetext.c_str();
    char format[] = "%[^:]: %d %d %d";
    char name[100];
    char grade;
    int a,b,c;
    sscanf(cStr,format,name,&a,&b,&c); 
    int sumscore = a+b+c;
    grade = score2grade(sumscore);
    nickname.push_back(name);
    score.push_back(sumscore);
    mygrade.push_back(grade);
    }


    


    
}

void getCommand(string &command,string &key)
{   
    string s;
    char x[100];
    char xx[100];
    char format[] = "%s %[^\n]";
    cout << "Please input your command: ";
    
    getline(cin,s);
    sscanf(s.c_str(),format,x,xx);
    command = x;
    key = xx;
    


}

void searchName(vector<string> name,vector<int>score,vector<char>grade, string key)
{   
    bool stayhere =false;
    for(unsigned int i =0; i < name.size(); i++)
    {
        if(key == toUpperStr(name[i]))
        {   
            cout << "---------------------------------" << endl;
            cout << name[i] << "'s" << " score = " << score[i] << endl;
            cout << name[i] << "'s" << " grade = " << grade[i] << endl;
            cout << "---------------------------------" << endl;
            stayhere = true;
            break;
        }   
        

    }  
    if(stayhere == false) cout << "---------------------------------" << endl << "Cannot found." <<endl << "---------------------------------" << endl;
}

void searchGrade(vector<string> name,vector<int>score,vector<char>grade, string key)
{   
    bool stayhere = false;
    const char * cStr  = key.c_str();
    cout << "---------------------------------" << endl;
    for(unsigned int i =0; i < name.size(); i++) 
    {
        if(*cStr == grade[i]) cout << name[i] <<" (" << score[i] << ")" << endl;
        stayhere = true;
    }
    if(stayhere == false) cout << "---------------------------------" << endl << "Cannot found." <<endl;
    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
