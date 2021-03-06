#ifndef HTTPCONTROLLERQ_H
#define HTTPCONTROLLERQ_H
#include <weekclass.h>
#include <QNetworkAccessManager>

class HttpControllerQ
{
public:
    HttpControllerQ();
    QNetworkAccessManager *nam;
    WeekModel *weekModel;
    QString getcondition() const;
    QString getwind_dir() const;
    QString getdaytime() const;
    QString getcseason() const;
    QString getData() const;
    QVariant getwind_gust() const;
    int gettemp() const;
    int getfeels_like() const;
    int getwind_speed() const;
    int getprec_type() const;
    int getpressure_mm() const;

public slots:
    void restRequest();
    void PictureRequest(QUrl url);
private:
    int temp;
    int feels_like;
    QString condition;
    QString icon;
    int wind_speed;
    QVariant wind_gust;
    QString wind_dir;
    QString daytime;
    QString season;
    QString cartun;// картинка
    QString DataCArt;
    int prec_type;
    int pressure_mm;
};

#endif // HTTPCONTROLLERQ_H
