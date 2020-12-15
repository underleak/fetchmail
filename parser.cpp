#include "parser.h"
#include <vector>
#include <fstream>
#include <vector>

using namespace std;


void Parser::sendInfo(int id){


   ifstream file("/private/var/mail/pavelprodanov");

    string s;
    char c;

    while (!file.eof()){
        file.get(c);
        s.push_back(c);

    }

    file.close();
   system("> /private/var/mail/pavelprodanov");
    long int p=0;
    long int tmp2 = s.find("Subject: ");
    long int tmp3 = s.find("From: ");
    long int tmp4 = s.find("To: ");
    long int tmp5 = s.find("boundary=");
    if (tmp2==-1) return;
    tmp5+=10;

    string boundaryValue;

    for (int i = 0; i<=s.length(); i++) {

        for (long int i=s.find("\n",tmp2); tmp2<=i; tmp2++){

          this->subject.push_back(s.at(tmp2));

        }
        for (long int i=s.find("\n",tmp3); tmp3<=i; tmp3++){
          this->from.push_back(s.at(tmp3));

        }
        for (long int i=s.find("\n",tmp4); tmp4<=i; tmp4++){
            this->to.push_back(s.at(tmp4));

        }

        for (long int i=s.find("\n",tmp5); tmp5<i-1; tmp5++){
            boundaryValue.push_back(s.at(tmp5));

        }
        long int tmp6 = s.find(boundaryValue,tmp5);
        tmp6 += boundaryValue.length();

        for (long int i=s.find(boundaryValue,tmp6); tmp6<i-2; tmp6++){
            this->text.push_back(s.at(tmp6));
        }
         this->text.erase(0,text.find("\n",1));

         QString acc_id;
         acc_id.setNum(id); //acc_id получаем из сигнатуры функции sendInfo(QString ID)
         QString result = "INSERT INTO data(acc_id,themeMsg, fromWho, textMsg) VALUES (" + acc_id   + ", '" +  QString::fromStdString(subject) + "', '" +
                                                                                                QString::fromStdString(from) + "', '" +
                                                                                                QString::fromStdString(text) + "')";

        db.query.exec(result);
        qDebug()<<result;
        subject.clear();
        from.clear();
        to.clear();
        boundaryValue.clear();
        text.clear();
        db.query.clear();

        tmp2 = s.find("Subject: ",tmp5) ;
        tmp3 = s.find("From: ",tmp5) ;
        tmp4 = s.find("To: ",tmp5) ;
        tmp5 = s.find("boundary=",tmp4) + 10;
        if (tmp2==-1) break;

 }

}
