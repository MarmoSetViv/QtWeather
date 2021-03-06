/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QNetworkReply>
#include <httpcontrollerq.h>
#include <QLabel>
#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    HttpControllerQ pep;
    pep.restRequest();


    QDialog *dialog = new QDialog;
    dialog->setGeometry(dialog->x(), dialog->y(), 250, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    QHBoxLayout *layoutHedder = new QHBoxLayout;
    QHBoxLayout *CenterLayout = new QHBoxLayout;
    QVBoxLayout *layoutLeft = new QVBoxLayout;
    QVBoxLayout *layoutRight = new QVBoxLayout;
    QHBoxLayout *layoutBottem = new QHBoxLayout;

    mainLayout->addLayout(layoutHedder);
    layoutHedder->setAlignment(Qt::AlignTop);
    layoutHedder->setAlignment(Qt::AlignHCenter);

    mainLayout->addLayout(CenterLayout);
    CenterLayout->addLayout(layoutLeft);
    layoutLeft->setAlignment(Qt::AlignLeft);
    CenterLayout->addLayout(layoutRight);
    layoutRight->setAlignment(Qt::AlignRight);

    mainLayout->addLayout(layoutBottem);
    layoutBottem->setAlignment(Qt::AlignBottom);

    QLabel *label1 = new QLabel;
    label1->setText("<font color=red>?????????????? ?????????????? ??????????! ???????????? ???? ???????????? </font>");
    label1->setAlignment(Qt::AlignHCenter);
//    label1->setAutoFillBackground(true);

//??????????

//    QPixmap *cartun = new QPixmap(":resourse/icons/WeatherIcon - 1-32.png");
//    QSize sizeCart(35,35);
//    QLabel *labelCart = new QLabel;
//    QString ChangeIcon = "";
//    if(pep.getData() == "ovc"){
//        cartun->load(":resourse/icons/WeatherIcon - 1-32.png");
//    }
//    else if (pep.getwind_dir() == "n") {
////        ChangeWinDir = "????????????????.";
//    }
////    cartun->load("/icons/WeatherIcon - 1-32.png");
//    labelCart->setPixmap(cartun->scaled(sizeCart,Qt::KeepAspectRatio));
//    labelCart->setMargin(35);

    QLabel *labelTemp = new QLabel;
    QFont font = labelTemp->font();
    labelTemp->setText(QString::number(pep.gettemp())+"????");
    font.setPointSize(35);
    labelTemp->setFont(font);
    labelTemp->setAlignment(Qt::AlignRight);
    labelTemp->setMargin(2);
//    label2->setMargin(10);
//????????????
    QLabel *labelWind_speed = new QLabel;
    labelWind_speed->setText("<font color=green>???????????????? ??????????: </font>"+QString::number(pep.getwind_speed())+"??/??");
    labelWind_speed->setAlignment(Qt::AlignRight);
    labelWind_speed->setMargin(1);

    QLabel *labelWind_gust = new QLabel;
    labelWind_gust->setText("<font color=green>???????????????? ??????????????: </font>"+QVariant(pep.getwind_gust()).toString()+"??/??");
    labelWind_gust->setAlignment(Qt::AlignRight);
    labelWind_gust->setMargin(1);

    QString ChangeWinDir = "";
    if(pep.getwind_dir() == "nw"){
        ChangeWinDir = "????????????-????????????????.";
    }
    else if (pep.getwind_dir() == "n") {
        ChangeWinDir = "????????????????.";
    }
    else if (pep.getwind_dir() == "ne") {
        ChangeWinDir = "????????????-??????????????????.";
    }
    else if (pep.getwind_dir() == "e") {
        ChangeWinDir = "??????????????????.";
    }
    else if (pep.getwind_dir() == "se") {
        ChangeWinDir = "??????-??????????????????.";
    }
    else if (pep.getwind_dir() == "s") {
        ChangeWinDir = "??????????.";
    }
    else if (pep.getwind_dir() == "sw") {
        ChangeWinDir = "??????-????????????????.";
    }
    else if (pep.getwind_dir() == "w") {
        ChangeWinDir = "????????????????.";
    }
    else if (pep.getwind_dir() == "c") {
        ChangeWinDir = "??????????.";
    }

    QLabel *labelWind_dir = new QLabel;
    labelWind_dir->setText("<font color=green>??????????????????????: </font>"+ChangeWinDir);
    labelWind_dir->setAlignment(Qt::AlignRight);
    labelWind_dir->setMargin(1);

    QLabel *labelPressure_mm = new QLabel;
    labelPressure_mm->setText("<font color=green>????????????????: </font>"+QString::number(pep.getpressure_mm())+"mm");
    labelPressure_mm->setAlignment(Qt::AlignRight);
    labelPressure_mm->setMargin(1);

    QLabel *labelFeelsLick = new QLabel;
    labelFeelsLick->setText("<font color=green>????????????????????: </font>"+QString::number(pep.getfeels_like())+"????");
    labelFeelsLick->setAlignment(Qt::AlignRight);
    labelFeelsLick->setMargin(2);


    QString ChangePrec = "";
    if(pep.getprec_type() == 0){
        ChangePrec = "?????? ??????????????.";
    }
    else if (pep.getprec_type() == 1) {
        ChangePrec = "??????????.";
    }
    else if (pep.getprec_type() == 2) {
        ChangePrec = "?????????? ???? ????????????.";
    }
    else if (pep.getprec_type() == 3) {
        ChangePrec = "????????.";
    }
    else if (pep.getprec_type() == 4) {
        ChangePrec = "????????.";
    }

    QLabel *labelPrec_type = new QLabel;
//    labelPrec_type->setText("<font color=green>?????? ?????????????? </font>"+QString::number(pep.getprec_type()));
    labelPrec_type->setText("<font color=green>?????? ??????????????: </font>"+ChangePrec);
    labelPrec_type->setAlignment(Qt::AlignRight);
    labelPrec_type->setMargin(2);

    QString Changecond = "";
    if(pep.getcondition() == "clear"){
        Changecond = "????????.";
    }
    else if (pep.getcondition() == "partly-cloudy") {
        Changecond = "??????????????????????.";
    }
    else if (pep.getcondition() == "cloudy") {
        Changecond = "?????????????? ?? ????????????????????????.";
    }
    else if (pep.getcondition() == "overcast") {
        Changecond = "????????????????.";
    }
    else if (pep.getcondition() == "drizzle") {
        Changecond = "????????????.";
    }
    else if (pep.getcondition() == "light-rain") {
        Changecond = "?????????????????? ??????????.";
    }
    else if (pep.getcondition() == "rain") {
        Changecond = "??????????.";
    }
    else if (pep.getcondition() == "moderate-rain") {
        Changecond = "???????????????? ?????????????? ??????????.";
    }
    else if (pep.getcondition() == "heavy-rain") {
        Changecond = "?????????????? ??????????.";
    }
    else if (pep.getcondition() == "continuous-heavy-rain") {
        Changecond = "???????????????????? ?????????????? ??????????.";
    }
    else if (pep.getcondition() == "showers") {
        Changecond = "????????????.";
    }
    else if (pep.getcondition() == "wet-snow") {
        Changecond = "?????????? ???? ????????????.";
    }
    else if (pep.getcondition() == "light-snow") {
        Changecond = "?????????????????? ????????.";
    }
    else if (pep.getcondition() == "snow") {
        Changecond = "????????";
    }
    else if (pep.getcondition() == "snow-showers") {
        Changecond = "????????????????.";
    }
    else if (pep.getcondition() == "hail") {
        Changecond = "????????.";
    }
    else if (pep.getcondition() == "thunderstorm") {
        Changecond = "??????????.";
    }
    else if (pep.getcondition() == "thunderstorm-with-rain") {
        Changecond = "?????????? ?? ????????????.";
    }
    else if (pep.getcondition() == "thunderstorm-with-hail") {
        Changecond = "?????????? ?? ????????????.";
    }

    QLabel *labelcondition = new QLabel;
    labelcondition->setText("<font color=green>??????????????????????: </font>" + Changecond);
    labelcondition->setAlignment(Qt::AlignRight);
    labelcondition->setMargin(2);

    QLabel *label4 = new QLabel;
    label4->setText("???????????? 1.0");
    label4->setAlignment(Qt::AlignHCenter);

    layoutHedder->addWidget(label1);
//    layoutLeft->addWidget(labelCart);
    layoutLeft->addWidget(labelTemp);
    layoutRight->addWidget(labelFeelsLick);
    layoutRight->addWidget(labelPrec_type);
    layoutRight->addWidget(labelcondition);
    layoutRight->addWidget(labelWind_speed);
    layoutRight->addWidget(labelWind_gust);
    layoutRight->addWidget(labelWind_dir);
    layoutRight->addWidget(labelPressure_mm);
    layoutBottem->addWidget(label4);

    dialog->setWindowTitle("Weather Widget");
    dialog->show();

    return app.exec();
}
