#ifndef WEBCARD_H
#define WEBCARD_H

#include <QString>

class WebCard
{
private:
    int webcard[10][8];
public:
    WebCard();
    QString get(QString s) const;
};

#endif // WEBCARD_H
