#include<bits/stdc++.h>
using namespace std;

class application{
    private:
    string message;

    public:
    void get(string msg,bool txrx){
        if(txrx){
            message = msg;
        }
        else{
            message = msg.substr(2);
        }
    }

    string print(){
        return message;
    }
};

class transport{

    private:
    string header = "TL";
    string tlmessage;

    public:
    void get(string msg, bool txrx){
        if(txrx){
            tlmessage = header + msg;
        }
        else{
            tlmessage = msg.substr(2);
        }
    }

    string print(){
        return tlmessage;
    }
};

class network{

    private:
    string header = "NL";
    string nlmessage;

    public:
    void get(string msg, bool txrx){
        if(txrx){
            nlmessage = header + msg;
        }
        else{
            nlmessage = msg.substr(2);
        }
    }

    string print(){
        return nlmessage;
    }
};

class datalink{

    private:
    string header = "DL";
    string dlmessage;

    public:
    void get(string msg, bool txrx){
        if(txrx){
            dlmessage = header + msg;
        }
        else{
            dlmessage = msg;
        }
    }

    string print(){
        return dlmessage;
    }
};

class physical{
    private:
    vector<int> dstream;

    public:
    void get(string msg, bool txrx){
        if(txrx){
            int n = msg.size();
            dstream.resize(n);
            for(int i=0; i<n; i++) dstream[i] = (int)msg[i];
        }
        else{
            dstream.clear();
            stringstream s(msg);
            int temp;
            while(s>>temp){
                dstream.push_back(temp);
            }
        }
    }

    string print(bool txrx){
        if(txrx){
            stringstream ss;
            for(auto ascii: dstream) ss<<ascii<<" ";
            return ss.str(); 
        }
        else{
            string output = "";
            for(auto ascii: dstream) output += char(ascii);
            return output;
        }
    }
};

int main(){
    application al;
    transport tl;
    network nl;
    datalink dl;
    physical pl;

    cout<<"Enter the value of txrx: ";
    int temp;
    cin>>temp;
    bool txrx = (temp==1);

    if(txrx){
        // For Transmission
        cout<<"Enter Message: ";
        string message;
        cin>>message;
        al.get(message, txrx);
        cout<<al.print()<<endl;
        tl.get(al.print(), txrx);
        cout<<tl.print()<<endl;
        nl.get(tl.print(), txrx);
        cout<<nl.print()<<endl;
        dl.get(nl.print(), txrx);
        cout<<dl.print()<<endl;
        pl.get(dl.print(), txrx);
        cout<<pl.print(txrx)<<endl;
    }
    else{
        // For Reception
        cout<<"Enter Message at Physical Layer: ";
        string message;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, message);

        pl.get(message, txrx);
        cout<<pl.print(txrx)<<endl;
        dl.get(pl.print(txrx), txrx);
        cout<<dl.print()<<endl;
        nl.get(dl.print(), txrx);
        cout<<nl.print()<<endl;
        tl.get(nl.print(), txrx);
        cout<<tl.print()<<endl;
        al.get(tl.print(), txrx);
        cout<<al.print()<<endl;
    }


    return 0;
}