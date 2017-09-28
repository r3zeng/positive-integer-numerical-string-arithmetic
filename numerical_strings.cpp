#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int i1, int i2){
    if(i1 > i2){
        return i1;
    }else{
        return i2;
    }
}

int char_to_int(char c){
    int t = c;
    return t - 48;
}

void front_fill_zeros (string &num, int length){
    string zero ("0");
    while(num.length() < length){
        num = zero + num;
    }
}

void append_zeros(string &num, int amount){
    string zero("0");
    for(int i = 0; i < amount; i++){
        num = num + zero;
    }
}

void remove_leading_zeros(string &num && num.length()>1){
    while(num.substr(0,1) == "0"){
        num = num.substr(1, num.length()-1);
    }
}

string add_numerical_string (string s1, string s2){
    string s = "";
    
    int length;
    length = max(s1.length(), s2.length());
    front_fill_zeros(s1, length);
    front_fill_zeros(s2, length);

    int carry = 0;

    for(int i = 0; i < length; i++){
        int s1_digit = char_to_int(s1.at(length - i -1));
        int s2_digit = char_to_int(s2.at(length - i -1));
        int total = s1_digit + s2_digit + carry;
        carry = total / 10;
        s = to_string(total % 10) + s;
    }
    if(carry != 0){
        s = to_string(carry) + s;
    }
    remove_leading_zeros(s);
    return s;
}

//pre: s1 >= s2
string sub_numerical_string (string s1, string s2){
    string s = "";
    
    int length;
    length = max(s1.length(), s2.length());
    front_fill_zeros(s1, length);
    front_fill_zeros(s2, length);

    int carry = 0;

    for(int i = 0; i < length; i++){
        int s1_digit = char_to_int(s1.at(length - i -1));
        int s2_digit = char_to_int(s2.at(length - i -1));
        bool b = false;
        if(s1_digit  + carry < s2_digit){
            s1_digit = s1_digit + 10;
            b = true;
        }
        int total = s1_digit - s2_digit + carry;
        s = to_string(total % 10) + s;
        if(b){
            carry = -1;
        }else{
            carry = 0;
        }
    }

    remove_leading_zeros(s);
    return s;
}


string mul_numerical_string (string s1, string s2){
    string s = "0";
    
    int length;
    length = max(s1.length(), s2.length());
    front_fill_zeros(s1, length);
    front_fill_zeros(s2, length);

    vector<string> rows;

    int carry = 0;

    for(int i = 0; i < s2.length(); i++){
        string s_temp ("");
        int s2_digit = char_to_int(s2.at(length -i -1));
        for(int j = 0; j < s1.length(); j++){
            int s1_digit = char_to_int(s1.at(length -j -1));
            int total = (s1_digit * s2_digit) + carry;
            carry = total / 10;
            s_temp = to_string(total % 10) + s_temp;
        }
	if(carry != 0){
            s_temp = to_string(carry) + s_temp;
        }
        append_zeros(s_temp, i);
        rows.push_back(s_temp);
    }

    for(int i = 0; i < rows.size(); i++){
        s = add_numerical_string(s, rows[i]);
    }

    remove_leading_zeros(s);
    return s;
}

bool equal_to_numerical_string (string s1, string s2){
	remove_leading_zeros(s1);
	remove_leading_zeros(s2);

	if(s1 == s2){
		return true;
	}else{
		return false;
	}
}

bool greater_than_numerical_string (string s1, string s2){

	if(equal_to_numerical_string(s1, s2)){
		return false;
	}

	remove_leading_zeros(s1);
	remove_leading_zeros(s2);

	if(s1.length() > s2.length()){
		return true;
	}else if(s2.length() > s1.length()){
		return false;
	}

	for(int i = 0; i < s1.length(); i++){
		if(char_to_int(s1.at(i)) > char_to_int(s2.at(i))){
			return true;
		}else if(char_to_int(s1.at(i)) < char_to_int(s2.at(i))){
			return false;
		}
	}
	return false;
}

int main()
{
    string s1 ("123");
    string s2 ("123");
    bool s = greater_than_numerical_string(s1, s2);
    cout << s << endl;

    return 0;
}



