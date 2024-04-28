#include <iostream>
#include <cstring>
#include <bitset>
#include <iomanip>

using namespace std;

string base2 (int base10)
{
    char symbols[2] = {'0', '1'};
    string result ="";
    while (base10 > 0)
    {
        result = symbols[base10 % 2] + result;
        base10 /= 2;
    }

    return result;
}
class R{
public:
    string st[8] = {"01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111"};

    string turn_register(char a){
        return st[a-'0'];
    }
};

class I{
public:
    string st[8] = {"01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111"};

    string turn_register(char a){
        return st[a-'0'];
    }
};


int main(){
    string instr,rd,rs,rt;
    int imm;
    I Itype;
    R Rtype;

    while(cin >> instr){
        if(instr == "addi"){//  I
            cin >> rt >> rs >> imm;
            string Imm = base2(imm);
            cout << "001000" << Itype.turn_register(rs[2]) << Itype.turn_register(rt[2]) <<  setw(16) << setfill('0') << Imm << endl;
        }

        else{//  R
            cin >> rd >> rs >> rt;
            if(instr == "add")
                cout << "000000" << Rtype.turn_register(rs[2]) << Rtype.turn_register(rt[2]) << Rtype.turn_register(rd[2]) << "00000100000" << endl;
            else if(instr == "sub")
                cout << "000000" << Rtype.turn_register(rs[2]) << Rtype.turn_register(rt[2]) << Rtype.turn_register(rd[2]) << "00000100010" << endl;
            else if(instr == "or")
                cout << "000000" << Rtype.turn_register(rs[2]) << Rtype.turn_register(rt[2]) << Rtype.turn_register(rd[2]) << "00000100101" << endl;
            else if(instr == "and")
                cout << "000000" << Rtype.turn_register(rs[2]) << Rtype.turn_register(rt[2]) << Rtype.turn_register(rd[2]) << "00000100100" << endl;
        }
    }

    return 0;
}





