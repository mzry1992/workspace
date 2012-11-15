#include "webcard.h"
#include <QString>
#include <string>
#include <cstdio>

WebCard::WebCard()
{
    webcard[0][0] = 57;
    webcard[0][1] = 87;
    webcard[0][2] = 98;
    webcard[0][3] = 04;
    webcard[0][4] = 02;
    webcard[0][5] = 65;
    webcard[0][6] = 81;
    webcard[0][7] = 14;
    webcard[1][0] = 35;
    webcard[1][1] = 42;
    webcard[1][2] = 27;
    webcard[1][3] = 26;
    webcard[1][4] = 94;
    webcard[1][5] = 51;
    webcard[1][6] = 17;
    webcard[1][7] = 71;
    webcard[2][0] = 56;
    webcard[2][1] = 51;
    webcard[2][2] = 48;
    webcard[2][3] = 82;
    webcard[2][4] = 65;
    webcard[2][5] = 56;
    webcard[2][6] = 80;
    webcard[2][7] = 80;
    webcard[3][0] = 34;
    webcard[3][1] = 04;
    webcard[3][2] = 60;
    webcard[3][3] = 73;
    webcard[3][4] = 78;
    webcard[3][5] = 44;
    webcard[3][6] = 45;
    webcard[3][7] = 10;
    webcard[4][0] = 43;
    webcard[4][1] = 05;
    webcard[4][2] = 20;
    webcard[4][3] = 47;
    webcard[4][4] = 68;
    webcard[4][5] = 46;
    webcard[4][6] = 42;
    webcard[4][7] = 86;
    webcard[5][0] = 87;
    webcard[5][1] = 72;
    webcard[5][2] = 63;
    webcard[5][3] = 64;
    webcard[5][4] = 71;
    webcard[5][5] = 27;
    webcard[5][6] = 59;
    webcard[5][7] = 21;
    webcard[6][0] = 64;
    webcard[6][1] = 07;
    webcard[6][2] = 95;
    webcard[6][3] = 92;
    webcard[6][4] = 93;
    webcard[6][5] = 68;
    webcard[6][6] = 35;
    webcard[6][7] = 78;
    webcard[7][0] = 23;
    webcard[7][1] = 93;
    webcard[7][2] = 31;
    webcard[7][3] = 53;
    webcard[7][4] = 31;
    webcard[7][5] = 26;
    webcard[7][6] = 44;
    webcard[7][7] = 42;
    webcard[8][0] = 94;
    webcard[8][1] = 71;
    webcard[8][2] = 48;
    webcard[8][3] = 60;
    webcard[8][4] = 81;
    webcard[8][5] = 75;
    webcard[8][6] = 94;
    webcard[8][7] = 07;
    webcard[9][0] = 94;
    webcard[9][1] = 10;
    webcard[9][2] = 33;
    webcard[9][3] = 44;
    webcard[9][4] = 73;
    webcard[9][5] = 58;
    webcard[9][6] = 19;
    webcard[9][7] = 86;
}

QString WebCard::get(QString s) const
{
    std::string buf = (const char*)s.toLocal8Bit();
    if (buf.length() < 2)
    {
        QString ret;
        ret = "NA";
        return ret;
    }
    int id = webcard[buf[0] - 'A'][buf[1] - '1'];
    char res[10];
    sprintf(res, "%02d", id);
    QString ret = res;
    return ret;
}